#include <SFML/Graphics.hpp>

#include "Level.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "LD44");
	window.setKeyRepeatEnabled(false);

	sf::Texture tileTex;
	if (!tileTex.loadFromFile("res/tile.png")) {
		printf("Error loading tile texture.");
	}
	sf::Texture playerTex;
	if (!playerTex.loadFromFile("res/player.png")) {
		printf("Error loading player texture.");
	}

	Level l1 = Level(3, 4, tileTex, playerTex);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::Up)
				{
					l1.movePlayer(0, -1);
				}
				else if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::Left)
				{
					l1.movePlayer(-1, 0);
				}
				else if (event.key.code == sf::Keyboard::S || event.key.code == sf::Keyboard::Down)
				{
					l1.movePlayer(0, 1);
				}
				else if (event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::Right)
				{
					l1.movePlayer(1, 0);
				}
			}
		}

		window.clear();
		l1.draw(window);
		window.display();
	}

	return 0;
}