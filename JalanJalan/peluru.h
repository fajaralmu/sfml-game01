#pragma once
#include <SFML\Graphics.hpp>
#include "pengatur_entitas.h"
#include "player.h"

class peluru : public entitas

{
public:
	peluru(player* p,pengatur_entitas* mng, sf::RenderWindow & window, float x, float y);

	void update();
	~peluru();
	
	int timer;
	bool timeUp;
	

	pengatur_entitas* manager;
	player* plyr;

	
};
