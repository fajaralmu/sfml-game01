#include "pelurumusuh.h"
#include <iostream>

using namespace std;

pelurumusuh::pelurumusuh(entitas* p, pengatur_entitas* mng, sf::RenderWindow& window, float x, float y)
{
	body.setSize(sf::Vector2f(5.f, 2.f));
	body.setPosition(x, y);
	
	body.setFillColor(sf::Color::Red);
	this->timer = 0;
	this->timeUp = false;
	this->alien = p;

	if (this->alien->kiri)
		this->vel.x = -9;
	else
		this->vel.x = 9;

	this->vel.y = 0;
	this->speed = 9;
	this->id = 4;
	this->manager = mng;

}



void pelurumusuh::update()
{
	this->timer++;
	if (this->timer >= 30)
	{
		this->timeUp = true;
		this->manager->hapus(this);
	}
	body.move(this->vel.x, this->vel.y);


	for (int j = 0; j < this->manager->en.size(); j++)
	{
		if (this->manager->en[j]->getId() ==0)
		{
			if (this->body.getGlobalBounds().intersects(this->manager->en[j]->body.getGlobalBounds()))
			{
				this->manager->hapus(this->manager->en[j]);
				break;
			}
		}

	}



}

pelurumusuh::~pelurumusuh()
{
	delete &this->body;
	delete &this->texture;

}


