#pragma once
#include <SFML\Graphics.hpp>
#include "objectsLayer.h"
#include "SFMLOrthogonalLayer.hpp"
using namespace sf;
using namespace tmx;
using namespace std;

class CharInterface :public Drawable {
private:
	sf::FloatRect recto;
	sf::Text hpBarText;
	sf::Text pwrBarText;
	sf::Text armorText;
	sf::Text cureText;
	sf::Text damageText;
	sf::Text defenceText;
	sf::Text healthText;
	sf::Text dodgeText;
	sf::Text strText;
	sf::Text endText;
	sf::Text intelText;
	sf::Text dexText;
	sf::Text lvlText;
	sf::Text lvlToText;
	sf::Text moneyText;
	sf::Text gemText;
	sf::Text nameText;
	Map map;
	Hero *hero;
	Font font;
	//	Texture backTexture;
	//	Sprite backSprite;
	MapLayer ml;
	//	Objects back;
	Objects icons;
	Objects clickable;

	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		//	target.draw(backSprite);
		target.draw(ml);
		target.draw(hpBarText);
		target.draw(pwrBarText);
		target.draw(armorText);
		target.draw(cureText);
		target.draw(damageText);
		target.draw(defenceText);
		target.draw(healthText);
		target.draw(dodgeText);
		target.draw(strText);
		target.draw(endText);
		target.draw(intelText);
		target.draw(dexText);
		target.draw(lvlText);
		target.draw(lvlToText);
		target.draw(moneyText);
		target.draw(gemText);
		target.draw(nameText);

	}

public:

	CharInterface(Hero *h) {
		hero = h;

		map.load("assets/interface.tmx");

		ml.setMap(map, 1);
		icons.setObjects(map, 2);
		clickable.setObjects(map, 3);

		font.loadFromFile("assets/himalaya.ttf");
		hpBarText.setFont(font);
		pwrBarText.setFont(font);
		armorText.setFont(font);
		cureText.setFont(font);
		damageText.setFont(font);
		defenceText.setFont(font);
		healthText.setFont(font);
		dodgeText.setFont(font);
		strText.setFont(font);
		endText.setFont(font);
		intelText.setFont(font);
		dexText.setFont(font);
		lvlText.setFont(font);
		lvlToText.setFont(font);
		moneyText.setFont(font);
		gemText.setFont(font);
		nameText.setFont(font);



		hpBarText.setCharacterSize(60);
		pwrBarText.setCharacterSize(60);
		armorText.setCharacterSize(30);
		cureText.setCharacterSize(30);
		damageText.setCharacterSize(30);
		defenceText.setCharacterSize(30);
		healthText.setCharacterSize(30);
		dodgeText.setCharacterSize(30);
		strText.setCharacterSize(50);
		endText.setCharacterSize(50);
		intelText.setCharacterSize(50);
		dexText.setCharacterSize(50);
		lvlText.setCharacterSize(50);
		lvlToText.setCharacterSize(50);
		moneyText.setCharacterSize(40);
		gemText.setCharacterSize(40);
		nameText.setCharacterSize(60);


		sf::Color grey(192, 192, 192);

		hpBarText.setFillColor(grey);
		pwrBarText.setFillColor(grey);
		lvlText.setFillColor(Color::Black);
		lvlToText.setFillColor(Color::Black);

		hpBarText.setString(to_string(hero->get_currhealth()) + "/" + to_string(hero->get_maxhealth()));
		pwrBarText.setString(to_string(hero->get_currpwr()) + "/" + to_string(hero->get_maxpwr()));
		armorText.setString(to_string(hero->get_armor()));
		cureText.setString(to_string(hero->get_cure()));
		damageText.setString(to_string(hero->get_damage()));
		defenceText.setString(to_string(hero->get_defence()));
		healthText.setString(to_string(hero->get_maxhealth()));
		dodgeText.setString(to_string(hero->get_dodge()));
		strText.setString(to_string(hero->get_str()));
		endText.setString(to_string(hero->get_end()));
		intelText.setString(to_string(hero->get_intel()));
		dexText.setString(to_string(hero->get_dex()));
		lvlText.setString(to_string(hero->get_lvl()));
		lvlToText.setString(to_string(hero->get_lvl() + 1));
		moneyText.setString(to_string(hero->get_money()));
		gemText.setString(to_string(hero->get_crystals()));
		nameText.setString(hero->get_name());


		hpBarText.move(tmxToSfVector(icons.getObjectByName("hp").getPosition()));
		pwrBarText.move(tmxToSfVector(icons.getObjectByName("pwr").getPosition()));
		armorText.move(tmxToSfVector(icons.getObjectByName("armor").getPosition()));
		cureText.move(tmxToSfVector(icons.getObjectByName("cure").getPosition()));
		damageText.move(tmxToSfVector(icons.getObjectByName("dmg").getPosition()));
		defenceText.move(tmxToSfVector(icons.getObjectByName("def").getPosition()));
		healthText.move(tmxToSfVector(icons.getObjectByName("health").getPosition()));
		dodgeText.move(tmxToSfVector(icons.getObjectByName("dodge").getPosition()));
		strText.move(tmxToSfVector(icons.getObjectByName("str").getPosition()));
		endText.move(tmxToSfVector(icons.getObjectByName("end").getPosition()));
		intelText.move(tmxToSfVector(icons.getObjectByName("int").getPosition()));
		dexText.move(tmxToSfVector(icons.getObjectByName("dex").getPosition()));
		lvlText.move(tmxToSfVector(icons.getObjectByName("lvl").getPosition()));
		lvlToText.move(tmxToSfVector(icons.getObjectByName("lvlto").getPosition()));
		moneyText.move(tmxToSfVector(icons.getObjectByName("money").getPosition()));
		gemText.move(tmxToSfVector(icons.getObjectByName("gems").getPosition()));
		nameText.move(tmxToSfVector(icons.getObjectByName("nickname").getPosition()));





	}
	sf::Vector2f tmxToSfVector(tmx::Vector2f f1) {
		sf::Vector2f f2(f1.x, f1.y);
		return f2;
	}
	void updateStats() {
		hpBarText.setString(to_string(hero->get_currhealth()) + "/" + to_string(hero->get_maxhealth()));
		pwrBarText.setString(to_string(hero->get_currpwr()) + "/" + to_string(hero->get_maxpwr()));
		armorText.setString(to_string(hero->get_armor()));
		cureText.setString(to_string(hero->get_cure()));
		damageText.setString(to_string(hero->get_damage()));
		defenceText.setString(to_string(hero->get_defence()));
		healthText.setString(to_string(hero->get_maxhealth()));
		dodgeText.setString(to_string(hero->get_dodge()));
		strText.setString(to_string(hero->get_str()));
		endText.setString(to_string(hero->get_end()));
		intelText.setString(to_string(hero->get_intel()));
		dexText.setString(to_string(hero->get_dex()));
		lvlText.setString(to_string(hero->get_lvl()));
		lvlToText.setString(to_string(hero->get_lvl() + 1));
		moneyText.setString(to_string(hero->get_money()));
		gemText.setString(to_string(hero->get_crystals()));
		nameText.setString(hero->get_name());
	}


	string whereClicked(sf::Vector2f point) {
		string clickedon = "nothing";
		vector<sf::FloatRect> rects = clickable.getRects();
		for (int i = 0; i < rects.size(); i++) {
			if (rects[i].contains(point)) {
				clickedon = clickable.getObject(i).getName();
			}
		}

		return clickedon;
	}




};