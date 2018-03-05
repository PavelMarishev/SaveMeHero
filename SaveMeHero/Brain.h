#pragma once
#include <iostream>
#include <string>
#include "dial.h"
#include "cScreen.h"
#include "hero.h"
class Brain 
{
	long interval;
	bool toShowDial;
	Dialog *dial;
	Clock clock;
public:
	Brain(bool TSD = false) 
	{
		dial = new Dialog(15);
		toShowDial = TSD;
	}
	void update(Hero h, RenderWindow &App)
	{
		interval = clock.getElapsedTime().asSeconds();
		if (interval >= 9)
		{
			if (toShowDial)
			{
				clock.restart();
				dial->thinkOfAnother();
			}
			toShowDial = false;
		}
		else if (interval >= 5) {
			toShowDial = true;
		}
		if (toShowDial)
		{
			dial->showSmallWindow("...", h.getHeroPos(), App, 1);
		}
	}
	vector<sf::Vector2f> findPath(int Ax, int Ay, int Bx, int By, tmx::Map &map, Objects &allobj)
	{
		int hw = 30, hh = 60;
		sf::Vector2u objSize;
		const int WALL = -1;
		const int BLANK = -2;
		int w = map.getBounds().width/hw;
		int h = map.getBounds().height/hh;
		vector<sf::Vector2f> path;
		path.push_back(sf::Vector2f(Bx, By));
		int **grid = new int*[h];
		int length;
		int currentObj = 0;
		int ax = Ax / hw , ay = Ay / hh, bx = Bx / hw, by = By / hh;
		vector<sf::FloatRect> ObjRects = allobj.getRects();
		for (int i = 0; i< h; i++) 
		{
			grid[i] = new int[w];
			for (int j = 0; j < w; j++) 
			{
				bool intersection = false;
				for (int k = 0; k < ObjRects.size(); k++)
				{
					if (sf::FloatRect(sf::Vector2f(j * hw, i * hh), sf::Vector2f(hw, hh)).intersects(ObjRects[k])) 
					{
						intersection = true;
					}
				}

				if (intersection)
				{
					grid[i][j] = WALL;
					cout << grid[i][j];
				}
				else 
				{
					grid[i][j] = BLANK;
				}
			}
		}
		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		int d, x, y, k;
		bool stop;
		
		d = 0;
		grid[ay][ax] = 0;            // стартова€ €чейка помечена 0
		do {
			stop = true;
			for (y = 0; y < h; y++)
				for (x = 0; x < w; x++)
					if (grid[y][x] == d)
					{
						for (k = 0; k < 4; k++)
						{
							int iy = y + dy[k], ix = x + dx[k];
							if (iy >= 0 && iy < h && ix >= 0 && ix < w &&
								grid[iy][ix] == BLANK)
							{
								stop = false;
								grid[iy][ix] = d + 1;
							}
						}
					}
			d++;
		} while (!stop && grid[by][bx] == BLANK);

		if (grid[by][bx] == BLANK) return path;

		length = grid[by][bx];
		x = bx;
		y = by;

		d = length;
		while (d > 0)
		{
			path.push_back(sf::Vector2f(x*hw,y*hh));
			d--;
			for (k = 0; k < 4; ++k)
			{
				int iy = y + dy[k], ix = x + dx[k];
				if (iy >= 0 && iy < h && ix >= 0 && ix < w && grid[iy][ix] == d)
				{
					x = x + dx[k];
					y = y + dy[k];
					break;
				}
			}
		}

		return path;
	}
};