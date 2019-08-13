#pragma once
#include <SFML\Graphics.hpp>
#include "Texture.h"
//std::unordered_map<std::string, std::shared_ptr<sf::Texture>> Texture::textureMap;


class entitas: public sf::Sprite
{
public:
	entitas();
	~entitas();
	virtual void update() {}
	virtual int getId();
	int id;
	virtual void draw(sf::RenderWindow & window);
	
	sf::Texture pTex;
	sf::Texture texture;
	sf::RectangleShape body;

	sf::RectangleShape boundLeft;
	sf::RectangleShape boundRight;
	sf::RectangleShape boundTop;
	sf::RectangleShape boundBottom;

	sf::Vector2f vel;
	bool kanan, kiri, turun, naik, tembak;
	bool isCollide;
	float speed;
	sf::RenderWindow* window;
	
	float row;
	sf::Vector2u ukuranTexture;
	sf::IntRect uvRect;
	
	

	
};

