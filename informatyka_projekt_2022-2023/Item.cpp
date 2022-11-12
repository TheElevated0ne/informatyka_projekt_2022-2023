#include "Item.h"

Item::Item(std::string imageUrl, std::map<std::string, sf::Texture>* textures) {
	this->x = 100;
	this->y = 100;
	this->imageUrl = imageUrl;
	if (textures->count(imageUrl) == 0) {
		this->texture.loadFromFile("Resources/" + imageUrl);
		textures->insert({ imageUrl, this->texture });
	}
	this->sprite.setTexture(textures->at(imageUrl));
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Item::getSprite() {
	return this->sprite;
}