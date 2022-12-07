#include "Tile.h"

Tile::Tile()
{
	x = 0.f;
	y = 0.f;
	passable = true;
	door = 4;
	this->direction = 0;
	this->texture.loadFromFile("Resources/dirt.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

Tile::Tile(float x, float y, bool passable, std::string imageUrl, std::map<std::string, sf::Texture> *textures)
{
	this->x = x;
	this->y = y;
	this->passable = passable;
	this->door = 4;
	this->imageUrl = imageUrl;
	this->direction = 0;
	// Jeœli tekstura nie jest jeszcze za³adowana program j¹ ³aduje
	if (textures->count(imageUrl) == 0) {
		this->texture.loadFromFile("Resources/" + imageUrl);
		textures->insert({imageUrl, this->texture});
	}
	this->sprite.setTexture(textures->at(imageUrl));
	this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}

float* Tile::getArea()
{
	float area[4] = {x, y , 128, 128};
	return area;
}

bool Tile::getPass()
{
	return passable;
}

void Tile::setRotation(int direction)
{
	if (direction == 0) {
		this->sprite.setTextureRect(sf::IntRect(0, 0, 256, 256));
	}
	if (direction == 1) {
		this->sprite.setTextureRect(sf::IntRect(256, 0, 256, 256));
	}
	if (direction == 2) {
		this->sprite.setTextureRect(sf::IntRect(768, 0, 256, 256));
	}
	if (direction == 3) {
		this->sprite.setTextureRect(sf::IntRect(512, 0, 256, 256));
	}
}

void Tile::makeDoor(int door)
{
	this->door = door;
}

int Tile::getDoor()
{
	return door;
}
