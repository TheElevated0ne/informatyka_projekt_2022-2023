#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Bullet.h"

class Enemy {
private:
	int x, y;
	float dx, dy;
	float speed, shot_damage, shot_reload, shot_speed, shot_range;
	std::string imageUrl;
	std::vector<Bullet> bullets;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Enemy();
	Enemy(float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range, std::string imageUrl);
	sf::Sprite getSprite();
};