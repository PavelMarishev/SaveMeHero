#include <iostream>
#include <SFML/Graphics.hpp>
#include "allScreens.h"


int main()
{
	
	vector<cScreen*> Screens;
	int screen = 0;
	RenderWindow App(VideoMode(1280,623), "Save Me Hero");
	//RenderWindow App(VideoMode(800, 800), "Save Me Hero");
	//To add scene just create onbject screen of it and push into Screens array
	Texture cursorT;
	Sprite cursor;
	cursorT.loadFromFile("assets/images/cursors.png");
	cursor.setTexture(cursorT);
	cursor.setTextureRect(sf::IntRect(73, 11, 20, 20));

	MapScreen mainMapScreen(&cursor);
	Screens.push_back(&mainMapScreen);
	InterfaceScreen interfaceScreen(&cursor);
	Screens.push_back(&interfaceScreen);
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return 0;
}