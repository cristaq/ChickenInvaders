#pragma once
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include <vector>
#include <string>
#include <iostream>
#include "Shield.h"
#include <SFML/Audio.hpp>

using namespace sf;

class Game
{
private:
	Player* player;
	Bullet* bullet;
	Shield* shield;
	std::vector<CustomSprite*> enemies;
	int numEnemies;
	RenderWindow* window;
	bool lose;
	

	Texture space;
	Sprite background;
	Texture shieldTxt;
	Sprite shieldIcon;

	Font font;
	Text scoreText;
	Text gameover;
	int score;

	Music backgroundSound;
	SoundBuffer explosion;
	Sound explosionSound;

public:
	Game();
	~Game();
	void run();
	void draw();
	void update();
	void restart();



};

