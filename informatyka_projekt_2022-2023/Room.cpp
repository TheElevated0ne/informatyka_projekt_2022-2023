#include "Room.h"

Room::Room()
{
	seed = 2137;
}

Room::Room(unsigned int seed, std::map<std::string, sf::Texture> *textures, sf::RenderWindow* window) {
	this->window = window;
	this->seed = seed;
	std::mt19937 gen(seed);
	std::uniform_int_distribution<> dist(1, 20);
	int temp_num;
	// Zape³nia pokój kafelkami
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			temp_num = dist(gen);
			if (!((i == 0 && j == 2) || (i == 7 && j == 2) || (i == 3 && j == 0) || (i == 3 && j == 5))) {
				if (temp_num <= 1) {
					Tile tempTile((float)i * 128.f + 152.f, (float)j * 128.f + 80.f, false, "block.png", textures);
					tiles.push_back(tempTile);
				}
				else {
					Tile tempTile((float)i * 128.f + 152.f, (float)j * 128.f + 80.f, true, "dirt.png", textures);
					tiles.push_back(tempTile);
				}
			}
			else {
				Tile tempTile((float)i * 128.f + 152.f, (float)j * 128.f + 80.f, true, "dirt.png", textures);
				tiles.push_back(tempTile);
			}
		}
	}
}

void Room::drawRoom() {
	for (Tile tile: tiles) {
		window->draw(tile.getSprite());
	}
}

std::vector<Tile>* Room::getTiles()
{
	return &tiles;
}

sf::RenderWindow* Room::getWindow()
{
	return window;
}

void Room::addTile(Tile tile)
{
	tiles.push_back(tile);
}
