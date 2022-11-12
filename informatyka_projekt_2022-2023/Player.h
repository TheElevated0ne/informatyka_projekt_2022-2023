#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Bullet.h"
#include "Room.h"

class Player {
private:
	float x, y;
	float dx, dy, acc;
	float speed, shot_damage, shot_reload, shot_speed, shot_range;
	std::vector<Bullet> bullets;
	std::vector<sf::Vector2f> forces;
	sf::Texture texture;
	sf::Sprite sprite;
	// CONTROLS --- 0-3 -> movement
	bool controls[4] = {};
public:
	Player();
	Player(float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range);
	sf::Sprite getSprite();
	void handleEvents(sf::Event *event);
	void setPosition(float x, float y);
	void update(float delta);
	void move();
	void addForce(sf::Vector2f force);
	void useForces();
};