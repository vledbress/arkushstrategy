#include "Game.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT), "pa");
    
   
    window.setFramerateLimit(Consts::fps);
    

    sf::Image icon;
    icon.loadFromFile("res/icon.png");



    SimpleTileFactory stf;
    std::shared_ptr<Tile> ui = stf.createTile("res/bisnes.png", 100, 100, 0, 0);
    
    
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    ShiftAnimation sa(ui, { 800,620 }, 60<<1);

    
    Map mp;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mp.draw(window);
        sa.update();
        ui->draw(window);
        window.display();
    }
}
