#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;



class Item {
	struct stat
	{
		std::string statName;
		int statVal;
	};
	int id;
	std::string type;
	std::string name;
	int str;
	int end;
	int intel;
	int dex;
	int armor;
	int cure;
	int damage;
	int defence;
	int dodge;
	Sprite sprite;
	vector<stat> stats;
public:
	Item();
	Item(int id, std::string name, std::string type);
	Item(int id, std::string name, std::string type, int str, int end, int intel, int dex, int armor, int cure, int damage, int defence, int dodge, Sprite sprite);
	std::string get_name();
	int get_id();
	vector<stat> get_stats();
	void Item::make_Items();
};