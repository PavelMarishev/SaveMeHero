#include <iostream>
#include <SFML/Graphics.hpp>
#include "allScreens.h"
#include "windows.h"

using namespace std;
using namespace sf;
int main()
{
	//SetConsoleCP(1251); 
	//SetConsoleOutputCP(1251);
	srand(time(0));
	vector<cScreen*> Screens;
	int screen = 0;
	RenderWindow App(VideoMode(800,600), "Save Me Hero");
	
	//To add scene just create onbject screen of it and push into Screens array
	testScreen ts;
	Screens.push_back(&ts);
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(App);
	}

	return 0;
}