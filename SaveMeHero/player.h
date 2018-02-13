#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


using namespace sf;
using namespace std;
	class PLAYER //: public Drawable {
	{

	public:

		float dx, dy;
		FloatRect rect;
		Sprite sprite;
		float frame;
		enum dirs { L, R, U, D } dir = D;


		PLAYER(Texture &image)
		{
			sprite.setTexture(image);
			rect = FloatRect(7 * 32, 9 * 32, 30, 60);
			dx = dy = 0.1;
			frame = 0;
		}


		void update(float time)
		{
			rect.left += (dx)* time;
//			Collision(0);
			rect.top += (dy)* time;
			//Collision(1);

			frame += 0.005*time;
			if (frame > 8) frame = 0;

			if (dx > 0) { dir = L; sprite.setTextureRect(IntRect(30 * int(frame), 130, 30, 60)); }
			if (dx < 0) { dir = R; sprite.setTextureRect(IntRect(30 * int(frame), 194, 30, 60)); }
			if (dy < 0) { dir = U; sprite.setTextureRect(IntRect(30 * int(frame), 0, 30, 60)); }
			if (dy > 0) { dir = D; sprite.setTextureRect(IntRect(30 * int(frame), 65, 30, 60)); }
			if (dy == 0 && dx == 0) {
				switch (dir)
				{
				case L:
					sprite.setTextureRect(IntRect(0, 130, 30, 60));
					break;
				case R:
					sprite.setTextureRect(IntRect(0, 194, 30, 60));
					break;
				case U:
					sprite.setTextureRect(IntRect(120, 0, 30, 60));
					break;
				case D:
					sprite.setTextureRect(IntRect(120, 65, 30, 60));
					break;
				}
			}

//			sprite.setPosition(rect.left - offsetX, rect.top - offsetY);

			dx = 0;
		}

		/*void Collision(int d)
		{
			for (int i = rect.top / 32; i<(rect.top + rect.height) / 32; i++)
				for (int j = rect.left / 32; j<(rect.left + rect.width) / 32; j++)
				{
					if (TileMap[i][j] == '0')
					{
						if ((dx>0) && (d == 0)) rect.left = j * 32 - rect.width;
						if ((dx<0) && (d == 0)) rect.left = j * 32 + 32;
						if ((dy>0) && (d == 1)) { rect.top = i * 32 - rect.height; }
						if ((dy<0) && (d == 1)) { rect.top = i * 32 + 32; }
					}

					if (TileMap[i][j] == 'G')
					{
						TileMap[i][j] = ' ';
					}
				}
		}*/
	};