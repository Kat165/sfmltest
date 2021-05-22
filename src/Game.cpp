#include "../headers/Game.h"

void Game::initVar() {
    this->window = nullptr;
    this->points = 0;
    this->enemySpawnTimerMax = 10.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new RenderWindow(this ->videoMode, "Game 1", Style::Titlebar |
    Style::Close);
    this->window->setFramerateLimit(60);

}

Game::Game() {
    this->initVar();
    this->initWindow();
    this->initEnemy();
}

Game::~Game() {
    delete this->window;
}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::render() {
    this->window->clear(Color(0, 0, 0, 255));
    this->renderEnemies();
    this->window->display();
}

void Game::update() {
    this->pollEvents();
    this->updateMousePos();
    this->updateEnemies();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type) {
            case Event::Closed:
                this->window->close();
                break;
            case Event::KeyPressed:
                if(this->event.key.code == Keyboard::Escape)
                    this->window->close();
                break;
            default:
                break;
        }
    }
}

void Game::initEnemy() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(Vector2f(100.f, 100.f));
    this->enemy.setFillColor(Color::Magenta);
    this->enemy.setOutlineColor(Color::Cyan);
    this->enemy.setOutlineThickness(3.f);
}

void Game::updateMousePos() {
    this->MousePos = Mouse::getPosition(*this->window);

}

void Game::spawnEnemies() {
    this->enemy.setPosition(
            static_cast<float>(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
            0.f
            );
    this->enemy.setFillColor(Color::Green);
    this->enemies.push_back(this->enemy);
}

void Game::updateEnemies() {
    if (this->enemies.size() < this->maxEnemies)
    {
        if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
        {
            this->spawnEnemies();
            this->enemySpawnTimer = 0.f;
        }
        else
            this->enemySpawnTimer += 1.f;
    }

    for (auto &e : this->enemies)
    {
        e.move(0.f, 1.f);
    }
}

void Game::renderEnemies() {

    for (auto &e : this->enemies)
    {
        this->window->draw(e);
    }
}
