#pragma once

#include <iostream>
#include "cScreen.h"
#include "charInterface.h"
#include "charInventory.h"
using namespace sf;

class InterfaceScreen :public cScreen
{
private:
	Sprite * cursor;
	Texture backTexture;
	Sprite backSprite;
	bool stats = true;
	bool inv = false;
	Hero *hero;
public:
	InterfaceScreen(Sprite * cur,Hero *h) {
		cursor = cur;
		hero = h;
		backTexture.loadFromFile("assets/images/back.png");
		backSprite.setTexture(backTexture);
		backSprite.setPosition(0, 0);
	}
	

	
	int InterfaceScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
		sf::View view;
		view.reset(sf::FloatRect(0, 0, 1280, 623));
	///TODO make class inteface
		
		Clock clock;
		CharInterface ci(hero);
		CharInvetory charInv(hero);
		
		while (Running)
		{
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			time = time / 800;

			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					return (-1);
				}
			}
		
			if (stats) {
				if ((Event.type == sf::Event::MouseButtonPressed) && (Event.mouseButton.button == sf::Mouse::Left)) {
					if (ci.whereClicked(sf::Vector2f(Mouse::getPosition(App))) == "backpack") {
						stats = false;
						inv = true;
					}
					if (ci.whereClicked(sf::Vector2f(Mouse::getPosition(App))) == "game") {
						return(0);
					}

				}
			}
			if (inv) {
				if ((Event.type == sf::Event::MouseButtonPressed) && (Event.mouseButton.button == sf::Mouse::Left)) {
					if (charInv.whereClicked(sf::Vector2f(Mouse::getPosition(App))) == "closeback") {
						stats = true;
						inv = false;
					}
				}
			}
			App.setView(view);
			App.clear();
			App.draw(backSprite);
			
			if (stats) { 
				ci.updateStats();
				App.draw(ci); 
			}
			if (inv) {
				charInv.updateStats();
				App.draw(charInv);
			}

			cursor->setPosition(getMouseGlobalPos(App));
			App.draw(*cursor);
			App.display();
		}

		return EXIT_SUCCESS;

	}
	sf::Vector2f getMouseGlobalPos(sf::RenderWindow &window) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		return worldPos;
	}
};