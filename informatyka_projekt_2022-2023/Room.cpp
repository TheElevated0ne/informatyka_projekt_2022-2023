#include "Room.h"

Room::Room(std::map<std::string, sf::Texture> *textures, sf::RenderWindow* window) {
	this->window = window;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			Tile tempTile(i*128 + 152, j*128 + 80, true, "dirt.png", textures);
			tiles.push_back(tempTile);
		}
	}
}

void Room::drawRoom() {
	for (Tile tile: tiles) {
		window->draw(tile.getSprite());
	}
}