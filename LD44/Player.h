#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Texture & texture);
	~Player();

	sf::Sprite sprite;

	int x = 0, y = 0;

	void draw(sf::RenderWindow & window, int tileSize);
};

