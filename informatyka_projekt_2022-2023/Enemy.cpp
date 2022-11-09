#include "Enemy.h"

Enemy::Enemy() {
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	speed = 1;
	shot_damage = 3;
	shot_reload = 2;
	shot_speed = 1.5;
	shot_range = 100;
	this->texture.loadFromFile("Resources/enemy.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

Enemy::Enemy(float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range, std::string imageUrl) {
	x = 0;
	y = 0;
	dx = 0;
	dy = 0;
	this->speed = speed;
	this->shot_damage = shot_damage;
	this->shot_reload = shot_reload;
	this->shot_speed = shot_speed;
	this->shot_range = shot_range;
	this->imageUrl = "Resources/";
	this->imageUrl += imageUrl;
	this->texture.loadFromFile(this->imageUrl);
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Enemy::getSprite() {
	return sprite;
}