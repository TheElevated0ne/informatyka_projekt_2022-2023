#pragma once
#include "Floor.h"
#include "Player.h"
class Dungeon
{
private:
	unsigned int seed;
	std::vector<Floor> floors;
	int current_floor_index;
	std::map<std::string, sf::Texture>* textures;
	sf::RenderWindow* window;
	Player* player;
	std::map<std::tuple<int, int>, Room>* current_map;
public:
	Dungeon(unsigned int seed, int floor_index, std::map<std::string, sf::Texture>* textures, sf::RenderWindow* window, Player* player);
	unsigned int getSeed();
	void drawRoom();
};

