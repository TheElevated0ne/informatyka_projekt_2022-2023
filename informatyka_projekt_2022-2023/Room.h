#pragma once
#include "Enemy.h"
#include "Tile.h"
#include "Item.h"
#include <random>

class Room
{
private:
	unsigned int seed;
	std::vector<Tile> tiles;
	std::vector<Enemy> enemies;
	std::vector<Item> items;
	sf::RenderWindow* window;
public:
	Room();
	Room(unsigned int seed, std::map<std::string, sf::Texture> *textures, sf::RenderWindow* window);
	void drawRoom();
	std::vector<Tile>* getTiles();
	sf::RenderWindow* getWindow();
	void addTile(Tile tile);
};

