#include <SFML/Graphics.hpp>

#include "Level.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "LD44");

	sf::Texture tileTex;
	if (!tileTex.loadFromFile("res/tile.png")) {
		printf("Error loading tile texture.");
	}
	Level l1 = Level(3, 4, tileTex);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		l1.draw(window);
		window.display();
	}

	return 0;
}