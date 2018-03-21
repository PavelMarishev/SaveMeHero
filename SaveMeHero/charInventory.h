#pragma once
#include <SFML\Graphics.hpp>
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
#include "hero.h"

using namespace sf;
using namespace tmx;
using namespace std;

class CharInvetory : public Drawable{
	Hero * hero;
	Texture cellTexture;
	Sprite cellSprite;
	vector<Sprite> cellsSprites;
	int row = 0;
	int column = 0;
	Objects mapObjs;
	MapLayer layerZero;
	Map map;
	sf::Text armorText;
	sf::Text cureText;
	sf::Text damageText;
	sf::Text defenceText;
	sf::Text healthText;
	sf::Text dodgeText;
	Font font;

	public:
	CharInvetory(Hero *h);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	string whereClicked(sf::Vector2f point);
	void updateStats();
	sf::Vector2f tmxToSfVector(tmx::Vector2f f1);
};