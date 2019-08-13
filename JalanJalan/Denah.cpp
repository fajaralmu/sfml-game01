#include "Denah.h"
#include "alien.h"
#include "virus.h"
#include <fstream>
#include <sstream>

using namespace std;
using namespace sf;

Denah::Denah(sf::RenderWindow & window, pengatur_entitas* manager, std::string filename, TextureMap* tx)
{
	sf::Image tileSetTexture;
	sf::Texture texture;
	this->manager = manager;
	this->window = &window;
	this->tx = tx;
	std::string tileSet;
	int width = 0;
	int height = 0;
	int tileWidth = 0;
	int tileHeight = 0;
	int* data;

	bool cleft = false,
		cright = false;

	std::string temp;
	std::ifstream fileDenah(filename);

	std::getline(fileDenah, tileSet);
	sf::Texture tex;

	std::getline(fileDenah, temp);
	tileWidth = stoi(temp, nullptr);
	std::getline(fileDenah, temp);
	tileHeight = stoi(temp, nullptr);

	std::getline(fileDenah, temp);
	width = stoi(temp, nullptr);
	std::getline(fileDenah, temp);
	height = stoi(temp, nullptr);

	data = new int[width * height];
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			char temp;
			fileDenah >> data[x + y*width] >> temp;
			std::cout << data[x + y*width];
		}
	}
	fileDenah.close();

	texture.create(tileWidth * width, tileHeight * height);
	tileSetTexture.loadFromFile("tile.png");
	sf::Image tile1, tile2, tile3, tile4, tile5, tile6;

	tile1.create(tileWidth, tileHeight);
	tile2.create(tileWidth, tileHeight);
	tile3.create(tileWidth, tileHeight);
	tile4.create(tileWidth, tileHeight);
	tile5.create(tileWidth, tileHeight);
	tile6.create(tileWidth, tileHeight);
	alien* a1;
	a1 = new alien(this->manager, *this->window, 0, 0, this->tx);
	//a1->body.setTexture(&this->manager->tambahTexture("alien.png"));
	virus* v1;
	v1 = new virus(this->manager, *this->window, 0, 0, this->tx);
	//v1->body.setTexture(&this->manager->tambahTexture("virus.png"));
	

	tile1.copy(tileSetTexture, 0, 0, IntRect(0, 0, tileWidth, tileHeight), true);
	tile2.copy(tileSetTexture, 0, 0, IntRect(tileWidth, 0, tileWidth, tileHeight), true);
	tile3.copy(tileSetTexture, 0, 0, IntRect(0, tileHeight, tileWidth, tileHeight), true);
	tile4.copy(tileSetTexture, 0, 0, IntRect(tileWidth, tileHeight, tileWidth, tileHeight), true);
	tile5.copy(tileSetTexture, 0, 0, IntRect(0, tileHeight * 2, tileWidth, tileHeight), true);
	tile6.copy(tileSetTexture, 0, 0, IntRect(tileWidth, tileHeight * 2, tileWidth, tileHeight), true);
	
	tile* t1;
	t1 = new tile(0, 0, tile1, 1);
	tile* t2;
	t2 = new tile(0, 0, tile2, 2);
	tile* t3;
	t3 = new tile(0, 0, tile3, 3);
	tile* t4;
	t4 = new tile(0, 0, tile4, 4);
	tile* t5;
	t5 = new tile(0, 0, tile5, 5);
	tile* t6;
	t6 = new tile(0, 0, tile6, 6);

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			switch (data[x + y*width])
			{
			case 1:
				t1->tileRect.setPosition(x * tileWidth, y * tileHeight);
				this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(*t1)));
				break;
			case 2:
				t2->tileRect.setPosition(x * tileWidth, y * tileHeight);
				this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(*t2)));
				//tambahTexture("tile2", new tile(*t2));
				break;
			case 3:
				t3->tileRect.setPosition(x * tileWidth, y * tileHeight);
				this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(*t3)));
				//tambahTexture("tile3", new tile(*t3));
				break;
			case 4:
				t4->tileRect.setPosition(x * tileWidth, y * tileHeight);
				this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(*t4)));
				//tambahTexture("tile4", new tile(*t4));
				break;
			case 5:
				t5->tileRect.setPosition(x * tileWidth, y * tileHeight);
				this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(*t5)));
				break;
			case 6:
				a1->body.setPosition(x * tileWidth, y * tileHeight);
				this->manager->tambah(new alien(*a1));
				break;
			case 7:
				v1->body.setPosition(x * tileWidth, y * tileHeight);
				this->manager->tambah(new virus(*v1));
				break;
			default:
				break;
			}
			
				
				//this->tiles.insert(std::make_pair(to_string(x + y*width), new tile(x * tileWidth, y * tileHeight, img,id)));
		
		}
	}

	std::cout << "\nnama file:" << tileSet << endl;
	std::cout << tileWidth << "," << tileHeight << endl;
	std::cout << width << "," << height << endl;

}

void Denah::draw(sf::View* view)
{
	for (auto& i : this->tiles)
	{
		if (i.second->tileRect.getPosition().x > view->getCenter().x - view->getSize().x * 0.6f && i.second->tileRect.getPosition().x < view->getCenter().x + view->getSize().x * 0.6f
			&& i.second->tileRect.getPosition().y > view->getCenter().y - view->getSize().y * 0.6f && i.second->tileRect.getPosition().y < view->getCenter().y + view->getSize().y * 0.6f)
			i.second->draw(*this->window);
	}
}

void Denah::update(sf::View* view)
{
	for (auto& i : this->tiles)
	{
		if (i.second->tileRect.getPosition().x > view->getCenter().x - view->getSize().x * 0.8f && i.second->tileRect.getPosition().x < view->getCenter().x + view->getSize().x * 0.8f
			&& i.second->tileRect.getPosition().y > view->getCenter().y - view->getSize().y * 0.8f && i.second->tileRect.getPosition().y < view->getCenter().y + view->getSize().y * 0.8f)
		{
			if (i.second->getID() >= 2)
			{
				for (int j = 0; j < this->manager->en.size(); j++)
				{
					if (manager->en[j]->getId() == 1)
					{
						if (manager->en[j]->kiri&& manager->en[j]->boundLeft.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()) || manager->en[j]->kanan&& manager->en[j]->boundRight.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()))
						{
							this->manager->en[j]->vel.x = 0;
						}
						else if (manager->en[j]->naik&& manager->en[j]->boundTop.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()) || manager->en[j]->turun&& manager->en[j]->boundBottom.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()))
						{
							this->manager->en[j]->vel.y = 0;
						}
					}
					else if (manager->en[j]->getId() > 1)
					{
						if (manager->en[j]->kiri&& manager->en[j]->boundLeft.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()))
						{
							this->manager->en[j]->vel.x *= -1;
							manager->en[j]->kiri = false;
							manager->en[j]->kanan = true;
						}
						if (manager->en[j]->kanan&& manager->en[j]->boundRight.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()))
						{
							this->manager->en[j]->vel.x *= -1;
							manager->en[j]->kiri = true;
							manager->en[j]->kanan = false;
						}
						else if (manager->en[j]->naik&& manager->en[j]->boundTop.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()) || manager->en[j]->turun&& manager->en[j]->boundBottom.getGlobalBounds().intersects(i.second->tileRect.getGlobalBounds()))
						{
							this->manager->en[j]->vel.y = 0;
						}
					}
				}
			}
		}
	}
}

Denah::~Denah()
{
}

tile Denah::tambahTexture(const std::string nama, tile* t)
{
	{
		auto i = tiles.find(nama);
		if (i != tiles.end())
		{
			std::cout << "sudah ada" << std::endl;
			return *i->second;
		}
		else
		{
			std::cout << "blm ada, loaded -> " << nama << std::endl;

			tiles.insert({ nama, t });
			int h = 0;
			for (auto& i : tiles)
			{
				std::cout << "i1 " << h << i.first << std::endl;
				h++;
			}
			return *t;

		}
	}
}
