#include "Item.h"

Item::Item(std::string image) {
	this->x = 100;
	this->y = 100;
	this->imageUrl = "Resources/";
	this->imageUrl += image;
	this->texture.loadFromFile(this->imageUrl);
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Item::getSprite() {
	return this->sprite;
}