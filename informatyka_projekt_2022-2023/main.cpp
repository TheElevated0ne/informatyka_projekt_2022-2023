#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Floor.h"
#include "Item.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Projekt");
	sf::Clock zegar;
	float delta = 5.f;
	std::map<std::string, sf::Texture> tekstury;
	Player gracz;
	Enemy wrog;
	Item hotdog("hotdog.png", &tekstury);
	Room pokoj(&tekstury, &window);

	sf::Texture bgTexture;
	bgTexture.loadFromFile("Resources/Cave.png");
	sf::Sprite background(bgTexture);

	while (window.isOpen())
	{
		zegar.restart();
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			gracz.handleEvents(&event);
		}

		gracz.update(delta);
		
		window.clear();
		window.draw(background);
		pokoj.drawRoom();
		window.draw(hotdog.getSprite());
		window.draw(gracz.getSprite());
		window.draw(wrog.getSprite());
		window.display();
		delta = zegar.getElapsedTime().asMilliseconds();
	}
}