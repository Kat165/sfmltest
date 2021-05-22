#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Game{

    RenderWindow *window;
    Event event;
    VideoMode videoMode;
    void initVar();
    void initWindow();
public:
    Game();
    ~Game();
    bool running() const;

    void pollEvents();
    void render();
    void update();
};

#endif //SFMLTEST_GAME_H
