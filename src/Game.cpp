#include "../headers/Game.h"

void Game::initVar() {
    this->window = nullptr;

}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new RenderWindow(this ->videoMode, "Game 1", Style::Titlebar |
    Style::Close);

}

Game::Game() {
    this->initVar();
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

bool Game::running() const {
    return this->window->isOpen();
}

void Game::render() {
    this->window->clear(Color(255, 0, 0, 255));
    this->window->display();
}

void Game::update() {
    this->pollEvents();

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
