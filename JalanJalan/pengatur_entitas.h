#pragma once
#include "entitas.h"
#include <string>
#include <unordered_map>
#include <SFML\Graphics.hpp>

class pengatur_entitas
{
public:
	pengatur_entitas(sf::RenderWindow* win);
	void tambah(entitas* en);
	void update(sf::View* view);
	void draw(sf::View* view);
	void hapus(entitas* en);

	~pengatur_entitas();

	std::vector<entitas*> en;
	sf::RenderWindow * window;
	std::unordered_map <std::string, sf::Texture> textureMap;
private:

};

