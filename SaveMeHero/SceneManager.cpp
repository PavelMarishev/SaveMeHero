#include <iostream>
#include <SFML/Graphics.hpp>
#include "allScreens.h"


int main()
{
	
	vector<cScreen*> Screens;
	int screen = 0;
	//RenderWindow App(VideoMode(1280,720), "Save Me Hero");
	RenderWindow App(VideoMode(800, 800), "Save Me Hero");
	//To add scene just create onbject screen of it and push into Screens array
	MapScreen mainMapScreen;
	Screens.push_back(&mainMapScreen);
//	InterfaceScreen interfaceScreen;
	//Screens.push_back(&interfaceScreen);
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return 0;
}