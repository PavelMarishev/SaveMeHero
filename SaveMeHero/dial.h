#pragma once

#include <string>
#include <iostream>
#include "JsonDB.h""
using namespace sf;
using namespace std;
class Dialog {
	Font font;
	Text text;
	string* collection;
	int mode = 0;
	string currentIdea;
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
						tempBuf += (j);
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
			if (i > (size*len) - tempBuf)
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
		font.loadFromFile("CyrilicOld.ttf");
		text.setString(default);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
		FileWork FW;
		collection = FW.getJSON();
		mode = type;
		currentIdea = collection[0];
	}
	void thinkOfAnother() 
	{
		string temp = currentIdea;
		do {
			currentIdea = collection[rand() % (collection->size())];
		} while (temp == currentIdea);
	}
	//showSmallWindow ������� ��������� ���������� ���� ����� �����, ���������: �����, ��������� �����, ����, ������, ������ ������
	void showSmallWindow(string speach, Vector2f obj, RenderWindow &window, int forMode = 0, int limitH = 4, int limitW = 10, float forTextAlign = 100, float Scale = 100)
	{
		switch (forMode)
		{
		case 0: {text.setString(format(speach, limitW, limitH)); break; }
		case 1: {text.setString(format(currentIdea, limitW, limitH)); break; }
		}
		
		text.setPosition(Vector2f(obj.x + 50, obj.y - (text.getCharacterSize() + 1)*limitH));
		
		Texture dialTx;
		dialTx.loadFromFile("assets/images/dialWindow.png");
		
		Sprite s(dialTx);
		s.setColor(Color(255,255,255,150));
		s.setScale(Vector2f(1.0/(700/(limitW*(text.getCharacterSize()-3))), 1.0 / (222 / (text.getCharacterSize()*limitH))));
		s.setPosition(Vector2f(obj.x + 25, obj.y - (text.getCharacterSize()+3)*limitH));

		window.draw(s);//����� ���� �������   
		window.draw(text);
	}
	void showBigWindow(string speach, RenderWindow &window,int h = 450, int k = 5)//������� ���� �����
	{
		RectangleShape rect(Vector2f(window.getSize().x, window.getSize().y / k));
		text.setString(speach);

		text.setPosition(Vector2f(10, h));//2 �������� ������ ������ ������(������)
		rect.setPosition(Vector2f(0, h));//2 �������� ������ ������ ����(������)
		rect.setFillColor(Color(255, 255, 255, 169));//4 �������� - ������������
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
};