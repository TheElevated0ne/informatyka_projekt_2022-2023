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
	Item(std::string image);
	sf::Sprite getSprite();
};

