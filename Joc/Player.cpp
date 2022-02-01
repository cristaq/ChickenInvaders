#include "Player.h"
#include <iostream>


Player::Player(String playerImage, int size) : CustomSprite(playerImage, size) {
    spriteX = 800 / 2 - size / 2;
    spriteY = 600 - size;
    shielded = false;
}
void Player::move() {
    if (Keyboard::isKeyPressed(Keyboard::Left) && spriteX - speed >= 0 ) {
        spriteX -= speed;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right) && spriteX + speed <= 800 - size) {
        spriteX += speed;
    }

    if (Keyboard::isKeyPressed(Keyboard::Up) && spriteY - speed >= 0) {
        spriteY -= speed;
    }

    if (Keyboard::isKeyPressed(Keyboard::Down) && spriteY + speed <= 600 - size) {
        spriteY += speed;
    }
}

void Player::reset() {
    spriteX = 800 / 2 - size / 2;
    spriteY = 600 - size;
}

bool Player::isShielded() {
    return shielded;
}

void Player::giveShield(bool b) {
    shielded = b;
}
