#include "Bullet.h"

using namespace sf;

void Bullet::move() {
	if (fired)
	{
		spriteY -= speed;
	}

	if (spriteY < 0) {
		fired = false;
		spriteY = -size;
	}
}

void Bullet::fire(CustomSprite* player) {
	if (!fired) {
		fired = true;
		spriteX = player->getX() + 16;
		spriteY = player->getY() + 16;
	}
}

bool Bullet::getFired() {
	return fired;
}

void Bullet::reset() {
	fired = false;
	spriteY = -size;
}

Bullet::Bullet(String s, int size) : CustomSprite(s, size) {
	speed = 0.8;
	spriteY = -size;
}
