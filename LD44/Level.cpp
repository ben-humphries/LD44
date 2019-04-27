#include "Level.h"


Level::Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture)
{
	this->width = width;
	this->height = height;

	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			tiles.push_back(Tile(x, y, tileTexture));
		}
	}

	player = new Player(playerTexture);
}

Level::~Level()
{
}

void Level::draw(sf::RenderWindow & window)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			tiles.at(x + y * width).draw(window);
		}
	}

	player->draw(window, width);
}
