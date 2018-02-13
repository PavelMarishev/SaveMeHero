#pragma once

#include <iostream>
#include <string>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"
#include "dial.h"
#include "player.h"

using namespace std;
using namespace sf;

float offsetX = 0, offsetY = 0;

const int H = 12;
const int W = 40;

/*String TileMap[H] = {

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

};*/

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


class SS2 : public cScreen {

public:
	int SS2::Run(sf::RenderWindow &App) 
	{
		Event Event;
		bool Running = true;

		tmx::Map map;
		map.load("assets/mymap.tmx");
		MapLayer layerZero(map, 0);
		MapLayer layerOne(map, 1);

		Texture t;
		t.loadFromFile("herosprite.png");
		t.setSmooth(true);
		float frame = 0;

		PLAYER p(t);
		Dialog d(15);
		Clock clock;
		float time;
		RectangleShape rectangle(Vector2f(32, 32));

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
			time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time /= 800;
			if (time>20) time = 20;


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
			/*
			for (int i = 0; i<H; i++)
				for (int j = 0; j<W; j++)
				{
					if (TileMap[i][j] == '0') rectangle.setFillColor(Color::Black);


					if (TileMap[i][j] == ' ') rectangle.setFillColor(Color::Green);

					rectangle.setPosition(j * 32 - offsetX, i * 32 - offsetY);
					App.draw(rectangle);
				}
			*/
			if (p.rect.left>300) offsetX = p.rect.left - 300;
			offsetY = p.rect.top - 200;
			App.draw(p.sprite);
			//d.Small(".....", p.sprite.getPosition(), App);
			//d.Big(".....", App);
			
			for (int i = 0; i < gui.size(); i++) {
				App.draw(gui[i].sprite); 
			}
			p.update(time);

			
			App.display();
		}
	return (-1);
	}
};