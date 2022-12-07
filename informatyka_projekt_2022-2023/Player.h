#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <cmath>
#include "Bullet.h"
#include "Room.h"
#include "Floor.h"

class Player {
private:
	float x, y;
	float dx, dy, acc;
	float speed, shot_damage, shot_reload, shot_speed, shot_range;
	std::vector<Bullet> bullets;
	std::vector<sf::Vector2f> forces;
	std::map<std::string, sf::Texture>* textures;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Clock shot_cooldown;
	Room* room;
	Floor* floor;
	// CONTROLS --- 0-3 -> movement, 4-7 -> shooting
	bool controls[8] = {};
public:
	Player(Room* room, std::map<std::string, sf::Texture>* textures);
	Player(Room* room, std::map<std::string, sf::Texture>* textures,  float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range);
	sf::Sprite getSprite();
	void handleEvents(sf::Event *event);
	void setPosition(float x, float y);
	void update(float delta);
	void move();
	void addForce(sf::Vector2f force);
	void useForces();
	void stopOnEdge();
	void shoot(float bdx, float bdy);
	void drawBullets();
	void drawPlayer();
	void changeRoom(Room* room);
	void setFloor(Floor* floor);
};