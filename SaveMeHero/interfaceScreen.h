#pragma once

#include <iostream>
#include "cScreen.h"
#include "charInterface.h"
using namespace sf;

class InterfaceScreen :public cScreen
{
private:
	Sprite * cursor;

public:
	InterfaceScreen(Sprite * cur) {
		cursor = cur;
	}
	int InterfaceScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
		sf::View view;
		view.reset(sf::FloatRect(0, 0, 1280, 623));
	///TODO make class inteface
		
		Clock clock;
		CharInterface ci;
		
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
		
			if ((Event.type == sf::Event::MouseButtonPressed)&& (Event.mouseButton.button == sf::Mouse::Left) ) {
			//	cout << ci.whereClicked(sf::Vector2f(Mouse::getPosition(App))) << endl;
				if (ci.whereClicked(sf::Vector2f(Mouse::getPosition(App)))=="game") {
					return(0);
			}
				
			}
			App.setView(view);
			App.clear();
			App.draw(ci);
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