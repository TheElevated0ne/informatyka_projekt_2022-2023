#pragma once
#include "Enemy.h"
#include "Tile.h"
#include "Item.h"

class Room
{
private:
	std::vector<Tile> tiles;
	std::vector<Enemy> enemies;
	std::vector<Item> items;
	sf::RenderWindow* window;
public:
	Room(std::map<std::string, sf::Texture> *textures, sf::RenderWindow* window);
	void drawRoom();
};

