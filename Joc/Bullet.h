#pragma once
#include "Player.h"
#include "CustomSprite.h"

using namespace sf;

class Bullet : public CustomSprite
{
private:
	bool fired = false;


public:
	void move();
	Bullet(String, int);
	void fire(CustomSprite*);
	bool getFired();
	void reset();

};

