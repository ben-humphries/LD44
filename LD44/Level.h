#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Tile.h"
#include "Player.h"
#include "Enemy.h"

#include "util.h"

class Level
{
public:
	Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture,
		sf::Texture & flippedTexture, sf::Texture & enemyTexture, sf::Texture & arrowTexture,
		sf::Texture & lineTexture, sf::Texture & bloodTexture, sf::Texture &moneyHolderTexture);
	~Level();

	sf::Font font;
	sf::Text score;
	sf::Text text;

	int scoreNum = 0;

	int width, height;

	std::vector<Tile> tiles;
	int tileWidth;

	Player * player;
	std::vector<Enemy *> enemies;

	void draw(sf::RenderWindow & window);

	void nextTurn(sf::RenderWindow & window);

	void update(sf::RenderWindow & window);

	void movePlayer(int x, int y, sf::RenderWindow & window, bool faceOnly = false);
	void flipPlayer(sf::RenderWindow & window);

	void reset(int num);

	int enemyNumber = 1;

	sf::Texture & enemyTexture, &arrowTexture, &lineTexture, &bloodTexture, &moneyHolderTexture;

	sf::SoundBuffer splatBuffer;
	sf::Sound splatSound;

	sf::SoundBuffer thumpBuffer;
	sf::Sound thumpSound;

private:
	void checkLOS(sf::RenderWindow & window);
};

