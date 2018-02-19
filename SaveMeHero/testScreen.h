#include <iostream>
#include "cScreen.h"
#include <SFML/Graphics.hpp>
#include <tmxlite/Map.hpp>
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"
#include "dial.h"
using namespace sf;

class testScreen : public cScreen {

public:
	int testScreen::Run(sf::RenderWindow &App) {
		Event Event;
		bool Running = true;
		bool toShowDial = false;
		tmx::Map map;
		map.load("assets/mymap.tmx");
		MapLayer layerZero(map, 0);
		MapLayer layerOne(map, 1);
		Hero h;

		Clock clock1,clock2;
		bool moving = false;
		Vector2i moveto;
		Dialog dial(15);
		dial.thinkOfAnother();
		while (Running)
		{
			float time = clock1.getElapsedTime().asMilliseconds();
			long interval = clock2.getElapsedTime().asSeconds();
			clock1.restart();
			time = time/800 ; 
	
			while (App.pollEvent(Event))
			{
				if (Event.type == sf::Event::Closed)
				{
					return (-1);
				}
			}
			//App.clear();
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

			if (interval >= 8) {
				toShowDial = true;
			}
			if(interval >= 11)
			{
				if (toShowDial)
				{
					clock2.restart();
					dial.thinkOfAnother();
				}
				toShowDial = false;
			}
			if (toShowDial)
			{
				dial.showSmallWindow(to_string(time*800), h.getHeroPos(), App, 1);
			}

			dial.showBigWindow("привет", App);

			App.display();
		}

		return EXIT_SUCCESS;

		return (-1);
	}

};