#include "util.h"


void sleep123(sf::RenderWindow & window, float seconds) {

	sf::Clock clock;

	float total = 0;

	while (seconds > total)
	{
		float dt = clock.restart().asSeconds();
		total += dt;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	}
}
