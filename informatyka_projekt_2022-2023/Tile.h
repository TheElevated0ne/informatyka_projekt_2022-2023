#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class Tile
{
private:
	int x, y;
	bool passable;
	std::string imageUrl;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Tile();
	Tile(int x, int y, bool passable, std::string imageUrl, std::map<std::string, sf::Texture> *textures);
	sf::Sprite getSprite();
};
