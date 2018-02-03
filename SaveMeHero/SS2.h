#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

float offsetX = 0, offsetY = 0;

const int H = 12;
const int W = 40;//width

String TileMap[H] = {

	"0000000000000000000000000000000000000000",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0                                      0",
	"0000000000000000000000000000000000000000",

};

class Button
{
public:
	Vector2f bPosition; 
	IntRect bSprite; 
	Sprite sprite;
	
	bool hasOnClick = false; 
	bool hasOnRelease = false;
	void onClick() 
	{
		cout << "Key pushed" << endl;
	}
	void onRelease()
	{
		cout << "Key released" << endl;
	}
	Button(Texture &texture, Vector2f bPosition, IntRect bSprite) 
	{ 
		sprite.setTexture(texture);
		this->bPosition = bPosition;
		this->bSprite = bSprite;
		sprite.setTextureRect(bSprite); 
		sprite.setPosition(bPosition); 
	}
};

std::vector<Button> gui;
Texture guiTexture; 

void RefreshKeys() {
	guiTexture.loadFromFile("gui.jpg");

	Button temp(guiTexture, Vector2f(480, 340), IntRect(0, 0, 100, 30));
	temp.hasOnClick = true;
	temp.hasOnRelease = true;
	gui.push_back(temp); 
}

class Dialog {
	Font font;
	Text text;
	string cutSpace(string s) {
		int i = 0;
		while (i < s.length())
		{
			if (s[i] == ' ')
			{
				int j;
				j = (i > 0 ? (i < (s.length() - 1) ? 1 : 0) : 0);
				while (s[i + j] == ' ')
				{
					s.erase(i + j, 1);
				}
			}
			i++;
		}
		return s;
	}
	string setw(string s, int w)
	{
		s = cutSpace(s);
		if (s.length() < 2 || s.length() > w)  return s;
		else
		{
			int i = 1;
			while (s.length() < w)
			{
				for (int j = i; j < s.length(); j++)
				{
					if (s[j] == ' ')
					{
						s.insert(j, " ");
						i = j;
						break;
					}
				}
			}
			return s;
		}
	}
	string format(string s, int Len = 1, int Size = 1)
	{
		string buf = s;
		buf = cutSpace(buf);
		int len = Len, size = Size, i = 0, temp = 0;
		while (i < (buf.length()))
		{
			bool found = false;
			if (temp >= len)
			{

				for (int j = 0; j < temp - 3; j++)
				{
					if (buf[i - j] == ' ')
					{
						buf[i - j] = '\n';
						temp = j;
						found = true;
						break;
					}
				}
				if (!found)
				{
					buf.insert(i, "\n");
					temp = -1;
				}
			}
			temp++;
			i++;
			if (i > size)
			{
				buf.resize(size);
				buf += "...";
			}
		}
		return buf;
	}
public:
	Dialog(int size, Color color = Color::Black, char* default = "")
	{
		font.loadFromFile("CyrilicOld.ttf");
		text.setString(default);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
	}
	void Small(string speach, Vector2f obj, RenderWindow &window, int limitH = 5,int limitW = 10)
	{
		Texture dialTx;
		dialTx.loadFromFile("dialog.png");
		Sprite s(dialTx);

		s.setPosition(Vector2f(obj.x + 15, obj.y - 15));
		RectangleShape rect(Vector2f(limitW*(text.getCharacterSize() / 1.5), text.getCharacterSize()*limitH + 3));
		rect.setPosition(Vector2f(obj.x + 25, obj.y - text.getCharacterSize()*limitH));
		rect.setFillColor(Color(255,255,255,169));
		text.setString(format(speach, limitW, limitW*limitH));
		text.setPosition(Vector2f(obj.x + 30, obj.y - text.getCharacterSize()*limitH));
		
		//window.draw(s);
		window.draw(rect);
		window.draw(text);
	}
	void Big(string speach, RenderWindow &window,int k = 5)
	{
		RectangleShape rect(Vector2f(window.getSize().x, window.getSize().y/k));
		text.setString(speach);

		text.setPosition(Vector2f(0, 300));
		rect.setPosition(Vector2f(0, 300));
		rect.setFillColor(Color(255,255,255,169));
		window.draw(rect);
		window.draw(text);
	}
};

class PLAYER {

public:

	float dx, dy;
	FloatRect rect;
	Sprite sprite;
	float currentFrame;
	enum dirs{L, R, U, D} dir = D;


	PLAYER(Texture &image)
	{
		sprite.setTexture(image);
		rect = FloatRect(7 * 32, 9 * 32, 30, 60);

		dx = dy = 0.1;
		currentFrame = 0;
	}


	void update(float time)
	{
		rect.left += (dx) * time;
		Collision(0);
		rect.top += (dy)* time;
		Collision(1);
		
		currentFrame += 0.005*time;
		if (currentFrame > 8) currentFrame -= 8;

		if (dx > 0) { dir = L; sprite.setTextureRect(IntRect(30 * int(currentFrame), 130, 30, 60)); }
		if (dx < 0) { dir = R; sprite.setTextureRect(IntRect(30 * int(currentFrame), 194, 30, 60)); }
		if (dy < 0) { dir = U; sprite.setTextureRect(IntRect(30 * int(currentFrame), 0, 30, 60)); }
		if (dy > 0) { dir = D; sprite.setTextureRect(IntRect(30 * int(currentFrame), 65, 30, 60)); }
		if (dy == 0 && dx == 0) {
			switch (dir)
			{
			case L:
				sprite.setTextureRect(IntRect(0, 130, 30, 60));
				break;
			case R:
				sprite.setTextureRect(IntRect(0, 194, 30, 60));
				break;
			case U:
				sprite.setTextureRect(IntRect(120, 0, 30, 60));
				break;
			case D:
				sprite.setTextureRect(IntRect(120, 65, 30, 60));
				break;
			}
		}
		
		sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

		dx = 0;
	}

	void Collision(int d)
	{
		for (int i = rect.top / 32; i<(rect.top + rect.height) / 32; i++)
			for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
			{
				if (TileMap[i][j] == '0')
				{
					if ((dx>0) && (d == 0)) rect.left = j * 32 - rect.width;
					if ((dx<0) && (d == 0)) rect.left = j * 32 + 32;
					if ((dy>0) && (d == 1)) { rect.top = i * 32 - rect.height;  }
					if ((dy<0) && (d == 1)) { rect.top = i * 32 + 32;  }
				}

				if (TileMap[i][j] == 'G')
				{
					TileMap[i][j] = ' ';
				}
			}
	}
};

class SS2 : public cScreen {

public:
	int SS2::Run(sf::RenderWindow &App) 
	{
		Event Event;
		bool Running = true;
		Texture t;
		t.loadFromFile("herosprite.png");
		t.setSmooth(true);
		float currentFrame = 0;

		PLAYER p(t);
		Dialog d(15);
		Clock clock;

		RectangleShape rectangle(Vector2f(32, 32));


		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();

		time /= 1;//speed

		if (time>20) time = 20;
		RefreshKeys();
		while (Running)
		{
			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					return (-1);
				}
				
			}

			if (Event.type == Event::MouseButtonPressed) {
				if (Event.mouseButton.button == Mouse::Left) {
					for (int i = 0; i < gui.size(); i++) {
						if (gui.at(i).hasOnClick) {
							if (Mouse::getPosition(App).x > gui.at(i).bPosition.x &&
								Mouse::getPosition(App).x < gui.at(i).bPosition.x + gui.at(i).bSprite.width &&
								Mouse::getPosition(App).y > gui.at(i).bPosition.y &&
								Mouse::getPosition(App).y < gui.at(i).bPosition.y + gui.at(i).bSprite.height) {
								gui.at(i).onClick();
							}
						}
					}
				}
			}
			else if (Event.type == Event::MouseButtonReleased) {
				if (Event.mouseButton.button == Mouse::Left) {
					for (int i = 0; i < gui.size(); i++) {
						if (gui.at(i).hasOnRelease) {
							if (Mouse::getPosition(App).x > gui[i].bPosition.x &&
								Mouse::getPosition(App).x < gui[i].bPosition.x + gui.at(i).bSprite.width &&
								Mouse::getPosition(App).y > gui[i].bPosition.y &&
								Mouse::getPosition(App).y < gui[i].bPosition.y + gui.at(i).bSprite.height) {
								gui.at(i).onRelease();
							}
						}
					}
				}
			}

			if (Keyboard::isKeyPressed)
			{
				p.dx = 0;
				p.dy = 0;
			}
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				p.dx = -0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				p.dx = 0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				p.dy = -0.1;
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				p.dy = 0.1;
			}

			App.clear(Color::White);

			for (int i = 0; i<H; i++)
				for (int j = 0; j<W; j++)
				{
					if (TileMap[i][j] == '0') rectangle.setFillColor(Color::Black);


					if (TileMap[i][j] == ' ') rectangle.setFillColor(Color::Green);

					rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
					App.draw(rectangle);
				}
			
			if (p.rect.left>300) offsetX = p.rect.left - 300;
			offsetY = p.rect.top - 200;
			App.draw(p.sprite);
			d.Small(".....", p.sprite.getPosition(), App);
			d.Big(".....", App);
			
			for (int i = 0; i < gui.size(); i++) {
				App.draw(gui[i].sprite); 
			}
			p.update(time);

			
			App.display();
		}
	return (-1);
	}
};