#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Player {
private:
	int x, y;
	float dx, dy;
	float speed, shot_damage, shot_reload, shot_speed, shot_range;
	std::vector<Bullet> bullets;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Player();
	Player(float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range);
	sf::Sprite getSprite();
};