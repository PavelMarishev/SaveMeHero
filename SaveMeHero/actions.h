#pragma once
#include <iostream>
#include <string>
#include "cScreen.h"
#include "hero.h"
#include "mapScreen.h"
#include "Brain.h"
class Actions 
{
	int currentAct;
	long interval;
	Hero heroInAct;
	Brain brain;
	vector<sf::Vector2f>* pathForActs;
	PathFinding* pfind;
	Clock clock;
	bool toSearchAct;
	int wayLen = 800;
	string* actionArr;
	int actCount;
/*
	ActNode* actMap; =
	{
	new ActNode("none", 0),
	{ "walk", 1 },
	{ "sleep", 2 }
	};
	*/
public:
	Actions(Hero h, PathFinding* pf, vector<sf::Vector2f>* path, Brain br, int AC = 3)
	{
		actCount = AC;
		currentAct = 0;
		heroInAct = h;
		brain = br;
		pathForActs = path;
		pfind = pf;
		actionArr = new string[actCount];
		actionArr[0] = "none";
		actionArr[1] = "walk";
		actionArr[2] = "sleep";
	}
	void DoAction() 
	{
		switch (currentAct)
		{
		case 0: 
			break;
		case 1: 
			walk();
			break;
		case 2:
			sleep();
			break;
		default: break;
		}
	}
	int getActId(string Action) 
	{
		for (int i = 0; i < actCount; i++)
		{
			if (actionArr[i] == Action) 
			{
				return i;
			}
		}
		return 0;
	}
	void setAct(string act) 
	{
		currentAct = getActId(act);
	}
	void walk()
	{
		interval = clock.getElapsedTime().asSeconds();
		if (interval > 8)
		{
			*pathForActs = pfind->findPath(heroInAct.getHeroPos().x, heroInAct.getHeroPos().y, heroInAct.getHeroPos().x + rand()% wayLen - wayLen/2, heroInAct.getHeroPos().y + rand() % wayLen - wayLen/2);
			clock.restart();
		}
	}
	void sleep() 
	{
		brain.SleepZZZ();
	}

};