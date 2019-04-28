#include "Player.h"



Player::Player(sf::Texture & texture, sf::Texture & flippedTexture)
{
	sprite.setTexture(texture);
	flippedSprite.setTexture(flippedTexture);

	x = 7; y = 7;
}


Player::~Player()
{
}


void Player::draw(sf::RenderWindow & window, int tileSize)
{
	sf::Sprite tSprite = flipped ? flippedSprite : sprite;

	tSprite.setOrigin(tileSize / 2, tileSize / 2);

	tSprite.setPosition(x*tileSize + tileSize / 2, y*tileSize + tileSize / 2);

	if (flipped) tSprite.move(sf::Vector2f(facingDir.x * tileSize, facingDir.y * tileSize));
	
	if (facingDir.x == 1) tSprite.setRotation(180);
	else if (facingDir.x == -1) tSprite.setRotation(0);
	else if (facingDir.y == 1) tSprite.setRotation(270);
	else if (facingDir.y == -1) tSprite.setRotation(90);

	window.draw(tSprite);
}