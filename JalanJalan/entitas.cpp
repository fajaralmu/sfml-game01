#include "entitas.h"
#include <iostream>



entitas::entitas()
{
	
}

int entitas::getId()
{
	return this->id;
}

void entitas::draw(sf::RenderWindow & window)
{
	window.draw(body);
}

entitas::~entitas()
{
}


