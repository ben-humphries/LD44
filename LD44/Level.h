#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Player.h"
#include "Enemy.h"

#include "util.h"

class Level
{
public:
	Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture, sf::Texture & enemyTexture, sf::Texture & arrowTexture, sf::Texture & lineTexture);
	~Level();


	int width, height;

	std::vector<Tile> tiles;
	int tileWidth;

	Player * player;
	std::vector<Enemy *> enemies;

	void draw(sf::RenderWindow & window);

	void update();

	void movePlayer(int x, int y, sf::RenderWindow & window);

};

