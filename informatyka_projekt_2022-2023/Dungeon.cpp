#include "Dungeon.h"

Dungeon::Dungeon(unsigned int seed, int floor_index, std::map<std::string, sf::Texture>* textures, sf::RenderWindow* window, Player* player)
{
	this->textures = textures;
	this->window = window;
	this->seed = seed;
	this->current_floor_index = floor_index;
	for (int i = 0; i < 4; i++) {
		floors.push_back(Floor(seed+i*1000, textures, window));
	}
	this->player = player;
	this->current_map = this->floors[floor_index].getMap();
	this->player->setFloor(&floors[floor_index]);
	this->player->changeRoom(this->floors[floor_index].getCurrentRoom());
}

unsigned int Dungeon::getSeed()
{
	return seed;
}

void Dungeon::drawRoom()
{
	floors[current_floor_index].getCurrentRoom()->drawRoom();
}
