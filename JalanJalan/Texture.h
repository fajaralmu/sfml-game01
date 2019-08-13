#pragma once
#include <memory>
#include <unordered_map>
#include <SFML\Graphics.hpp>
#include <iostream>

class TextureMap {
public:
	sf::Texture tambahTexture(const std::string nama)
	{
		auto i = textureMap.find(nama);
		if (i != textureMap.end())
		{
			std::cout << "sudah ada" << std::endl;
			return i->second;
		}
		else
		{
			auto j = new sf::Texture;
			j->loadFromFile(nama);
			std::cout << "blm ada, loaded -> " <<nama << std::endl;

			textureMap.insert({ nama, *j });
			int h = 0;
			for (auto& i : textureMap)
			{
				
				std::cout << "i1 " << h << i.first << std::endl;
				h++;
			}
			return *j;

		}
	}

private:
	std::unordered_map<std::string, sf::Texture> textureMap;
};
