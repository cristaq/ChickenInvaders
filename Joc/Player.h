#pragma once
#include "CustomSprite.h"

using namespace sf;

class Player : public CustomSprite
{
private:
    bool shielded;
public:
    void move();
    Player(String, int);
    void reset();
    bool isShielded();
    void giveShield(bool);
};

