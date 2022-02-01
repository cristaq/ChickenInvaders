#include "Shield.h"

Shield::Shield(String s, int size) : CustomSprite(s, size) {
	spriteY = 600 + size;
	spriteX = rand() % (800 - size);
	speed = 0.2;
}

void Shield::move() {
	if (spriteY < 600 + size) {
		spriteY += speed;
	}
}

void Shield::reset() {
	spriteY = -size;
	spriteX = rand() % (800 - size);
}

void Shield::dissapear() {
	spriteY = 600 + size;
}