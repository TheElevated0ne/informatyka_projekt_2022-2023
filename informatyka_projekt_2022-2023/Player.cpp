#include "Player.h"

Player::Player() {
	x = 536.f;
	y = 336.f;
	dx = 0.f;
	dy = 0.f;
	acc = 0.15f;
	speed = 6.f;
	shot_damage = 3.f;
	shot_reload = 2.f;
	shot_speed = 1.5f;
	shot_range = 100.f;
	this->texture.loadFromFile("Resources/hero.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

Player::Player(float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range) {
	x = 536.f;
	y = 336.f;
	dx = 0.f;
	dy = 0.f;
	acc = 0.2f;
	this->speed = speed;
	this->shot_damage = shot_damage;
	this->shot_reload = shot_reload;
	this->shot_speed = shot_speed;
	this->shot_range = shot_range;
	this->texture.loadFromFile("Resources/hero.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
}

sf::Sprite Player::getSprite() {
	return sprite;
}

void Player::handleEvents(sf::Event* event)
{
	if (event->type == sf::Event::KeyPressed) {
		
		if (event->key.code == sf::Keyboard::W) {
			controls[0] = true;
		}
		if (event->key.code == sf::Keyboard::A) {
			controls[1] = true;
		}
		if (event->key.code == sf::Keyboard::S) {
			controls[2] = true;
		}
		if (event->key.code == sf::Keyboard::D) {
			controls[3] = true;
		}
	}
	if (event->type == sf::Event::KeyReleased) {

		if (event->key.code == sf::Keyboard::W) {
			controls[0] = false;
		}
		if (event->key.code == sf::Keyboard::A) {
			controls[1] = false;
		}
		if (event->key.code == sf::Keyboard::S) {
			controls[2] = false;
		}
		if (event->key.code == sf::Keyboard::D) {
			controls[3] = false;
		}
	}
}

void Player::setPosition(float x, float y)
{
	this->x = x;
	this->y = y;
	this->sprite.setPosition(this->x, this->y);
}

void Player::update(float delta)
{
	move();
	x += dx * delta / 10;
	y += dy * delta / 10;
	setPosition(x, y);
}

void Player::move()
{
// Up
	if (controls[0]) {
		dy -= acc;
	}
// Left
	if (controls[1]) {
		dx -= acc;
	}
// Down
	if (controls[2]) {
		dy += acc;
	}
// Right
	if (controls[3]) {
		dx += acc;
	}

// Slowing down
	if (dx > 0) {
		if (dx < acc * 0.5f) {
			dx = 0;
		}
		else {
			dx -= acc * 0.5f;
		}
	}
	if (dx < 0) {
		if (dx > -acc * 0.5f) {
			dx = 0;
		}
		else {
			dx += acc * 0.5f;
		}
	}
	if (dy > 0) {
		if (dy < acc * 0.5f) {
			dy = 0;
		}
		else {
			dy -= acc * 0.5f;
		}
	}
	if (dy < 0) {
		if (dy > -acc * 0.5f) {
			dy = 0;
		}
		else {
			dy += acc * 0.5f;
		}
	}

	float alfa = std::atan2f(dy, dx);
	float max_dx = std::cosf(alfa) * speed;
	float max_dy = std::sinf(alfa) * speed;
	if (std::abs(dx) > std::abs(max_dx)) {
		dx = max_dx;
	}
	if (std::abs(dy) > std::abs(max_dy)) {
		dy = max_dy;
	}
		
	useForces();
}

void Player::addForce(sf::Vector2f force)
{
	forces.push_back(force);
}

void Player::useForces()
{
	for (sf::Vector2f force : forces) {
		dx += force.x;
		dy += force.y;
	}
	forces.clear();
}


