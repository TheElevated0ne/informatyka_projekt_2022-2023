#include <SFML/Graphics.hpp>

#include "Bullet.h"
#include "Player.h"
#include "Enemy.h"
#include "Floor.h"
#include "Item.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "Projekt");
	sf::Clock zegar;
	std::map<std::string, sf::Texture> tekstury;
	Player gracz;
	Enemy wrog;
	Item hotdog("hotdog.png");
	Room pokoj(&tekstury);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		pokoj.drawRoom(&window);
		window.draw(hotdog.getSprite());
		window.draw(gracz.getSprite());
		window.draw(wrog.getSprite());
		window.display();
	}
}