#include "Item.h"
using namespace std;

Item::Item(){}
Item::Item(int id, std::string name,std::string type)
{
	this->id = id;
	this->name = name;
	this->type = type;
}

Item::Item(int id,
	std::string name,
	std::string type,
	int str,
	int end,
	int intel, 
	int dex,
	int armor, 
	int cure,
	int damage,
	int defence,
	int dodge,
	Sprite sprite)
{
	this->id = id;
	this->name = name;
	this->str = str;
	this->end = end;
	this->intel = intel;
	this->dex = dex;
	this->armor = armor;
	this->cure = cure;
	this->damage = damage;
	this->defence = defence;
	this->dodge = dodge;
	this->sprite = sprite;

}

std::string Item::get_name()
{
	return name;
}

int Item::get_id()
{
	return id;
}

vector<Item::stat> Item::get_stats()
{
	return stats;
}
void Item::make_Items()
{
	
}
