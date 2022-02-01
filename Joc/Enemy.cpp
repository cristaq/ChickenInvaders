#include "Enemy.h"

Enemy::Enemy(String s, int size) : CustomSprite(s, size) {
	spriteX = rand() % 736;
	spriteY = rand() % 150;
	speed = 0.35;
}

void Enemy::move() {
	spriteX += direction * speed;
	if (spriteX >= 800 - size) {
		direction = -1;
		spriteY += size;
	}
	else if (spriteX <= 0) {
		direction = 1;
		spriteY += size;
	}

	if (spriteY >= 600 - size) {
		spriteY = rand() % 100;
	}
}

void Enemy::reset() {
	spriteX = rand() % 736;
	spriteY = rand() % 100;
}