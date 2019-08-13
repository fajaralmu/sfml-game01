#include "player.h"
#include "peluru.h"
#include <iostream>

using namespace std;

int u = 0;
int i = 0;
int n = 0;
int j = 0;
player::player(pengatur_entitas *mng, sf::RenderWindow& window, float x, float y, TextureMap* tx)
{
	body.setSize(sf::Vector2f(50.f, 80.f));
	body.setPosition(x, y - body.getGlobalBounds().height);
	//texture.loadFromFile("robot.png");
	pTex = tx->tambahTexture("robot.png");
	body.setTexture(&pTex);
	//std::cout<<"x" << pTex.getSize().x << endl;
	ukuranTexture = pTex.getSize();
	ukuranTexture.x /= 3;
	ukuranTexture.y /= 3;
	uvRect.width = ukuranTexture.x;
	uvRect.height = ukuranTexture.y;

	uvRect.left = uvRect.width*i;
	this->vel.x = 0;
	this->vel.y = 0;
	this->speed = 5;
	this->turun = true;
	this->kanan = false;
	this->kiri = false;
	this->isCollide = false;
	this->tembak = false;
	this->id = 1;
	this->manager = mng;

	//Bounds
	boundTop.setSize(sf::Vector2f(body.getGlobalBounds().width * 0.6f, 1.f));
	boundBottom.setSize(sf::Vector2f(body.getGlobalBounds().width * 0.6f, 1.f));
	boundRight.setSize(sf::Vector2f(1.f, body.getGlobalBounds().height * 0.6f));
	boundLeft.setSize(sf::Vector2f(1.f, body.getGlobalBounds().height * 0.6f));


}

void player::lompat(float vel, float N)
{
	this->turun = false;
	n++;
	this->vel.y = vel;
	if (n > 0)
	{
		this->vel.y += n;
		if (n >= N)
		{
			this->vel.y = 0;
			n = 0;
			this->naik = false;
			this->turun = true;
		}
	}
}

void player::update()
{
	float p = body.getSize().x;
	float l = body.getSize().y;
	body.move(this->vel.x, this->vel.y);

	boundTop.setPosition(body.getPosition().x + (p - boundTop.getSize().x) / 2, body.getPosition().y);
	boundBottom.setPosition(body.getPosition().x + (p - boundBottom.getSize().x) / 2, body.getPosition().y + body.getGlobalBounds().height - boundBottom.getGlobalBounds().height);
	boundLeft.setPosition(body.getPosition().x, body.getPosition().y + (l - boundLeft.getSize().y) / 2);
	boundRight.setPosition(body.getPosition().x + body.getGlobalBounds().width - boundRight.getGlobalBounds().width, body.getPosition().y + (l - boundRight.getSize().y) / 2);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		u++;

	if (u > 3) {
		u = 0;
		i++;
		if (i >= 3)
		{
			i = 0;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (this->kiri)
			this->kiri = false;
		else
			this->kanan = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		if (this->kanan)
			this->kanan = false;
		else
			this->kiri = true;
	}
	else
	{
		this->row = 1;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !this->naik)
	{
		if (this->turun)
			this->turun = false;
		this->naik = true;
	}
	else  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (this->naik)
			this->naik = false;
		this->turun = true;
	}

	if (this->kanan)
	{
		this->row = 0;
		uvRect.left = abs(uvRect.width)*i;
		uvRect.width = abs(uvRect.width);
	}
	if (this->kiri)
	{
		this->row = 0;
		uvRect.left = abs(uvRect.width)*(i + 1);
		uvRect.width = -abs(uvRect.width);

	}
	if (this->naik)
	{
		if (injak)
		{
			lompat(-1.5f, 1.5f);
			injak = false;
		}
		else
			lompat(-18, 18);
	}
	else if (this->turun)
	{
		this->vel.y = 5;
		this->naik = false;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
		this->speed = 8;
	else
		this->speed = 5;

	this->vel.x = this->speed * (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left));
	body.setTextureRect(sf::IntRect(uvRect.left, uvRect.height*this->row, uvRect.width, uvRect.height));

	this->tembak = sf::Keyboard::isKeyPressed(sf::Keyboard::LControl);
	if (this->tembak)
		this->manager->tambah(new peluru(this, this->manager, *this->window, body.getPosition().x + body.getGlobalBounds().width / 2, body.getPosition().y + body.getGlobalBounds().height / 2));


	for (int i = 0; i < this->manager->en.size(); i++)
	{
		if (this->manager->en[i]->getId() == 3)
		{
			if (boundBottom.getGlobalBounds().intersects(this->manager->en[i]->boundTop.getGlobalBounds()))
			{
				this->naik = true;
				injak = true;
				this->manager->hapus(this->manager->en[i]);
			}
		}
	}
}




player::~player()
{
	//delete &this->body;
	//delete &this->boundBottom;
	//delete &this->boundTop;
	//delete &this->boundRight;
	//delete &this->boundLeft;
}
