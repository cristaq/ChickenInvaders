#include "Game.h"

using namespace sf;

int main()
{
    Game* game = new Game();
    game->run();
    delete game;
    return 0;
}