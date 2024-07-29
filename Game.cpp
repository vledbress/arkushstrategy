#include "Game.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT), "zalupa");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    window.setFramerateLimit(60);
    std::string path = "res/map.png";

    sf::Texture texture;
    if (!texture.loadFromFile(path)) {
        std::cerr << "Error: Could not load image from " << path << std::endl;
        return;
    }

    sf::Sprite sprite(texture);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }
}
