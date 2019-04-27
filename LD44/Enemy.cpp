#include "Enemy.h"



Enemy::Enemy(sf::Texture & texture, sf::Texture & arrowTexture, sf::Texture & lineTexture)
{
	sprite.setTexture(texture);
	arrowSprite.setTexture(arrowTexture);
	lineSprite.setTexture(lineTexture);


	int random = rand() % 4;

	nextTurnDir = sf::Vector2f(0, 0);

	if (random == 0) nextTurnDir.x = 1;
	else if (random == 1) nextTurnDir.x = -1;
	else if (random == 2) nextTurnDir.y = 1;
	else if (random == 3) nextTurnDir.y = -1;

	facingDir = sf::Vector2f(0, -1);
}


Enemy::~Enemy()
{
}

void Enemy::draw(sf::RenderWindow & window, int tileSize)
{
	sprite.setOrigin(tileSize / 2, tileSize / 2);
	arrowSprite.setOrigin(tileSize / 2, tileSize / 2);
	lineSprite.setOrigin(tileSize / 2, tileSize / 2);

	sprite.setPosition(x*tileSize + tileSize / 2, y*tileSize + tileSize / 2);
	arrowSprite.setPosition(x*tileSize + tileSize / 2, y*tileSize + tileSize / 2);
	lineSprite.setPosition(x*tileSize + tileSize / 2, y*tileSize + tileSize / 2);

	if (facingDir.x == 1) sprite.setRotation(90);
	else if (facingDir.x == -1) sprite.setRotation(270);
	else if (facingDir.y == 1) sprite.setRotation(180);
	else if (facingDir.y == -1) sprite.setRotation(0);

	if (nextTurnDir.x == 1) arrowSprite.setRotation(90);
	else if (nextTurnDir.x == -1) arrowSprite.setRotation(270);
	else if (nextTurnDir.y == 1) arrowSprite.setRotation(180);
	else if (nextTurnDir.y == -1) arrowSprite.setRotation(0);

	if (facingDir.x != 0) lineSprite.setRotation(90);
	else lineSprite.setRotation(0);

	for (int i = 0; i < 3; i++) {
		lineSprite.move(sf::Vector2f(facingDir.x * tileSize, facingDir.y*tileSize));
		window.draw(lineSprite);
	}

	window.draw(arrowSprite);
	window.draw(sprite);
}

void Enemy::move(int levelSize)
{
	int random = rand() % 4;

	facingDir = nextTurnDir;

	nextTurnDir = sf::Vector2f(0, 0);

	if (random == 0) nextTurnDir.x = 1;
	else if (random == 1) nextTurnDir.x = -1;
	else if (random == 2) nextTurnDir.y = 1;
	else if (random == 3) nextTurnDir.y = -1;

	x += facingDir.x;
	y += facingDir.y;

	if (x > levelSize - 1) x = levelSize - 1;
	if (y > levelSize - 1) y = levelSize - 1;

	if (x < 0) x = 0;
	if (y < 0) y = 0;
}
