#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(sf::Texture & texture, sf::Texture & flippedTexture);
	~Player();

	sf::Sprite sprite;
	sf::Sprite flippedSprite;

	int x = 0, y = 0;

	bool flipped = false;

	sf::Vector2f facingDir;

	void draw(sf::RenderWindow & window, int tileSize);
};

