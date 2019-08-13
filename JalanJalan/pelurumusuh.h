#pragma once
#include <SFML\Graphics.hpp>
#include "pengatur_entitas.h"
#include "player.h"

class pelurumusuh : public entitas

{
public:
	pelurumusuh(entitas* p, pengatur_entitas* mng, sf::RenderWindow & window, float x, float y);

	void update();
	~pelurumusuh();

	int timer;
	bool timeUp;


	pengatur_entitas* manager;
	entitas* alien;


};
