#include "Tile.h"



Tile::Tile(int x, int y, sf::Texture & texture)
{
	this->x = x;
	this->y = y;
	sprite.setTexture(texture);
}


Tile::~Tile()
{
}

void Tile::draw(sf::RenderWindow & window)
{
	sprite.setPosition(sf::Vector2f(x*sprite.getGlobalBounds().width, y*sprite.getGlobalBounds().height));
	window.draw(sprite);
}
