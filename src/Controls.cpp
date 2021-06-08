#include "../headers/Controls.h"
Controls::Controls() {
    this->initWindow();
    this->initCText();
}

Controls::~Controls() {
    delete this->window;
}

void Controls::run() {
    while (this->window->isOpen())
    {
        this->updatePollEvents();
        this->update();
        this->render();
    }
}

void Controls::initWindow() {
    this->window = new RenderWindow(VideoMode(800, 600),
                                    "Game 3", Style::Close | Style::Titlebar);
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Controls::initCText() {
    if (!this->font.loadFromFile(R"(C:\Users\kasia\Documents\Fonts\Dosis-Light.ttf)"))
        cout<<"CONTROLS::INITCTEXT - failed to load font from file" <<endl;
    this->controlsText.setFont(this->font);
    this->controlsText.setCharacterSize(60);
    this->controlsText.setFillColor(Color::White);
    this->controlsText.setString("test");
}


void Controls::updatePollEvents() {
    Event e{};
    while (this->window->pollEvent(e))
    {
        if (e.Event::type == Event::Closed)
            this->window->close();
        if (e.Event::key.code == Keyboard::Enter)
            this->window->close();
    }
}

void Controls::udpateCText() {
    stringstream ss;
    ss<<"Click on squares.";
    this->controlsText.setString(ss.str());
    this->controlsText.setFillColor(Color::White);
    this->controlsText.setOutlineColor(Color::Black);
    this->controlsText.setOutlineThickness(2.f);
    this->controlsText.setPosition(200.f, 250.f);
}

void Controls::update() {
    this->udpateCText();
}

void Controls::renderCTexT() {
    this->window->draw(this->controlsText);
}


void Controls::render() {
    this->window->clear();
    this->renderCTexT();
    this->window->display();
}