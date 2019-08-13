#include "pengatur_entitas.h"
#include "peluru.h"
#include "alien.h"
#include "player.h"
#include <iostream>

pengatur_entitas::pengatur_entitas(sf::RenderWindow * win)
{
	this->window = win;
}

void pengatur_entitas::tambah(entitas * en)
{
	this->en.push_back(en);
	//std::cout << en->getId() << std::endl;
	
}



void pengatur_entitas::update(sf::View* view)
{

	for (int i = 0; i < this->en.size(); i++)
	{
		if (this->en[i]->body.getPosition().x > view->getCenter().x - view->getSize().x * 0.6f  && this->en[i]->body.getPosition().x < view->getCenter().x + view->getSize().x* 0.6f
			&& this->en[i]->body.getPosition().y > view->getCenter().y - view->getSize().y * 0.6f && this->en[i]->body.getPosition().y < view->getCenter().y + view->getSize().y * 0.6f)
			en[i]->update();

	}
}

void pengatur_entitas::draw(sf::View* view)
{
	for (int i = 0; i < this->en.size(); i++)
	{
		//std::cout << en[i]->body.getPosition().x << std::endl;
		if (this->en[i]->body.getPosition().x > view->getCenter().x - view->getSize().x * 0.6f  && this->en[i]->body.getPosition().x < view->getCenter().x + view->getSize().x* 0.6f
			&& this->en[i]->body.getPosition().y > view->getCenter().y - view->getSize().y * 0.6f && this->en[i]->body.getPosition().y < view->getCenter().y + view->getSize().y * 0.6f)
			en[i]->draw(*this->window);
	}
}

void pengatur_entitas::hapus(entitas* en)
{
	for (int i = 0; i < this->en.size(); i++)
	{
		if (this->en[i] == en)
		{
			this->en.erase(this->en.begin() + i);

		}
	}
}

pengatur_entitas::~pengatur_entitas()
{
	
}
