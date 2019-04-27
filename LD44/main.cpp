#include <SFML/Graphics.hpp>

#include "Level.h"

int main()
{
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 800), "LD44");
	window.setKeyRepeatEnabled(false);

	sf::View view;
	view.zoom(0.5);
	view.setCenter(4*50, 4*50);
	window.setView(view);

	sf::Texture tileTex;
	if (!tileTex.loadFromFile("res/tile.png")) {
		printf("Error loading tile texture.\n");
	}
	sf::Texture playerTex;
	if (!playerTex.loadFromFile("res/player.png")) {
		printf("Error loading player texture.\n");
	}
	sf::Texture enemyTex;
	if (!enemyTex.loadFromFile("res/enemy.png")) {
		printf("Error loading enemy texture.\n");
	}
	sf::Texture arrowTex;
	if (!arrowTex.loadFromFile("res/arrow.png")) {
		printf("Error loading arrow texture.\n");
	}

	Level l1 = Level(8, 8, tileTex, playerTex, enemyTex, arrowTex);

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

		window.clear(sf::Color(40, 127, 50));
		l1.draw(window);
		window.display();
	}

	return 0;
}