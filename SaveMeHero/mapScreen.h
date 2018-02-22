#include <iostream>
#pragma once
#include "cScreen.h"
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"

using namespace sf;

class MapScreen : public cScreen,public Hero {
private :
	float  spPosX, spPosY;
	Event Event;
	bool Running = true;
	tmx::Map map;
	Hero h;
	sf::Vector2i moveto;
	MapLayer layerZero;
	MapLayer layerOne;
	Clock clock;
	Objects allobj;
public:
	MapScreen(){
		map.load("assets/mymap2.tmx");
		layerZero.setMap(map, 0);
		layerOne.setMap(map, 1);
		allobj.setObjects(map, 2);
	}
	string whereClicked(sf::Vector2f point, Objects clickable) {
		string clickedon = "nothing";
		vector<sf::FloatRect> rects = clickable.getRects();
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i].contains(point)) {
				clickedon = clickable.getObject(i).getName();
			}
		}
		return clickedon;
	}
	bool checkCollision(Objects colobjs,sf::FloatRect charRect) {
		vector<sf::FloatRect> rects = colobjs.getRects();
		for (int i = 0; i < rects.size(); i++) {
			if (charRect.intersects(rects[i])) {
				cout << "Collision with object: " << colobjs.getObject(i).getName() << endl;
			/*sf::Vector2f SpritePxPos = sprite.getPosition();
			
				spPosX = SpritePxPos.x;
				spPosY = SpritePxPos.y;
				sprite.setPosition(spPosX, spPosY);*/
				sprite.move(10, 10);

				return true;
			}
			
		}
	}
	int MapScreen::Run(sf::RenderWindow &App) {
		Running = true;
		bool moving = false;

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

			if (Event.type == sf::Event::MouseButtonPressed) {
				
			
				if ((Event.mouseButton.button == sf::Mouse::Left)) {
				if (whereClicked(sf::Vector2f(Mouse::getPosition(App)), allobj) == "menu") {
					Running = false;
					moving = false;
					return (1);
				}
				else{
				
					moveto = Mouse::getPosition(App);
					moving = true;
				}
				}
			}

			if (moving) {
				moving = h.moveHeroTo(moveto, time); 
			}
			bool Col = checkCollision(allobj, h.getRect());
			if (Col == true)
			{
				moving = false;
			

			}

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