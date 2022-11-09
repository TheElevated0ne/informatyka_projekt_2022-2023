#include "Bullet.h"

Bullet::Bullet(int x, int y, float dx, float dy, float speed, float damage, float range, bool hostile) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->speed = speed;
	this->damage = damage;
	this->range = range;
	this->hostile = hostile;
}
