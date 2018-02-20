#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"
#include "Log.h"

using namespace sf;

class testScreen : public cScreen {

public:
	int testScreen::Run(sf::RenderWindow &App) {
		Event event;
		bool Running = true;
		tmx::Map map;
		map.load("assets/mymap.tmx");
		MapLayer layerZero(map, 0);
		MapLayer layerOne(map, 1);
		Hero h;
		Clock clock;
		bool moving = false;
		Vector2i moveto;

		bool isPressed = false;
		Log l;

		
		while (Running)
		{
			float time = clock.getElapsedTime().asMilliseconds();
			clock.restart();
			time = time / 800;

			Vector2i pos = Mouse::getPosition(App);
			if (isPressed) l.add(pos.x, pos.y);
	
			while (App.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					return (-1);
				}

				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left)
					{
						isPressed = true;
					}
				if (event.type == Event::MouseButtonReleased)
					if (event.key.code == Mouse::Left) {
						isPressed = false;
						cout << l.get() << endl;
						l.clear();
					}
			}
			App.clear();
			App.draw(layerZero);
			App.draw(layerOne);
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				moveto = Mouse::getPosition(App);
				moving = true;
				
				
			}
			if (moving) {
				
				moving = h.moveHeroTo(moveto, time); 
			}
			
			App.draw(h);
			
			App.display();
		}

		return EXIT_SUCCESS;



		/*
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
		}*/

		return (-1);
	}

};