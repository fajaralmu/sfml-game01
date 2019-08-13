#pragma once
#include <string>
#include <iostream>
#include <SFML\Graphics.hpp>
#include "tile.h"
#include <unordered_map>
#include <memory>
//#include <vector>
#include "pengatur_entitas.h"
#include "Texture.h"

class Denah
{
public:
	Denah(sf::RenderWindow & window,pengatur_entitas* manager,std::string filename, TextureMap* tx);
	void draw(sf::View* view);
	void update(sf::View* view);
	tile tambahTexture(const std::string nama, tile* t);


	~Denah();

private:
	std::unordered_map<std::string, tile*> tiles;
	pengatur_entitas* manager;
	TextureMap* tx;

	sf::RenderWindow* window;

	
	//std::unordered_map<std::string, tile*> textureMap;
};

