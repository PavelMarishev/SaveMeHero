#pragma once

#include <string>
#include <iostream>
#include "JsonDB.h""
using namespace sf;
using namespace std;
class Dialog {
	Font font;
	sf::Text text;
	string** collection;
	int mode = 0;
	//int *ideasCount;
	int ideasCount;
	sf::FloatRect SmallDialRect;
	string currentIdea;
	string currentContext;
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
		Len *= 2;
		string buf = s;
		buf = cutSpace(buf);
		int tempBuf = 0;
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
						tempBuf += j;
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
			if (i > (size*len) - tempBuf - 1)
			{
				buf.resize((size*len) - tempBuf);
				buf += "...";
			}
		}
		return buf;
	}
public:
	Dialog(int size = 14, Color color = Color::Black, char* default = "",int type = 0)
	{
		font.loadFromFile("assets/himalaya.ttf");
		text.setString(default);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
		FileWork FW;
		collection = FW.getJSON(&ideasCount);
		mode = type;
		currentIdea = collection[0][0];
		currentContext = collection[1][0];
	}
	void thinkOfAnother() 
	{
		string temp = currentIdea;
		int t = 0;
		do {
			t = rand() % ideasCount;
			cout << "ideasCount = " << ideasCount << endl;
			currentIdea = collection[0][t];
		} while (temp == currentIdea);
		currentContext = collection[1][t];
	}
	//showSmallWindow выводит маленькое диалоговое окно возле героя, параметры: текст, положение героя, окно, высота, ширина абзаца
	void showSmallWindow(string speach, sf::Vector2f obj, RenderWindow &window, int forMode = 0, int limitH = 4, int limitW = 10, float forTextAlign = 100, float Scale = 100)
	{
		switch (forMode)
		{
		case 0: {text.setString(format(speach, limitW, limitH)); break; }
		case 1: {text.setString(format(currentIdea, limitW, limitH)); break; }
		}
		
		text.setPosition(sf::Vector2f(obj.x + 50, obj.y - (text.getCharacterSize() + 1)*limitH));
		
		Texture dialTx;
		dialTx.loadFromFile("assets/images/dialWindow.png");
		
		Sprite s(dialTx);
		s.setColor(Color(255,255,255,150));
		s.setScale(1.0/(700/(limitW*(text.getCharacterSize()-3))), 1.0 / ((200+ text.getCharacterSize()*2) / (text.getCharacterSize()*limitH)));
		s.setPosition(sf::Vector2f(obj.x + 20, obj.y - (text.getCharacterSize() + 3)*limitH));
		SmallDialRect = s.getGlobalBounds();
		window.draw(s); 
		window.draw(text);
	}
	void showBigWindow(string speach, RenderWindow &window,int h = 450, int k = 5)//большое окно внизу
	{
		RectangleShape rect(sf::Vector2f(window.getSize().x, window.getSize().y / k));
		text.setString(speach);

		text.setPosition(sf::Vector2f(10, h));//2 параметр задает высоту текста(сверху)
		rect.setPosition(sf::Vector2f(0, h));//2 параметр задает высоту окна(сверху)
		rect.setFillColor(Color(255, 255, 255, 169));//4 параметр - прозрачность
		window.draw(rect);
		window.draw(text);
	}
	int getMode() 
	{
		return mode;
	}
	void setMode(int val) 
	{
		mode = val;
	}
	sf::FloatRect getSmallDialRect()
	{
		return SmallDialRect;
	}
	string getCurrentIdea() 
	{
		return currentIdea;
	}
	string getCurrentContext() 
	{
		return currentContext;
	}
};