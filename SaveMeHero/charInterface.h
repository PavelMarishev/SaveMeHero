#pragma once
#include <SFML\Graphics.hpp>
#include "objectsLayer.h"

using namespace sf;
using namespace tmx;
using namespace std;

class CharInterface :public Drawable {
    private:
		//Texture iconsTexture;
		sf::Text t;
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
			target.draw(t);
		}

     public:

		 CharInterface() {
			
			 map.load("assets/interface.tmx");
			 back.setObjects(map, 0);
			 icons.setObjects(map, 2);

			 backTexture.loadFromFile("assets/images/back.png");
			 frontTexture.loadFromFile("assets/images/newinterface.png");

			 backSprite.setTexture(backTexture);
			 frontSprite.setTexture(frontTexture);
		
			 font.loadFromFile("assets/himalaya.ttf");
			 t.setFont(font);
			 t.setCharacterSize(60);
			 t.setString(to_string(h.currhealth) + "/" +to_string (h.maxhealth));

			 t.move(vectorConvert(icons.getObject("hp").getPosition()));
				
			 backSprite.setPosition(vectorConvert(back.getObject("background").getPosition()));
			 frontSprite.setPosition(vectorConvert(back.getObject("background").getPosition()));
			
			 

		 }
		sf::Vector2f vectorConvert(tmx::Vector2f f1) {
			 sf::Vector2f f2(f1.x, f1.y);
			 return f2;
		 }




};