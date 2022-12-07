#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <iostream>
class Tile
{
private:
	float x, y;
	bool passable;
	std::string imageUrl;
	sf::Texture texture;
	sf::Sprite sprite;
	// 0 - top, 1 - right, 2 - bottom, 3 - left, 4 - none
	int direction, door;

public:
	Tile();
	Tile(float x, float y, bool passable, std::string imageUrl, std::map<std::string, sf::Texture> *textures);
	sf::Sprite getSprite();
	float* getArea();
	bool getPass();
	void setRotation(int direction);
	void makeDoor(int door);
	int getDoor();
};
