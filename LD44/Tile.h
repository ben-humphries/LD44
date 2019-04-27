#pragma once

#include <SFML/Graphics.hpp>
class Tile
{
public:
	Tile(int x, int y, sf::Texture & texture);
	~Tile();

	sf::Sprite sprite;

	//coord x and y
	int x, y;

	void draw(sf::RenderWindow & window);
};

