#pragma once

#include <SFML/Graphics.hpp>

class Enemy
{
public:
	Enemy(sf::Texture & texture, sf::Texture & arrowTexture);
	~Enemy();

	sf::Sprite sprite;
	sf::Sprite arrowSprite;

	int x = 0, y = 0;

	sf::Vector2f facingDir;
	sf::Vector2f nextTurnDir;

	void draw(sf::RenderWindow & window, int tileSize);

	void move(int levelSize);
};

