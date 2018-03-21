#include "charInventory.h"

CharInvetory::CharInvetory(Hero * h)
{
	hero = h;
	map.load("assets/inventory.tmx");
	layerZero.setMap(map, 0);
	mapObjs.setObjects(map, 1);
	cellTexture.loadFromFile("assets/images/inventory/oneblock.png");
	cellSprite.setTexture(cellTexture);
	armorText.move(tmxToSfVector(mapObjs.getObjectByName("armor").getPosition()));
	cureText.move(tmxToSfVector(mapObjs.getObjectByName("cure").getPosition()));
	damageText.move(tmxToSfVector(mapObjs.getObjectByName("dmg").getPosition()));
	defenceText.move(tmxToSfVector(mapObjs.getObjectByName("def").getPosition()));
	healthText.move(tmxToSfVector(mapObjs.getObjectByName("health").getPosition()));
	dodgeText.move(tmxToSfVector(mapObjs.getObjectByName("dodge").getPosition()));
	for (int i = 0; i < hero->inventorySize; i++) {
		cellsSprites.push_back(cellSprite);
		cellsSprites.at(i).setPosition(805+38*column, 280+38*row);
		column++;
		if (column == 12) {
			row++;
			column = 0;
		}
	}

	font.loadFromFile("assets/himalaya.ttf");
	armorText.setFont(font);
	cureText.setFont(font);
	damageText.setFont(font);
	defenceText.setFont(font);
	healthText.setFont(font);
	dodgeText.setFont(font);


	
}
void CharInvetory::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(layerZero);
	for (int i = 0; i < cellsSprites.size(); i++) {
		target.draw(cellsSprites.at(i));
	}
	target.draw(armorText);
	target.draw(cureText);
	target.draw(damageText);
	target.draw(defenceText);
	target.draw(healthText);
	target.draw(dodgeText);
}

string CharInvetory::whereClicked(sf::Vector2f point) {
	string clickedon = "nothing";
	vector<sf::FloatRect> rects =mapObjs.getRects();
	for (int i = 0; i < rects.size(); i++) {
		if (rects[i].contains(point)) {
			clickedon = mapObjs.getObject(i).getName();
			break;
		}
	}

	return clickedon;
}

void CharInvetory::updateStats()
{
	armorText.setString(to_string(hero->armor));
	cureText.setString(to_string(hero->cure));
	damageText.setString(to_string(hero->damage));
	defenceText.setString(to_string(hero->defence));
	healthText.setString(to_string(hero->maxhealth));
	dodgeText.setString(to_string(hero->dodge));

}
sf::Vector2f CharInvetory::tmxToSfVector(tmx::Vector2f f1)
{
	
	return sf::Vector2f(f1.x, f1.y);
}
