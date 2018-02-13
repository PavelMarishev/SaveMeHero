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
		enum dirs { L, R, U, D } dir = D;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
		{
			Sprite todraw = heroSprite;
			
			target.draw(heroSprite, states);
		}
	public:
		Hero() {
			heroTexture.loadFromFile("assets/images/herosprite.png");
			heroSprite.setTexture(heroTexture);
			heroSprite.setTextureRect(IntRect(0, 0, 30, 60));
			heroSprite.setPosition(400, 400);
		};
		void setHeroPos(int x, int y) {
			heroSprite.setPosition(x, y);
		}
		Vector2f getHeroPos() 
		{
			return heroSprite.getPosition();
		}

		bool moveHeroTo(Vector2i where, float time) {
			int x = where.x;
			int y = where.y;

			bool moving = false;
			frame += 15 * time;

			if (frame > 8)frame = 0;
			if (abs(heroSprite.getPosition().x - x) < abs(heroSprite.getPosition().y - y)&&(abs(heroSprite.getPosition().y - y)>3))
			{
				if (heroSprite.getPosition().y < y) 
				{
					dir = D;
					heroSprite.setTextureRect(IntRect(30 * int(frame), 65, 30, 60));//v
				}
				else 
				{
					dir = U;
					heroSprite.setTextureRect(IntRect(30 * int(frame), 0, 30, 60)); //^
				}
			}
			else if(abs(heroSprite.getPosition().x - x) > abs(heroSprite.getPosition().y - y) && (abs(heroSprite.getPosition().x - x)>3))
			{
				if (heroSprite.getPosition().x < x)
				{
					dir = L;
					heroSprite.setTextureRect(IntRect(30 * int(frame), 130, 30, 60));//<
				}
				else 
				{
					dir = R;
					heroSprite.setTextureRect(IntRect(30 * int(frame), 194, 30, 60)); //>
				}
			}
			else 
			{
				switch (dir)
				{
				case L:
					heroSprite.setTextureRect(IntRect(0, 130, 30, 60));
					break;
				case R:
					heroSprite.setTextureRect(IntRect(0, 194, 30, 60));
					break;
				case U:
					heroSprite.setTextureRect(IntRect(120, 0, 30, 60));
					break;
				case D:
					heroSprite.setTextureRect(IntRect(120, 65, 30, 60));
					break;
				}
			}

			if (heroSprite.getPosition().x < x) {
				heroSprite.move(300 * time, 0);
				moving = true;

			}
			if (heroSprite.getPosition().x > x) {
				heroSprite.move(-300 * time, 0);
				moving = true;
			}

			if (heroSprite.getPosition().y < y) {
				heroSprite.move(0, 300 * time);
				moving = true;
			}
			if (heroSprite.getPosition().y > y) {
				heroSprite.move(0, -300 * time);
				moving = true;
			}
			return moving;
		}
};