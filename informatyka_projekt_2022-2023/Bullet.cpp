#include "Bullet.h"

Bullet::Bullet(std::map<std::string, sf::Texture>* textures, std::string imageUrl, int x, int y, float dx, float dy, float speed, float damage, float range, bool hostile) {
	this->x = (float)x;
	this->y = (float)y;
	this->dx = dx;
	this->dy = dy;
	this->speed = speed;
	this->damage = damage;
	this->range = range;
	this->hostile = hostile;
	this->destroy = false;
	if (textures->count(imageUrl) == 0) {
		this->texture.loadFromFile("Resources/" + imageUrl);
		textures->insert({ imageUrl, this->texture });
	}
	this->sprite.setTexture(textures->at(imageUrl));
	this->sprite.setPosition(x, y);
}

sf::Sprite Bullet::getSprite()
{
	return sprite;
}

void Bullet::update(float delta)
{
	move();
	x += dx * speed * delta;
	y += dy * speed * delta;
	this->sprite.setPosition(x, y);

	if (x < 152.f) {
		destroy = true;
	}
	if (x + 32.f > 1048.f) {
		destroy = true;
	}
	if (y < 80.f) {
		destroy = true;
	}
	if (y + 32.f > 720.f) {
		destroy = true;
	}
}

void Bullet::move()
{

}

bool Bullet::isDestroyed()
{
	return destroy;
}

void Bullet::getCoords(float* x, float* y)
{
	*x = this->x;
	*y = this->y;
}

void Bullet::kill()
{
	this->destroy = true;
}
