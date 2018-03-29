#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;

class Hero : public Drawable {
public:
	int money = 100;
	int crystals = 5;
	int maxhealth = 100;
	int currhealth = 99;
	int maxpwr = 100;
	int currpwr = 98;
	int str = 1;
	int end = 1;
	int intel = 1;
	int dex = 1;
	int lvl = 1;
	int armor = 1;
	int cure = 1;
	int damage = 2;
	int defence = 1;
	int dodge = 1;
	int exp = 0;
	int inventorySize = 84;
	String name = "Dark Lord";

	float frame = 0;
	const int speed = 300;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		Sprite todraw = sprite;

		target.draw(sprite, states);
	}
public:
	int get_money() const
	{
		return money;
	}

	void set_money(int money)
	{
		this->money = money;
	}

	int get_crystals() const
	{
		return crystals;
	}

	void set_crystals(int crystals)
	{
		this->crystals = crystals;
	}

	int get_maxhealth() const
	{
		return maxhealth;
	}

	void set_maxhealth(int maxhealth)
	{
		this->maxhealth = maxhealth;
	}

	int get_currhealth() const
	{
		return currhealth;
	}

	void set_currhealth(int currhealth)
	{
		this->currhealth = currhealth;
	}

	int get_maxpwr() const
	{
		return maxpwr;
	}

	void set_maxpwr(int maxpwr)
	{
		this->maxpwr = maxpwr;
	}

	int get_currpwr() const
	{
		return currpwr;
	}

	void set_currpwr(int currpwr)
	{
		this->currpwr = currpwr;
	}

	int get_str() const
	{
		return str;
	}

	void set_str(int str)
	{
		this->str = str;
	}

	int get_end() const
	{
		return end;
	}

	void set_end(int end)
	{
		this->end = end;
	}

	int get_intel() const
	{
		return intel;
	}

	void set_intel(int intel)
	{
		this->intel = intel;
	}

	int get_dex() const
	{
		return dex;
	}

	void set_dex(int dex)
	{
		this->dex = dex;
	}

	int get_lvl() const
	{
		return lvl;
	}

	void set_lvl(int lvl)
	{
		this->lvl = lvl;
	}

	int get_armor() const
	{
		return armor;
	}

	void set_armor(int armor)
	{
		this->armor = armor;
	}

	int get_cure() const
	{
		return cure;
	}

	void set_cure(int cure)
	{
		this->cure = cure;
	}

	int get_damage() const
	{
		return damage;
	}

	void set_damage(int damage)
	{
		this->damage = damage;
	}

	int get_defence() const
	{
		return defence;
	}

	void set_defence(int defence)
	{
		this->defence = defence;
	}

	int get_dodge() const
	{
		return dodge;
	}

	void set_dodge(int dodge)
	{
		this->dodge = dodge;
	}

	int get_exp() const
	{
		return exp;
	}

	void set_exp(int exp)
	{
		this->exp = exp;
	}

	int get_inventory_size() const
	{
		return inventorySize;
	}

	void set_inventory_size(int inventory_size)
	{
		inventorySize = inventory_size;
	}

	String get_name() const
	{
		return name;
	}

	void set_name(const String& name)
	{
		this->name = name;
	}

	Texture texture;
	Sprite sprite;
	sf::FloatRect rect;


	//stats

	//
	Hero() {
		texture.loadFromFile("assets/images/hero.png");
		sprite.setTexture(texture);
		sprite.setTextureRect(sf::IntRect(0, 0, 30, 60));
		sprite.setPosition(1700, 2100);
		rect = sprite.getGlobalBounds();
	};
	sf::FloatRect getRect() {
		return rect;
	}
	void setHeroPos(sf::Vector2f pos) {
		sprite.setPosition(pos);
		rect = sprite.getGlobalBounds();

	}
	sf::Vector2f getHeroPos() {
		return sprite.getPosition();
	}

	bool moveHeroTo(sf::Vector2f where, float time) {
		int x = where.x;
		int y = where.y;

		bool moving = false;

		frame += 10 * time;

		if (frame > 5)frame = 1;
		sprite.setTextureRect(sf::IntRect(33 * (int)frame, 0, 25, 60));

		if ((sprite.getPosition().x) != x) {
			if (sprite.getPosition().x < x) {
				sprite.move(speed*time, 0);
				moving = true;

			}
			if (sprite.getPosition().x > x) {
				sprite.move(-speed * time, 0);
				moving = true;
			}
		}

		if ((sprite.getPosition().y) != y) {
			if (sprite.getPosition().y < y) {
				sprite.move(0, speed*time);
				moving = true;
			}
			if (sprite.getPosition().y > y) {
				sprite.move(0, -speed * time);
				moving = true;
			}
		}
		rect = sprite.getGlobalBounds();
		if (rect.contains(sf::Vector2f(where))) {
			moving = false;
			sprite.setTextureRect(sf::IntRect(0, 0, 30, 60));
		}
		return moving;

	}



};