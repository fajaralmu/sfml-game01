#pragma once
#include <SFML\Graphics.hpp>
#include "pengatur_entitas.h"

class player : public entitas

{
public:
	player(pengatur_entitas *mng,sf::RenderWindow & window, float x, float y, TextureMap* tx);

	void update();
	void lompat(float vel, float N);
	//void draw(sf::RenderWindow & window);
	~player();
	sf::Texture pTex;


private:
	float row;
	bool injak;
	pengatur_entitas *manager;
	sf::Vector2u ukuranTexture;
	sf::IntRect uvRect;
	//sf::RenderWindow* window;
	

};
