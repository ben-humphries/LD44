#pragma once

#include <SFML/Graphics.hpp>

#include "Tile.h"
#include "Player.h"
#include "Enemy.h"

#include "util.h"

class Level
{
public:
	Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture,
		sf::Texture & flippedTexture, sf::Texture & enemyTexture, sf::Texture & arrowTexture,
		sf::Texture & lineTexture, sf::Texture & bloodTexture);
	~Level();

	sf::Font font;
	sf::Text score;

	int scoreNum = 0;

	int width, height;

	std::vector<Tile> tiles;
	int tileWidth;

	Player * player;
	std::vector<Enemy *> enemies;

	void draw(sf::RenderWindow & window);

	void nextTurn(sf::RenderWindow & window);

	void update();

	void movePlayer(int x, int y, sf::RenderWindow & window, bool faceOnly = false);
	void flipPlayer();

};

