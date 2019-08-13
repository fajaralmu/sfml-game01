#include <iostream>
#include "SFML\Graphics.hpp"
#include "SFML\Window.hpp"
#include "SFML\System.hpp"
#include <vector>
#include <cstdlib>
#include "player.h"
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Denah.h"
#include "peluru.h"
#include "alien.h"
#include "pengatur_entitas.h"
#include "Texture.h"

using namespace std;
using namespace sf;

int main()
{
	sf::View view;
	TextureMap tx;

	sf::RenderWindow window(sf::VideoMode(640, 384), "Shooting Simple");
	window.setFramerateLimit(60);

	
	pengatur_entitas manager(&window);
	player player(&manager, window, window.getSize().x / 2, window.getSize().y / 2, &tx);

	manager.tambah(&player);

	Denah denah(window, &manager, "maps.txt",&tx );

	sf::RectangleShape bg;
	bg.setSize(sf::Vector2f(3200, 640));

	sf::Texture bgTx;
	bgTx.loadFromFile("bg.jpg");
	bgTx.setRepeated(true);

	bg.setTexture(&bgTx);

	
	view.reset(sf::FloatRect(player.body.getPosition().x - view.getSize().x / 2, player.body.getPosition().y - view.getSize().y / 2, window.getSize().x, window.getSize().y));

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		//view
		//bg.setPosition(player.body.getPosition().x - view.getSize().x / 2, player.body.getPosition().y - view.getSize().y / 2);
		if (player.body.getPosition().x - window.getSize().x / 2 <= 0)
		{
			view.setCenter(Vector2f(window.getSize().x / 2, player.body.getPosition().y));
		}
		else if (player.body.getPosition().x + window.getSize().x / 2 >= bg.getGlobalBounds().width)
		{
			view.setCenter(Vector2f(bg.getGlobalBounds().width - window.getSize().x / 2, player.body.getPosition().y));
		}
		else  if (player.body.getPosition().y - window.getSize().y / 2 <= 0)
		{
			view.setCenter(Vector2f(player.body.getPosition().x, window.getSize().y / 2));
		}
		else if (player.body.getPosition().y + window.getSize().y / 2 >= bg.getGlobalBounds().height)
		{
			view.setCenter(Vector2f(player.body.getPosition().x, bg.getGlobalBounds().height - window.getSize().y / 2));
		}
		else
			view.setCenter(Vector2f(player.body.getPosition().x, player.body.getPosition().y));

		//
		if (player.body.getPosition().x + window.getSize().x / 2 >= bg.getGlobalBounds().width && player.body.getPosition().y - window.getSize().y / 2 <= 0)
		{
			view.setCenter(Vector2f(bg.getGlobalBounds().width - window.getSize().x / 2, window.getSize().y / 2));
		}

		if (player.body.getPosition().x + window.getSize().x / 2 >= bg.getGlobalBounds().width && player.body.getPosition().y + window.getSize().y / 2 >= bg.getGlobalBounds().height)
		{
			view.setCenter(Vector2f(bg.getGlobalBounds().width - window.getSize().x / 2, bg.getGlobalBounds().height - window.getSize().y / 2));
		}

		if (player.body.getPosition().x - window.getSize().x / 2 <= 0 && player.body.getPosition().y - window.getSize().y / 2 <= 0)
		{
			view.setCenter(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
		}

		if (player.body.getPosition().x - window.getSize().x / 2 <= 0 && player.body.getPosition().y + window.getSize().y / 2 >= bg.getGlobalBounds().height)
		{
			view.setCenter(Vector2f(window.getSize().x / 2, bg.getGlobalBounds().height - window.getSize().y / 2));
		}

		window.setView(view);

		//Update
		manager.update(&view);
		denah.update(&view);

		//Draw
		window.clear(sf::Color::White);
	window.draw(bg);
		denah.draw(&view);

		manager.draw(&view);
		window.display();
	}
	return 0;
}
