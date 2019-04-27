#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"

class Level
{
public:
	Level(int width, int height, sf::Texture & tileTexture);
	~Level();

	int width, height;

	std::vector<Tile> tiles;

	void draw(sf::RenderWindow & window);
};

