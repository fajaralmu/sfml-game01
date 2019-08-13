#pragma once
#include <SFML\Graphics.hpp>
class tile: public sf::Sprite

{
public: 
	tile(float x, float y, sf::Image img, int ID);
	void update();
	void draw(sf::RenderWindow &window);
	void setImage(sf::Image img);
	void setId(int ID);
	int getID();
	~tile();
	sf::Texture texture;
	sf::RectangleShape tileRect;
	
private:
	float row;
	int ID;
	sf::Image image;
	sf::Vector2u ukuranTexture;
	sf::IntRect uvRect;
	sf::RenderWindow* window;
	float x, y;
};

