#include "Player.h"



Player::Player(sf::Texture & texture)
{
	sprite.setTexture(texture);
}


Player::~Player()
{
}


void Player::draw(sf::RenderWindow & window, int tileSize)
{
	sprite.setPosition(x*tileSize, y*tileSize);
	window.draw(sprite);
}