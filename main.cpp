#include <iostream>
#include "headers/Game.h"

using namespace sf;
using namespace std;

int main() {

    srand(static_cast<unsigned>(time(nullptr)));

    Game game;

    while (game.running() && !game.getEndGame())
    {
        game.update();
        game.render();
    }

    return 0;
}
