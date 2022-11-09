#include "Tile.h"

Tile::Tile()
{
	x = 0;
	y = 0;
	passable = true;
	this->texture.loadFromFile("Resources/dirt.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

Tile::Tile(int x, int y, bool passable, std::string imageUrl, std::map<std::string, sf::Texture> *textures)
{
	this->x = x;
	this->y = y;
	this->passable = passable;
	this->imageUrl = imageUrl;
	if (textures->count(imageUrl) == 0) {
		this->texture.loadFromFile("Resources/" + imageUrl);
		textures->insert({imageUrl, this->texture});
	}
	this->sprite.setTexture(textures->at(imageUrl));
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Tile::getSprite()
{
	return sprite;
}
