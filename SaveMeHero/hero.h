#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;
class Hero : public Drawable {
	private:
		
		float frame = 0;
		int speed = 300;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			Sprite todraw = sprite;
			
			target.draw(sprite, states);
		}
	public:
		Texture texture;
		Sprite sprite;
		sf::FloatRect rect;
		//stats
		int money = 100000;
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
		
			frame +=10*time;
	
			if (frame > 5)frame = 1;
			sprite.setTextureRect(sf::IntRect(33 * (int)frame, 0, 25, 60));
		
				if ((sprite.getPosition().x) != x) {
					if (sprite.getPosition().x < x) {
						sprite.move(speed*time, 0);
						moving = true;

					}
					if (sprite.getPosition().x > x) {
						sprite.move(-speed *time, 0);
						moving = true;
					}
				}

				if ((sprite.getPosition().y) != y) {
					if (sprite.getPosition().y < y) {
						sprite.move(0, speed*time);
						moving = true;
					}
					if (sprite.getPosition().y > y) {
						sprite.move(0, -speed *time);
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