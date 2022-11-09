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
public:
	Room(std::map<std::string, sf::Texture> *textures);
	void drawRoom(sf::RenderWindow *window);
};

