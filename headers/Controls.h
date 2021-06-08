//
// Created by kasia on 08.06.2021.
//

#ifndef SFMLTEST_CONTROLS_H
#define SFMLTEST_CONTROLS_H


#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>

using namespace sf;
using namespace std;

class Controls {
    RenderWindow* window;
    Font font;
    Text controlsText;
    void initWindow();
    void initCText();
public:
    Controls();
    ~Controls();
    void run();
    void updatePollEvents();
    void udpateCText();
    void update();
    void renderCTexT();
    void render();
};


#endif //SFMLTEST_CONTROLS_H
