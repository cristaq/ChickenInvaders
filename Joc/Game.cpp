#include "Game.h"

Game::Game() {
	window = new RenderWindow(VideoMode(800, 600), "Chicken Invaders");
	player = new Player("spaceship.png", 64);
	bullet = new Bullet("bullet32p.png", 32);
	shield = new Shield("shield.png", 32);
	numEnemies = 7;
	for (int i = 0; i < numEnemies; i++) {
		CustomSprite* enemy = new Enemy("chickenEnemy.png", 64);
		enemies.push_back(enemy);
	}
	lose = false;

	space.loadFromFile("background.jpg");
	background.setTexture(space);
	background.setPosition(0, 0);
	shieldTxt.loadFromFile("shield.png");
	shieldIcon.setPosition(800 - shield->getSize(), 0);
	shieldIcon.setTexture(shieldTxt);

	font.loadFromFile("FRADM.ttf");
	scoreText.setFont(font);
	score = 0;
	scoreText.setString("Score: " + std::to_string(score));
	scoreText.setCharacterSize(18);
	scoreText.setPosition(Vector2f(0, 0));

	gameover.setFont(font);
	gameover.setString("GAME OVER");
	gameover.setCharacterSize(80);
	gameover.setPosition(Vector2f(200, 250));

	backgroundSound.openFromFile("background.wav");
	backgroundSound.setLoop(true);
	backgroundSound.play();
	explosion.loadFromFile("explosion.wav");
	explosionSound.setBuffer(explosion);
}

Game::~Game() {
	delete window;
	delete player;
	delete bullet;
	delete shield;
	for (int i = 0; i < numEnemies; i++) {
		delete enemies[i];
	}
}

void Game::run() {
	Event event;
	while (window->isOpen()) {
		draw();

		if (!lose) {
			update();
		}

		while (window->pollEvent(event))
		{
			if (event.type == Event::Closed)
				window->close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Enter) && lose == true) {
			restart();
		}
	}
}

void Game::draw() {
	window->clear();
	window->draw(background);
	window->draw(scoreText);
	if (!lose) {
		bullet->draw(window);
		for (int i = 0; i < numEnemies; i++) {
			enemies[i]->draw(window);
		}
		shield->draw(window);
	}
	else {
		window->draw(gameover);
	}
	player->draw(window);

	if (player->isShielded()) {
		window->draw(shieldIcon);
	}
	window->display();
}

void Game::update() {
	player->move();
	for (int i = 0; i < numEnemies; i++) {
		enemies[i]->move();
	}
	bullet->move();
	shield->move();

	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		bullet->fire(player);
	}

	for (int i = 0; i < numEnemies; i++) {
		if (enemies[i]->collide(player)) {
			explosionSound.play();
			if (player->isShielded()) {
				enemies[i]->reset();
				player->giveShield(false);
			}
			else
			{
				player->reset();
				lose = true;
			}
		}
		if (enemies[i]->collide(bullet)) {
			explosionSound.play();
			score++;
			scoreText.setString("Score: " + std::to_string(score));
			bullet->reset();
			enemies[i]->reset();
		}
	}

	if ((score + 1) % 25 == 0) {
		shield->reset();
	}

	if (player->collide(shield)) {
		player->giveShield(true);
		shield->dissapear();
	}
}

void Game::restart() {
	score = 0;
	lose = false;
	player->reset();
	for (int i = 0; i < numEnemies; i++) {
		enemies[i]->reset();
	}
	bullet->reset();
	shield->dissapear();
	scoreText.setString("Score: " + std::to_string(score));
	draw();
}