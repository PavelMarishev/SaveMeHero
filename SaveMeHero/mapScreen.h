#include <iostream>
#pragma once
#include "cScreen.h"
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"
#include "dial.h" 
#include "Log.h"

using namespace sf;

class MapScreen : public cScreen,public Hero {
private :
	float  spPosX, spPosY;
	bool Running = true;
	tmx::Map map;
	Hero h;
	sf::Vector2f moveto;
	MapLayer layerZero;
	MapLayer layerOne;
	Dialog *dial = new Dialog(15);
	bool toShowDial = false;
	Clock clock, clock2;
	Objects allobj;
	int CamSpeed = 600;
	Log l;
	bool isPressed = false;
	bool camIsMoving = false;
	Sprite * cursor;

	Texture arrowsText;
	Sprite ArrowCursor;
public:
	MapScreen(Sprite * cur){
		map.load("assets/bigmap.tmx");
		layerZero.setMap(map, 0);
		layerOne.setMap(map, 1);
		allobj.setObjects(map, 2);
		cursor = cur;

		arrowsText.loadFromFile("assets/images/cursors.png");
		ArrowCursor.setTexture(arrowsText);
		ArrowCursor.setTextureRect(sf::IntRect(177,79,10,10));
		ArrowCursor.setScale(2, 2);

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
				sprite.move(10, 10);

				return true;
			}
			
		}
	}
	int MapScreen::Run(sf::RenderWindow &App) {
		App.setMouseCursorVisible(false);
		Running = true;
		bool moving = false;
		Event Event;
		sf::View view;
		int camDir = 0;
		view.reset(sf::FloatRect(0,0,1280,623));
		view.setCenter(h.getHeroPos());
		while (Running)
		{
			float time = clock.getElapsedTime().asMilliseconds();
			long interval = clock2.getElapsedTime().asSeconds();
			clock.restart();
			time = time / 800;

		
		

			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					return (-1);
				}
			}

			if (Event.type == Event::MouseButtonPressed)
				if (Event.key.code == Mouse::Left) {
					isPressed = true;
				}
			if (Event.type == Event::MouseButtonReleased)
				if (Event.key.code == Mouse::Left) {
					if (isPressed) cout << l.get() << endl;
					isPressed = false;
					l.clear();
				}
			sf::Vector2i pos = Mouse::getPosition(App);
			
			if (!(pos.x < 20) && !(pos.x > 1260) && !(pos.y < 20) && !(pos.y > 600)) { 
			camIsMoving = false; 
			camDir = 0;
			}

			if (pos.x < 20) {
			view.move(-CamSpeed * time, 0); 
			camIsMoving = true;
			camDir = 1;
			}
			if (pos.x > 1260){ 
			view.move(CamSpeed * time, 0);
			camIsMoving = true;
			camDir = 3;
			}
			if (pos.y < 20) { 
			view.move(0, -CamSpeed * time); 
			camIsMoving = true;
			camDir = 2;
			}
			if (pos.y > 600) { 
			view.move(0, CamSpeed * time); 
			camIsMoving = true;
			camDir = 4;
			}
			if ((pos.x < 20) && (pos.y > 600)) camDir = 5;
			if ((pos.x < 20) && (pos.y < 20))camDir = 6;
			if ((pos.x > 1260) && (pos.y < 20))camDir = 7;
			if ((pos.x > 1260) && (pos.y > 600))camDir = 8;

			if (isPressed) l.add(pos.x, pos.y);
			App.clear();
			App.draw(layerZero);
			App.draw(layerOne);
		


			if (moving && !isPressed) {
				moving = h.moveHeroTo(moveto, time);
				view.setCenter(h.getHeroPos());
			}
			bool Col = checkCollision(allobj, h.getRect());
			if (interval >= 9)
			{
				if (toShowDial)
				{
					clock2.restart();
					dial->thinkOfAnother();
				}
				toShowDial = false;
			}
			else if (interval >= 5) {
				toShowDial = true;
			}
			if (toShowDial)
			{
				dial->showSmallWindow("...", h.getHeroPos(), App, 1);
			}

			App.draw(h);
			if (!camIsMoving) {
				cursor->setPosition(getMouseGlobalPos(App));
				App.draw(*cursor);
			}
			else {
				switch (camDir){
				case 1:
					ArrowCursor.setRotation(-45);
					break;
				case 2:
					ArrowCursor.setRotation(45);
					break;
				case 3:
					ArrowCursor.setRotation(135);
					break;
				case 4:
					ArrowCursor.setRotation(225);
					break;
				case 5:
					ArrowCursor.setRotation(-90);
					break;
				case 6:
					ArrowCursor.setRotation(0);
					break;
				case 7:
					ArrowCursor.setRotation(90);
					break;
				case 8:
					ArrowCursor.setRotation(180);
					break;
				}
			ArrowCursor.setPosition(getMouseGlobalPos(App));
			App.draw(ArrowCursor);
			}
			App.setView(view);
			App.display();
			if (Event.type == sf::Event::MouseButtonPressed) {
				

				if ((Event.mouseButton.button == sf::Mouse::Left)) {
					if(h.getRect().contains(getMouseGlobalPos(App))){
						Running = false;
						moving = false;
						return (1);
					}
					else {

						moveto = getMouseGlobalPos(App);
						moving = true;
					}
				}
				if ((Event.mouseButton.button == sf::Mouse::Right)) {
					sf::Vector2f mosPosi = getMouseGlobalPos(App);
					cout << "GLOBAL: x=" << mosPosi.x << "y=" << mosPosi.y << endl;
					cout << "LOCAL: x=" << sf::Mouse::getPosition(App).x << "y="<< sf::Mouse::getPosition(App).y<<endl;
				}
			}
		}

		return 0;
		return (-1);
	}
	sf::Vector2f getMouseGlobalPos(sf::RenderWindow &window) {
		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);
		return worldPos;
	}
};