#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class CustomSprite
{
protected:
    Texture texture;
    Sprite sprite;
    float spriteX = 368;
    float spriteY = 268;
    float speed = 0.4;
    int size;

public:
    CustomSprite(String s, int size);
    void draw(RenderWindow* window);
    bool collide(CustomSprite*);
    virtual void move() = 0;
    float getX();
    float getY();
    int getSize();
    virtual void reset() = 0;
    virtual ~CustomSprite();
};

