#include <iostream>
#pragma once
#include "cScreen.h"
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"

using namespace sf;

class MapScreen : public cScreen {
private :
	Event Event;
	bool Running = true;
	tmx::Map map;
	Hero h;
	bool moving = false;
	sf::Vector2i moveto;
	MapLayer layerZero;
	MapLayer layerOne;
	Clock clock;
	Objects allobj;
public:
	MapScreen(){
		map.load("assets/mymap.tmx");
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
	string checkCollision(Objects colobjs,sf::FloatRect charRect) {
		vector<sf::FloatRect> rects = colobjs.getRects();
		string objName = "nothing";
		for (int i = 0; i < rects.size(); i++) {
			if (charRect.intersects(rects[i])) {
				objName = colobjs.getObject(i).getName();
			}
			
		}
		return objName;
	}
	int MapScreen::Run(sf::RenderWindow &App) {
		Running = true;
		
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
				if (whereClicked(sf::Vector2f(Mouse::getPosition(App)),allobj) == "menu") {
					Running = false;
					return (1);
				}
				else {
					moveto = Mouse::getPosition(App);
					moving = true;
				}
			}

			if (moving) {
			//	cout << "Player rect is" << h.getRect().left << "  " << h.getRect().top << "  " << h.getRect().width << "  " << h.getRect().height << endl;
				moving = h.moveHeroTo(moveto, time); 
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