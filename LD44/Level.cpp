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

	tileWidth = tileTexture.getSize().x;
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

	player->draw(window, tileWidth);
}

void Level::movePlayer(int x, int y)
{
	player->x += x;
	player->y += y;

	if (player->x > width - 1) player->x = width - 1;
	if (player->y > height - 1) player->y = height - 1;

	if (player->x < 0) player->x = 0;
	if (player->y < 0) player->y = 0;

	player->facingDir.x = 0;
	player->facingDir.y = 0;

	player->facingDir.x = x;
	player->facingDir.y = y;

	printf("%f   %f\n", player->facingDir.x, player->facingDir.y);
	printf("%d   %d\n", player->x, player->y);
}
