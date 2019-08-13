#include "virus.h"
#include <iostream>
#include "pelurumusuh.h"

using namespace std;

virus::virus(pengatur_entitas *mng, sf::RenderWindow& windowm, float x, float y, TextureMap* tx)
{
	srand(time(NULL));
	body.setSize(sf::Vector2f(50.f, 50.f));
	body.setPosition(x, y);
	
	this->pTes = tx->tambahTexture("virus.png");

	body.setTexture(&this->pTes);

	ukuranTexture = texture.getSize();
	ukuranTexture.x /= 3;
	ukuranTexture.y /= 3;
	uvRect.width = ukuranTexture.x;
	uvRect.height = ukuranTexture.y;

	uvRect.left = uvRect.width*i;
	this->vel.x = 2;
	this->vel.y = 0;
	this->speed = 5;
	this->turun = true;
	this->kanan = true;
	this->kiri = false;
	this->isCollide = false;
	this->tembak = false;
	this->id = 3;
	this->manager = mng;

	//Bounds
	boundTop.setSize(sf::Vector2f(body.getGlobalBounds().width * 0.6f, 20.f));
	boundTop.setFillColor(sf::Color::Transparent);
	boundBottom.setSize(sf::Vector2f(body.getGlobalBounds().width * 0.6f, 1.f));
	boundRight.setSize(sf::Vector2f(1.f, body.getGlobalBounds().height * 0.6f));
	boundLeft.setSize(sf::Vector2f(1.f, body.getGlobalBounds().height * 0.6f));

}



void virus::update()
{

	float p = body.getSize().x;
	float l = body.getSize().y;
	body.move(this->vel.x, this->vel.y);

	boundTop.setPosition(body.getPosition().x + (p - boundTop.getSize().x) / 2, body.getPosition().y);
	boundBottom.setPosition(body.getPosition().x + (p - boundBottom.getSize().x) / 2, body.getPosition().y + body.getGlobalBounds().height - boundBottom.getGlobalBounds().height);
	boundLeft.setPosition(body.getPosition().x, body.getPosition().y + (l - boundLeft.getSize().y) / 2);
	boundRight.setPosition(body.getPosition().x + body.getGlobalBounds().width - boundRight.getGlobalBounds().width, body.getPosition().y + (l - boundRight.getSize().y) / 2);

	this->u++;

	if (this->u > 3) {
		this->u = 0;
		switch (rand() % 5)
		{
		case 1:
			this->tembak = true;
			break;
		default:
			break;
		}
		this->i++;
		if (this->i >= 3)
		{
			this->tembak = false;
			this->i = 0;
		}
	}


	this->row = 1;

	if (this->kanan)
	{
		this->row = 0;
		uvRect.left = abs(uvRect.width)*this->i;
		uvRect.width = abs(uvRect.width);
	}
	if (this->kiri)
	{
		this->row = 0;
		uvRect.left = abs(uvRect.width)*(this->i + 1);
		uvRect.width = -abs(uvRect.width);
	}
	if (this->turun)
	{
		this->vel.y = 5;
		this->naik = false;
	}
	if (this->tembak)
		this->manager->tambah(new pelurumusuh(this, this->manager, *this->window, body.getPosition().x + body.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2));


	//body.setTextureRect(sf::IntRect(uvRect.left, uvRect.height*this->row, uvRect.width, uvRect.height));
}

virus::~virus()
{
	delete &this->texture;
	delete &this->body;
	delete &this->boundBottom;
	delete &this->boundTop;
	delete &this->boundRight;
	delete &this->boundLeft;
}
