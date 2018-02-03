#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;
class Hero : public Drawable {
	private:
		Texture heroTexture;
		Sprite heroSprite;
		float frame = 0;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			Sprite todraw = heroSprite;
			
			target.draw(heroSprite, states);
		}
	public:
		Hero() {
			heroTexture.loadFromFile("assets/images/hero.png");
			heroSprite.setTexture(heroTexture);
			heroSprite.setTextureRect(IntRect(0, 0, 30, 65));
			heroSprite.setPosition(400, 400);
		
		};
		void setHeroPos(int x, int y) {
			heroSprite.setPosition(x, y);
		}
		bool moveHeroTo(Vector2i where, float time) {
			int x = where.x;
			int y = where.y;

			bool moving = false;
		
			frame +=10*time;
	
			if (frame > 5)frame = 1;
			heroSprite.setTextureRect(IntRect(33 * (int)frame, 0, 25, 60));
		
				if ((heroSprite.getPosition().x) != x) {
					if (heroSprite.getPosition().x < x) {
						heroSprite.move(300*time, 0);
						moving = true;

					}
					if (heroSprite.getPosition().x > x) {
						heroSprite.move(-300*time, 0);
						moving = true;
					}
				}

				if ((heroSprite.getPosition().y) != y) {
					if (heroSprite.getPosition().y < y) {
						heroSprite.move(0, 300*time);
						moving = true;
					}
					if (heroSprite.getPosition().y > y) {
						heroSprite.move(0, -300*time);
						moving = true;
					}
				}
			
				return moving;

		}

	

};