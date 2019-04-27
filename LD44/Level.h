#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Player.h"

class Level
{
public:
	Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture);
	~Level();

	int width, height;

	std::vector<Tile> tiles;

	Player * player;

	void draw(sf::RenderWindow & window);
};

