#pragma once
#include "CustomSprite.h"

class Enemy : public CustomSprite
{
private:
	int direction = 1;
public:
	void move();
	Enemy(String, int);
	void reset();
};

