#include "Game.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT), "pa");
    
   
    window.setFramerateLimit(60);
    


    std::unique_ptr<Tile> ptr = std::make_unique<Tile>("res/sava.png", 800,300);
    


    

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ptr->draw(window);
       
 
        window.display();
    }
}
