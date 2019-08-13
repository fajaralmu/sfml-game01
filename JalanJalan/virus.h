#pragma once
#include <SFML\Graphics.hpp>
#include "pengatur_entitas.h"

class virus: public entitas

{
public:
	virus(pengatur_entitas *mng, sf::RenderWindow & window, float x, float y, TextureMap* tx);

	sf::Texture pTes;

	void update();
	~virus();

private:
	int u = 0;
	int i = 0;
	float row;
	sf::Vector2u ukuranTexture;
	sf::IntRect uvRect;
	pengatur_entitas * manager;
};
