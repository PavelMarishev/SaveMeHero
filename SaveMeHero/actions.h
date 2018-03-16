#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "hero.h"
#include "mapScreen.h"
#include "Brain.h"
class Actions 
{
	string currentAct;
	long interval;
	Clock clock;
	bool toSearchAct;

	int wayLen = 800;
public:
	Actions(string CA = "stay") 
	{
		currentAct = CA;
	}
	void walk(PathFinding pf, vector<sf::Vector2f>* path, Hero h)
	{
		interval = clock.getElapsedTime().asSeconds();

		if (interval > 8)
		{
			*path = pf.findPath(h.getHeroPos().x, h.getHeroPos().y, h.getHeroPos().x + rand()% wayLen - wayLen/2, h.getHeroPos().y + rand() % wayLen - wayLen/2);
			clock.restart();
		}
	}
	void stay() {}

};