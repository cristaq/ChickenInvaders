#include "CustomSprite.h"

CustomSprite::CustomSprite(String s, int size) {
    texture.loadFromFile(s);
    sprite.setTexture(texture);
    sprite.setPosition(spriteX, spriteY);
    this->size = size;
}

void CustomSprite::draw(RenderWindow* window) {
    sprite.setPosition(spriteX, spriteY);
    window->draw(sprite);
}

float CustomSprite::getX() {
    return spriteX;
}

float CustomSprite::getY() {
    return spriteY;
}

int CustomSprite::getSize() {
    return size;
}

bool CustomSprite::collide(CustomSprite* target) {
    if (spriteX + size * 4 / 5 > target->getX() + size * 1 / 5 
        && spriteX + size * 1 / 5 < target->getX() + target->getSize() * 4 / 5 
        && spriteY + size * 4 / 5 > target->getY() + size * 1 / 5 
        && spriteY + size * 1 / 5 < target->getY() + target->getSize() * 4 / 5) {
        return true;
    }

    return false;
}

CustomSprite::~CustomSprite(){}
