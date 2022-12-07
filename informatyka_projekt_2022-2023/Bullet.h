#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

class Bullet {
private:
	float x, y;
	float dx, dy;
	float speed, damage, range;
	bool hostile, destroy;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Bullet(std::map<std::string, sf::Texture>* textures, std::string imageUrl, int x, int y, float dx, float dy, float speed, float damage, float range, bool hostile);
	sf::Sprite getSprite();
	void update(float delta);
	void move();
	bool isDestroyed();
	void getCoords(float* x, float* y);
	void kill();
};