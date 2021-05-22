#ifndef SFMLTEST_GAME_H
#define SFMLTEST_GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <ctime>
#include <sstream>

using namespace sf;
using namespace std;

class Game{

    float enemySpawnTimer;
    float enemySpawnTimerMax;
    unsigned int maxEnemies;
    unsigned int points;
    int health;
    bool endGame;
    bool mouseHeld;

    RenderWindow *window;
    Event event;
    VideoMode videoMode;
    RectangleShape enemy;
    Font font;
    Text uiText;
    Vector2i mousePosWindow;
    Vector2f mousePosView;
    vector<RectangleShape> enemies;

    void initVar();
    void initWindow();
    void initEnemy();
    void initFont();
    void initText();
public:
    Game();
    ~Game();
    bool running() const;
    bool getEndGame() const;
    void pollEvents();
    void renderText(RenderTarget& target);
    void renderEnemies(RenderTarget& target);
    void render();
    void updadeText();
    void updateEnemies();
    void updateMousePos();
    void update();
    void spawnEnemies();
};

#endif //SFMLTEST_GAME_H
