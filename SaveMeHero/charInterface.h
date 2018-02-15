#pragma once
#include <SFML\Graphics.hpp>
#include "objectsLayer.h"

using namespace sf;
using namespace tmx;
using namespace std;

class CharInterface :public Drawable {
    private:
		//Texture iconsTexture;
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

		Hero h;
		Font font;
		Texture backTexture;
		Texture frontTexture;
		Sprite backSprite;
		Sprite frontSprite;
		Map map;
		Objects back;
		Objects icons;

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			target.draw(backSprite);
			target.draw(frontSprite);
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

		 CharInterface() {
			
			 map.load("assets/interface.tmx");
			 back.setObjects(map, 0);
			 icons.setObjects(map, 2);

			 backTexture.loadFromFile("assets/images/back.png");
			 frontTexture.loadFromFile("assets/images/newinterface2.png");

			 backSprite.setTexture(backTexture);
			 frontSprite.setTexture(frontTexture);
		
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
			

			 hpBarText.setString(to_string(h.currhealth) + "/" +to_string (h.maxhealth));
			 pwrBarText.setString(to_string(h.currpwr) + "/" + to_string(h.maxpwr));
			 armorText.setString(to_string(h.armor));
			 cureText.setString(to_string(h.cure));
			 damageText.setString(to_string(h.damage));
			 defenceText.setString(to_string(h.defence));
			 healthText.setString(to_string(h.maxhealth));
			 dodgeText.setString(to_string(h.dodge));
			 strText.setString(to_string(h.str));
			 endText.setString(to_string(h.end));
			 intelText.setString(to_string(h.intel));
			 dexText.setString(to_string(h.dex));
			 lvlText.setString(to_string(h.lvl));
			 lvlToText.setString(to_string(h.lvl + 1));
			 moneyText.setString(to_string(h.money));
			 gemText.setString(to_string(h.crystals));
			 nameText.setString(h.name);



			 hpBarText.move(vectorConvert(icons.getObject("hp").getPosition()));
			 pwrBarText.move(vectorConvert(icons.getObject("pwr").getPosition()));
			 armorText.move(vectorConvert(icons.getObject("armor").getPosition()));
			 cureText.move(vectorConvert(icons.getObject("cure").getPosition()));
			 damageText.move(vectorConvert(icons.getObject("dmg").getPosition()));
			 defenceText.move(vectorConvert(icons.getObject("def").getPosition()));
			 healthText.move(vectorConvert(icons.getObject("health").getPosition()));
			 dodgeText.move(vectorConvert(icons.getObject("dodge").getPosition()));
			 strText.move(vectorConvert(icons.getObject("str").getPosition()));
			 endText.move(vectorConvert(icons.getObject("end").getPosition()));
			 intelText.move(vectorConvert(icons.getObject("int").getPosition()));
			 dexText.move(vectorConvert(icons.getObject("dex").getPosition()));
			 lvlText.move(vectorConvert(icons.getObject("lvl").getPosition()));
			 lvlToText.move(vectorConvert(icons.getObject("lvlto").getPosition()));
			 moneyText.move(vectorConvert(icons.getObject("money").getPosition()));
			 gemText.move(vectorConvert(icons.getObject("gems").getPosition()));
			 nameText.move(vectorConvert(icons.getObject("nickname").getPosition()));

			 backSprite.setPosition(vectorConvert(back.getObject("background").getPosition()));
			 frontSprite.setPosition(vectorConvert(back.getObject("background").getPosition()));
			
			 

		 }
		sf::Vector2f vectorConvert(tmx::Vector2f f1) {
			 sf::Vector2f f2(f1.x, f1.y);
			 return f2;
		 }




};