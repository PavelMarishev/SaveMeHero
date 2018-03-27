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
	Dialog* dial;
	Hero* hero;
	RenderWindow *App;
	Clock clock;
public:
	Brain() {}
	Brain(Hero* h, RenderWindow* A, bool TSD = false)
	{
		dial = new Dialog(25);
		hero = h;
		App = A;
		toShowDial = TSD;
	}
	void RandThink()
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
			dial->showSmallWindow("...", hero->getHeroPos(), *App, 1);
		}
	}
	void SleepZZZ() 
	{
		interval = clock.getElapsedTime().asSeconds();
		switch (interval%4) 
		{
		case 0: dial->showSmallWindow("z", hero->getHeroPos(), *App, 0); break;
		case 1: dial->showSmallWindow("zz", hero->getHeroPos(), *App, 0); break;
		case 2: dial->showSmallWindow("zzZ", hero->getHeroPos(), *App, 0); break;
		case 3: dial->showSmallWindow("", hero->getHeroPos(), *App, 0); break;
		}
	}
	sf::FloatRect getSDR()
	{
		return dial->getSmallDialRect();
	}
	bool dialIsShowing()
	{
		return toShowDial;
	}
	string getCurrentAct() 
	{
		return dial->getCurrentContext();
	}
};






class PathFinding
{
	int hw, hh;
	sf::Vector2u objSize;
	const int WALL = -1;
	const int BLANK = -2;
	int w;
	int h;
	int **grid;
	int length;
	vector<sf::FloatRect> ObjRects;
public:
	PathFinding(tmx::Map &map, Objects &allobj)
	{
		hw = 30;
		hh = 60;
		w = map.getBounds().width / hw;
		h = map.getBounds().height / hh;
		grid = new int*[h];
		ObjRects = allobj.getRects();
	}
	vector<sf::Vector2f> findPath(int Ax, int Ay, int Bx, int By)
	{
		vector<sf::Vector2f> path;
		
		int ax = Ax / hw, ay = Ay / hh, bx = Bx / hw, by = By / hh;
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
				}
				else
				{
					grid[i][j] = BLANK;
				}
			}
		}

		if (grid[by][bx] == WALL)
		{
			path.push_back(sf::Vector2f(Ax, Ay));
			return path;
		}

		int dx[4] = { 1, 0, -1, 0 };
		int dy[4] = { 0, 1, 0, -1 };
		int d, x, y, k;
		bool stop;

		d = 0;
		grid[ay][ax] = 0;
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
		/*
		if (grid[by][bx] == BLANK)
		{
			path.push_back(sf::Vector2f(Ax, Ay));
			return path;
		}
		*/
		length = grid[by][bx];
		x = bx;
		y = by;
		path.push_back(sf::Vector2f(Bx, By));
		d = length;
		while (d > 1)
		{
			path.push_back(sf::Vector2f(x*hw, y*hh));
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
