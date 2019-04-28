#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::Texture & texture, sf::Texture & arrowTexture, sf::Texture & lineTexture, sf::Texture & bloodTexture);
	~Enemy();

	sf::Sprite sprite;
	sf::Sprite arrowSprite;
	sf::Sprite lineSprite;
	sf::Sprite bloodSprite;

	int x = 0, y = 0;

	sf::Vector2f facingDir;
	sf::Vector2f nextTurnDir;

	bool alive = true;

	sf::Vector2f deathDirection;

	void draw(sf::RenderWindow & window, int tileSize);

	void move(int levelSize, int playerX, int playerY);
};

