#include "Player.h"



Player::Player(sf::Texture & texture)
{
	sprite.setTexture(texture);
	x = 7; y = 7;
}


Player::~Player()
{
}


void Player::draw(sf::RenderWindow & window, int tileSize)
{
	sprite.setOrigin(tileSize / 2, tileSize / 2);

	sprite.setPosition(x*tileSize + tileSize / 2, y*tileSize + tileSize / 2);
	
	if (facingDir.x == 1) sprite.setRotation(180);
	else if (facingDir.x == -1) sprite.setRotation(0);
	else if (facingDir.y == 1) sprite.setRotation(270);
	else if (facingDir.y == -1) sprite.setRotation(90);

	window.draw(sprite);
}