#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>

using namespace sf;
using namespace std;

class Game{

    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned int maxEnemies;
    int points;
    RenderWindow *window;
    Event event;
    VideoMode videoMode;
    RectangleShape enemy;
    Vector2i MousePos;
    vector<RectangleShape> enemies;
    void initVar();
    void initWindow();
    void initEnemy();
public:
    Game();
    ~Game();
    bool running() const;
    void pollEvents();
    void renderEnemies();
    void render();
    void updateEnemies();
    void updateMousePos();
    void update();
    void spawnEnemies();
};

#endif //SFMLTEST_GAME_H
