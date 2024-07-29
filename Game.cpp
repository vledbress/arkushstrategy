#include "Game.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT), "pa");
    
   
    window.setFramerateLimit(60);
    

    sf::Image icon;
    icon.loadFromFile("res/icon.png");


    // Устанавливаем иконку
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    
    Map mp;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mp.draw(window);
        window.display();
    }
}
