#pragma once

#include <string>
#include <iostream>

using namespace sf;
using namespace std;
class Dialog {
	Font font;
	Text text;
	string cutSpace(string s) {
		int i = 0;
		while (i < s.length())
		{
			if (s[i] == ' ')
			{
				int j;
				j = (i > 0 ? (i < (s.length() - 1) ? 1 : 0) : 0);
				while (s[i + j] == ' ')
				{
					s.erase(i + j, 1);
				}
			}
			i++;
		}
		return s;
	}
	string setw(string s, int w)
	{
		s = cutSpace(s);
		if (s.length() < 2 || s.length() > w)  return s;
		else
		{
			int i = 1;
			while (s.length() < w)
			{
				for (int j = i; j < s.length(); j++)
				{
					if (s[j] == ' ')
					{
						s.insert(j, " ");
						i = j;
						break;
					}
				}
			}
			return s;
		}
	}
	string format(string s, int Len = 1, int Size = 1)
	{
		string buf = s;
		buf = cutSpace(buf);
		int len = Len, size = Size, i = 0, temp = 0;
		while (i < (buf.length()))
		{
			bool found = false;
			if (temp >= len)
			{

				for (int j = 0; j < temp - 3; j++)
				{
					if (buf[i - j] == ' ')
					{
						buf[i - j] = '\n';
						temp = j;
						found = true;
						break;
					}
				}
				if (!found)
				{
					buf.insert(i, "\n");
					temp = -1;
				}
			}
			temp++;
			i++;
			if (i > size)
			{
				buf.resize(size);
				buf += "...";
			}
		}
		return buf;
	}
public:
	Dialog(int size = 15, Color color = Color::Black, char* default = "")
	{
		font.loadFromFile("CyrilicOld.ttf");
		text.setString(default);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
	}
	void showSmallWindow(string speach, Vector2f obj, RenderWindow &window, int limitH = 5, int limitW = 10)
	{
		Texture dialTx;
		dialTx.loadFromFile("dialog.png");
		Sprite s(dialTx);

		s.setPosition(Vector2f(obj.x + 15, obj.y - 15));
		RectangleShape rect(Vector2f(limitW*(text.getCharacterSize() / 1.5), text.getCharacterSize()*limitH + 3));
		rect.setPosition(Vector2f(obj.x + 25, obj.y - text.getCharacterSize()*limitH));
		rect.setFillColor(Color(255, 255, 255, 169));
		text.setString(format(speach, limitW, limitW*limitH));
		text.setPosition(Vector2f(obj.x + 30, obj.y - text.getCharacterSize()*limitH));

		//window.draw(s);
		window.draw(rect);
		window.draw(text);
	}
	void showBigWindow(string speach, RenderWindow &window, int k = 5)
	{
		RectangleShape rect(Vector2f(window.getSize().x, window.getSize().y / k));
		text.setString(speach);

		text.setPosition(Vector2f(0, 450));
		rect.setPosition(Vector2f(0,  450));
		rect.setFillColor(Color(255, 255, 255, 169));
		window.draw(rect);
		window.draw(text);
	}
};