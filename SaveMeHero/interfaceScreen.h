#pragma once

#include <iostream>
#include "cScreen.h"
#include "charInterface.h"
using namespace sf;

class InterfaceScreen :public cScreen
{

public:
	int InterfaceScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
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
			App.clear();
			App.draw(ci);
			App.display();
		}

		return EXIT_SUCCESS;

	}

};