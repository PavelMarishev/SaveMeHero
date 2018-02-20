#include <iostream>
#pragma once
#include "cScreen.h"
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"

using namespace sf;

class MapScreen : public cScreen {

public:
	void checkCollision(Objects colobjs,sf::FloatRect charRect) {
		vector<sf::FloatRect> rects = colobjs.getRects();
		for (int i = 0; i < rects.size(); i++) {
			if(charRect.intersects(rects[i]))cout<<"Collision";
			
		}
	
	}
	int MapScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
		tmx::Map map;
		map.load("assets/mymap.tmx");
		MapLayer layerZero(map, 0);
		MapLayer layerOne(map, 1);
		Hero h;
		Clock clock;
		bool moving = false;
		sf::Vector2i moveto;
		Objects allobj(map,2);
		
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
			App.draw(layerZero);
			App.draw(layerOne);
			if (Mouse::isButtonPressed(Mouse::Button::Left)) {
				moveto = Mouse::getPosition(App);
				moving = true;
			}
			if (moving) {
			//	cout << "Player rect is" << h.getRect().left << "  " << h.getRect().top << "  " << h.getRect().width << "  " << h.getRect().height << endl;
				moving = h.moveHeroTo(moveto, time); 
			}
			checkCollision(allobj,h.getRect());

			App.draw(h);
			
			App.display();
		}

		return 0;



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