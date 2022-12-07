#include "Player.h"

Player::Player(Room* room, std::map<std::string, sf::Texture>* textures) {
	this->room = room;
	this->floor = nullptr;
	this->textures = textures;
	x = 536.f;
	y = 336.f;
	dx = 0.f;
	dy = 0.f;
	acc = 0.15f;
	speed = 6.f;
	shot_damage = 3.f;
	shot_reload = 20.f;
	shot_speed = 1.f;
	shot_range = 100.f;
	this->texture.loadFromFile("Resources/hero.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->sprite.setPosition(sf::Vector2f((float)x, (float)y));
	shot_cooldown.restart();
}

Player::Player(Room* room, std::map<std::string, sf::Texture>* textures, float speed, float shot_damage, float shot_reload, float shot_speed, float shot_range) {
	this->room = room;
	this->floor = nullptr;
	this->textures = textures;
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

// w celu up³ynnienia ruchu, wciœniêcie przycisku raz sprawia ¿e postaæ bêdzie siê porusza³a
// do momentu a¿ przycisk zostanie zwolniony
// klucze dla tablicy controls:
// Ruch:     0 - góra, 1 - lewo, 2 - dó³, 3 - prawo
// Strza³:   4 - góra, 5 - lewo, 6 - dó³, 7 - prawo
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

		if (event->key.code == sf::Keyboard::Up) {
			controls[4] = true;
		}
		if (event->key.code == sf::Keyboard::Left) {
			controls[5] = true;
		}
		if (event->key.code == sf::Keyboard::Down) {
			controls[6] = true;
		}
		if (event->key.code == sf::Keyboard::Right) {
			controls[7] = true;
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
		if (event->key.code == sf::Keyboard::Up) {
			controls[4] = false;
		}
		if (event->key.code == sf::Keyboard::Left) {
			controls[5] = false;
		}
		if (event->key.code == sf::Keyboard::Down) {
			controls[6] = false;
		}
		if (event->key.code == sf::Keyboard::Right) {
			controls[7] = false;
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
	// zmiana ruchu na klatkê zale¿y od czasu pomiêdzy klatkami
	// dziêki temu postaæ porusza siê ze sta³¹ prêdkoœci¹ w czasie
	// bez wzglêdu na iloœæ klatek na sekundê
	// delta to czas pomiêdzy klatkami fizyki
	x += dx * delta / 10;
	y += dy * delta / 10;
	setPosition(x, y);

	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update(delta);
	}

	for (int i = 0; i < bullets.size(); ++i) {
		if (bullets[i].isDestroyed()) {
			bullets.erase(bullets.begin() + i);
		}
	}
}

void Player::move()
{
// Stan wejœæ ruchu zmienia przyspieszenie postaci w danej osi
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

	if (controls[4]) {
		shoot(0.f, -1.f);
	}
	if (controls[5]) {
		shoot(-1.f, 0.f);
	}
	if (controls[6]) {
		shoot(0.f, 1.f);
	}

	if (controls[7]) {
		shoot(1.f, 0.f);
	}


// Sta³y opór dla postaci wykonuj¹cej ruch
// Gdy prêdkoœæ jest dostatecznie ma³a, jej wartoœæ jest ustawiana na zero
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

	// Limit prêdkoœci dotyczy d³ugoœci wektora prêdkoœci, a nie jego wartoœci sk³adowych
	// Dziêki temu prêdkoœæ po skosach jest taka sama jak w poziomie i pionie
	// (w przeciwnym wypadku ruch skosami by³by szybszy)
	float alfa = std::atan2f(dy, dx);
	float max_dx = std::cosf(alfa) * speed;
	float max_dy = std::sinf(alfa) * speed;
	if (std::abs(dx) > std::abs(max_dx)) {
		dx = max_dx;
	}
	if (std::abs(dy) > std::abs(max_dy)) {
		dy = max_dy;
	}
		
	// Dopiero po przeliczeniu ruchu z wejœæ dodawane s¹ si³y zewnêtrzne	
	useForces();
	// Zatrzymywanie siê na œcianach jest na koñcu przeliczania
	// W przeciwnym wypadku postaæ by siê przebija³a
	stopOnEdge();
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

void Player::stopOnEdge()
{
	// Stopping on walls
	if (x < 152.f) {
		x = 152.f;
	}
	if (x + 128.f > 1048.f) {
		x = 1048.f - 128.f;
	}
	if (y < 80.f) {
		y = 80.f;
	}
	if (y + 128.f > 720.f) {
		y = 720.f - 128.f;
	}
	// Operations on tiles
	for (Tile tile : *room->getTiles()) {
		// walking through doors
		float tileX, tileY, tile_width, tile_height;
		tileX = tile.getArea()[0];
		tileY = tile.getArea()[1];
		tile_width = tile.getArea()[2];
		tile_height = tile.getArea()[3];
		if (tile.getDoor() != 4) {
			int door = tile.getDoor();
			if (x < tileX + tile_width + 1.f && x + 128.f > tileX - 1.f) {
				if (y < tileY + tile_height + 1.f && y + 128.f > tileY - 1.f) {
					floor->changeRoomByDoor(door);
					changeRoom(floor->getCurrentRoom());
					if (door == 0) {
						x = 536.f;
						y = 570.f;
					}
					if (door == 1) {
						x = 170.f;
						y = 336.f;
					}
					if (door == 2) {
						x = 536.f;
						y = 90.f;
					}
					if (door == 3) {
						x = 900.f;
						y = 336.f;
					}
				}
			}
		}

		if (!tile.getPass()) {
			// stopping on walls
			if (x < tileX + tile_width && x + 128.f > tileX) {
				if (y < tileY + tile_height && y + 128.f > tileY) {
					if (x < tileX - (128.f - 10.f)) {
						x = tileX - 128.f;
					}
					if (x > tileX + tile_width - 10.f) {
						x = tileX + tile_width;
					}
					if (y < tileY - (128.f - 10.f)) {
						y = tileY - 128.f;
					}
					if (y > tileY + tile_height - 10.f) {
						y = tileY + tile_height;
					}
				}
			}
			// stopping bullets
			float bulletX, bulletY;
			for (int i = 0; i < bullets.size(); i++) {
				bullets[i].getCoords(&bulletX, &bulletY);
				if (bulletX + 20.f > tileX && bulletX < tileX + tile_width) {
					if (bulletY + 20.f > tileY && bulletY < tileY + tile_height) {
						bullets.erase(bullets.begin() + i);
						i -= 1;
					}
				}
			}
		}
	}
}

void Player::shoot(float bdx, float bdy)
{
	if (shot_cooldown.getElapsedTime().asMilliseconds() > (int)shot_reload) {
		bullets.push_back(Bullet(textures, "bullet.png", x + 48.f, y + 48.f, bdx + dx/20.f, bdy + dy/20.f, shot_speed, shot_damage, shot_range, false));
		shot_cooldown.restart();
	}
}

void Player::drawBullets()
{
	for (Bullet bullet : bullets) {
		room->getWindow()->draw(bullet.getSprite());
	}
}

void Player::drawPlayer()
{
	drawBullets();
	room->getWindow()->draw(sprite);
}

void Player::changeRoom(Room* room)
{
	x = 536.f;
	y = 336.f;
	this->room = room;
	bullets.clear();
}

void Player::setFloor(Floor* floor)
{
	this->floor = floor;
}



