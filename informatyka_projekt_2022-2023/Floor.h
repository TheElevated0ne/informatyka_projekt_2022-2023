#pragma once
#include <random>
#include "Room.h"
#include <tuple>
class Floor
{
private:
	unsigned int seed;
	std::vector<Room> rooms;
	std::map<std::tuple<int, int>, Room> map;
	std::map<std::string, sf::Texture>* textures;
	sf::RenderWindow* window;
	std::tuple<int, int> currentPosition;
public:
	Floor(unsigned int seed, std::map<std::string, sf::Texture>* textures, sf::RenderWindow* window);
	void generateFloor();
	std::map<std::tuple<int, int>, Room>* getMap();
	Room* getCurrentRoom();
	void changeRoomByDoor(int door);
};


