#include "tile.h"
#include <iostream>


tile::tile(float x, float y, sf::Image img, int ID)
{
	tileRect.setSize(sf::Vector2f(32.f, 32.f));
	this->x = x;
	this->y = y;
	this->ID = ID;
	this->image = img;
	texture.loadFromImage(this->image);
	//std::cout << "load texture" << std::endl;
	tileRect.setTexture(&texture);
	tileRect.setPosition(this->x, this->y);
}

void tile::update()
{
}

void tile::draw(sf::RenderWindow &window)
{
	window.draw(tileRect);
}

void tile::setImage(sf::Image img)
{
	this->image = img;
	texture.loadFromImage(this->image);
	tileRect.setTexture(&texture);
}

void tile::setId(int ID)
{
	this->ID = ID;
}

int tile::getID()
{
	return this->ID;
}


tile::~tile()
{
//	delete &this->texture;
	//delete &this->tileRect;
}
