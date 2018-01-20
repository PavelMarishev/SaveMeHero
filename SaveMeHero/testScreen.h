#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class testScreen : public cScreen {

public:
	int testScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
		CircleShape shape(100.f);
		shape.setFillColor(sf::Color::Green);
		while (Running)
		{
			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					return (-1);
				}
			}
			App.clear();
			App.draw(shape);
			App.display();
		}
		return (-1);
	}

};