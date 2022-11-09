#pragma once

class Bullet {
private:
	int x, y;
	float dx, dy;
	float speed, damage, range;
	bool hostile;
public:
	Bullet(int x, int y, float dx, float dy, float speed, float damage, float range, bool hostile);
};