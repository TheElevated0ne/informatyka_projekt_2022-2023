#include "Room.h"

Room::Room(std::map<std::string, sf::Texture> *textures) {
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 5; j++) {
			Tile tempTile(i*128, j*128, true, "dirt.png", textures);
			tiles.push_back(tempTile);
		}
	}
}

void Room::drawRoom(sf::RenderWindow *window) {
	for (Tile tile: tiles) {
		window->draw(tile.getSprite());
	}
}