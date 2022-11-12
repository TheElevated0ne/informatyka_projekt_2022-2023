#pragma once
#include <SFML/Graphics.hpp>
#include <string>
class Item
{
private:
	std::string imageUrl;
	int x;
	int y;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Item(std::string imageUrl, std::map<std::string, sf::Texture>* textures);
	sf::Sprite getSprite();
};

