#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class cScreen
{
public:
	virtual int Run(RenderWindow & App) = 0;
};