#pragma once
#include "CustomSprite.h"

class Shield : public CustomSprite
{
public:
	Shield(String, int);
	void move();
	void reset();
	void dissapear();
};

