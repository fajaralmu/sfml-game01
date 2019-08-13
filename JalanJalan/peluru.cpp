#include "peluru.h"
#include <iostream>

using namespace std;

peluru::peluru(player* p, pengatur_entitas* mng, sf::RenderWindow& window, float x, float y)
{
	body.setSize(sf::Vector2f(5.f, 2.f));
	body.setPosition(x, y);
	body.setFillColor(sf::Color::White);
	this->timer = 0;
	this->timeUp = false;
	this->plyr = p;

	if (this->plyr->kiri)
		this->vel.x = -9;
	else
		this->vel.x = 9;

	this->vel.y = 0;
	this->speed = 9;
	this->id = 2;
	this->manager = mng;
}

void peluru::update()
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
		if (this->manager->en[j]->getId() == 3)
		{
			if (this->body.getGlobalBounds().intersects(this->manager->en[j]->body.getGlobalBounds()))
			{
				this->manager->hapus(this->manager->en[j]);
				this->manager->hapus(this);
				break;
			}
		}
	}
}

peluru::~peluru()
{
	delete &this->body;
	delete &this->texture;
}


