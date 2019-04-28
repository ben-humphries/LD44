#include "Level.h"

Level::Level(int width, int height, sf::Texture & tileTexture, sf::Texture & playerTexture,
	sf::Texture & flippedTexture, sf::Texture & enemyTexture, sf::Texture & arrowTexture,
	sf::Texture & lineTexture, sf::Texture & bloodTexture, sf::Texture & moneyHolderTexture)
{
	this->width = width;
	this->height = height;

	
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			tiles.push_back(Tile(x, y, tileTexture));
		}
	}

	player = new Player(playerTexture, flippedTexture);

	tileWidth = tileTexture.getSize().x;

	for (int i = 0; i < 2; i++) {
		Enemy * enemy = new Enemy(enemyTexture, arrowTexture, lineTexture, bloodTexture, false);
		enemies.push_back(enemy);
	}

	Enemy * enemy = new Enemy(moneyHolderTexture, arrowTexture, lineTexture, bloodTexture, true);
	enemies.push_back(enemy);


	if (!font.loadFromFile("res/SFPixelate.ttf")) {
		printf("Couldn't load font\n");
	}
	score.setFont(font);
	score.setString("$$$$$: 0");
	score.setPosition(0, -50);

	text.setFont(font);
	text.setPosition(-50, 50 * 8);
	text.setCharacterSize(27);
}

Level::~Level()
{
}

void Level::draw(sf::RenderWindow & window)
{
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			tiles.at(x + y * width).draw(window);
		}
	}

	for (auto enemy : enemies)
	{
		enemy->draw(window, tileWidth);
	}

	player->draw(window, tileWidth);

	window.draw(score);
	window.draw(text);
}

void Level::movePlayer(int x, int y, sf::RenderWindow & window, bool faceOnly)
{
	for (auto enemy : enemies)
	{
		int tx = x + player->x;
		int ty = y + player->y;

		if (tx == enemy->x && ty == enemy->y && enemy->alive) {
			faceOnly = true;
		}
	}
	if (!faceOnly) {
		player->x += x;
		player->y += y;

		if (player->x > width - 1) player->x = width - 1;
		if (player->y > height - 1) player->y = height - 1;

		if (player->x < 0) player->x = 0;
		if (player->y < 0) player->y = 0;
	}

	player->facingDir.x = 0;
	player->facingDir.y = 0;

	player->facingDir.x = x;
	player->facingDir.y = y;

	//printf("%f   %f\n", player->facingDir.x, player->facingDir.y);
	//printf("%d   %d\n", player->x, player->y);

	nextTurn(window);
}

void Level::nextTurn(sf::RenderWindow & window)
{
	window.clear(sf::Color(40, 127, 50));
	draw(window);
	window.draw(score);
	window.display();
	sleep123(window, 0.3);
	update(window);
}

void Level::update(sf::RenderWindow & window)
{
	checkLOS(window);

	for (auto enemy : enemies)
	{
		enemy->move(width, player->x, player->y);
	}

	checkLOS(window);
}

void Level::checkLOS(sf::RenderWindow & window)
{
	//check if player is in LOS of enemies
	for (auto enemy : enemies)
	{
		sf::Vector2f dir = enemy->facingDir;
		for (int i = 0; i < 3; i++)
		{
			int tx = enemy->x + dir.x*(i + 1);
			int ty = enemy->y + dir.y*(i + 1);
			printf("%d: %d   %d ||  %d    %d\n", i, tx, ty, player->x, player->y);

			bool caught = (tx == player->x && ty == player->y) ||
				(player->flipped && tx == player->x + player->facingDir.x && ty == player->y + player->facingDir.y && player->alive);
			caught = caught && player->alive;

			if (caught) {
				text.setString("Jeepers! Is that a living ATM? Run!");
				player->alive = false;
				nextTurn(window);
				sleepwithskip(window, 10);
				reset();
			}
		}
	}
}

void Level::flipPlayer(sf::RenderWindow & window)
{
	player->flipped = !player->flipped;

	for (auto enemy : enemies)
	{
		int tx = player->x + player->facingDir.x;
		int ty = player->y + player->facingDir.y;

		if (tx == enemy->x && ty == enemy->y && enemy->alive) {
			printf("SMASH THAT BITCH\n");
			enemy->alive = false;
			enemy->deathDirection = player->facingDir;
			scoreNum += 50;
			if (enemy->moneyHolder)
				scoreNum += 150;
		}
	}

	std::string tstring = "$$$$$: " + std::to_string(scoreNum);
	score.setString(tstring);

	nextTurn(window);
	checkLOS(window);
	sleep123(window, 0.2);
	player->flipped = false;
}

void Level::reset()
{
	scoreNum = 0;
	std::string tstring = "$$$$$: " + std::to_string(scoreNum);
	score.setString(tstring);
	text.setString("");

	player->alive = true;
	player->facingDir = sf::Vector2f(-1, 0);
	player->flipped = false;
	player->x = 7;
	player->y = 7;

	for (auto enemy : enemies)
	{
		enemy->alive = true;
		enemy->facingDir = sf::Vector2f(0, 1);
		enemy->x = 0;
		enemy->y = 0;
	}
}
