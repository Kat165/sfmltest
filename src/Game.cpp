#include "../headers/Game.h"

//KONSTRUKTORY I DEKONSTRUKTORY

Game::Game() {
    this->initVar();
    this->initWindow();
    this->initFont();
    this->initText();
    this->initEnemy();
}

Game::~Game() {
    delete this->window;
}

//GETTERY

bool Game::running() const {
    return this->window->isOpen();
}

bool Game::getEndGame() const {
    return this->endGame;
}

//INITY

void Game::initVar() {
    this->window = nullptr;
    this->points = 0;
    this->enemySpawnTimerMax = 20.f;
    this->enemySpawnTimer = this->enemySpawnTimerMax;
    this->maxEnemies = 5;
    this->mouseHeld = false;
    this->health = 20;
    this->endGame = false;
}

void Game::initWindow() {
    this->videoMode.height = 600;
    this->videoMode.width = 800;
    this->window = new RenderWindow(this ->videoMode, "Game 1", Style::Titlebar |
    Style::Close);
    this->window->setFramerateLimit(60);
}

void Game::initEnemy() {
    this->enemy.setPosition(10.f, 10.f);
    this->enemy.setSize(Vector2f(75.f, 75.f));
    this->enemy.setFillColor(Color::Magenta);
    //this->enemy.setOutlineColor(Color::Cyan);
    //this->enemy.setOutlineThickness(3.f);
}

void Game::initFont() {
    if (this->font.loadFromFile(R"(C:\Users\kasia\Documents\Fonts\Dosis-Light.ttf)"))
    {
        cout<<"Failed to load font";
    }
}

void Game::initText() {
    this->uiText.setFont(this->font);
    this->uiText.setCharacterSize(24);
    this->uiText.setFillColor(Color::Red);
    this->uiText.setString("NONE");

}

//RENDERY

void Game::renderEnemies(RenderTarget& target) {

    for (auto &e : this->enemies)
    {
        target.draw(e);
    }
}

void Game::renderText(RenderTarget& target) {
    target.draw(this->uiText);
}

void Game::render() {
    this->window->clear(Color(0, 0, 0, 255));
    this->renderEnemies(*this->window);
    this->renderText(*this->window);
    this->window->display();
}

//UPDATE

void Game::update() {
    this->pollEvents();
    if (!this->endGame)
    {
        this->updateMousePos();
        this->updadeText();
        this->updateEnemies();
    }
    if (this->health <= 0)
        endGame = true;
}

void Game::updateMousePos() {
    this->mousePosWindow = Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
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

    for (int i = 0; i<enemies.size(); ++i)
    {
        bool deleted = false;

        this->enemies[i].move(0.f,3.f);
        if (this->enemies[i].getPosition().y > this->window->getSize().y)
        {
            this->enemies.erase(this->enemies.begin() + i);
            this->health -= 1;
            cout<<"Health: "<<this->health<<endl;
        }
    }

    if (Mouse::isButtonPressed(Mouse::Left))
    {
        if(!this->mouseHeld)
        {
            this->mouseHeld = true;
            bool deleted = false;
            for (int i = 0; i < enemies.size() && !deleted; ++i) {
                if (this->enemies[i].getGlobalBounds().contains(this->mousePosView))
                {
                    if (this->enemies[i].getFillColor() == Color::Green)
                        this->points += 15.f;
                    else if (this->enemies[i].getFillColor() == Color::Yellow)
                        this->points += 10.f;
                    else if (this->enemies[i].getFillColor() == Color::Blue)
                        this->points += 8.f;
                    else if (this->enemies[i].getFillColor() == Color::White)
                        this->points += 5.f;
                    else if (this->enemies[i].getFillColor() == Color::Red)
                        this->points += 1.f;

                    this->enemies.erase(this->enemies.begin() + i);
                    deleted = true;

                    cout<<"Points: "<<this->points<<endl;
                }
            }
        }
    }else{this->mouseHeld = false;}

}

void Game::updadeText() {
    stringstream ss;
    ss<<"Points: "<<this->points<<endl<<"Health: "<< this->health<<endl;
    this->uiText.setString(ss.str());
}

//INNE

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

void Game::spawnEnemies() {
    this->enemy.setPosition(
            static_cast<float>(rand()%static_cast<int>(this->window->getSize().x - this->enemy.getSize().x)),
            0.f
            );

    //Random enemy type
    int type = rand()%5;

    switch (type) {
        case 0:
            this->enemy.setFillColor(Color::Green);
            this->enemy.setSize(Vector2f(10.f, 10.f));
            break;
        case 1:
            this->enemy.setFillColor(Color::Yellow);
            this->enemy.setSize(Vector2f(30.f, 30.f));
            break;
        case 2:
            this->enemy.setFillColor(Color::Blue);
            this->enemy.setSize(Vector2f(45.f, 45.f));
            break;
        case 3:
            this->enemy.setFillColor(Color::White);
            this->enemy.setSize(Vector2f(65.f, 65.f));
            break;
        case 4:
            this->enemy.setFillColor(Color::Red);
            this->enemy.setSize(Vector2f(80.f, 80.f));
            break;
        default:
            this->enemy.setFillColor(Color::Cyan);
            this->enemy.setSize(Vector2f(10.f, 10.f));
            break;
    }
    this->enemies.push_back(this->enemy);
}
