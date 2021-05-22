#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(640, 480), "dziala", Style::Titlebar | Style::Close);
    Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            switch (event.type) {
                case Event::Closed:
                    window.close();
                    break;
                case Event::KeyPressed:
                    if(event.key.code == Keyboard::Escape)
                        window.close();
                    break;
            }
        }
        window.clear(Color::Blue);
        window.display();
    }

    return 0;
}
