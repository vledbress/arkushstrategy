#include "Game.h"

void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(Consts::SCREEN_WIDTH, Consts::SCREEN_HEIGHT), "pa");
    
   
    window.setFramerateLimit(Consts::fps);
    

    sf::Image icon;
    icon.loadFromFile("res/icon.png");
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());


    SimpleTileFactory stf;
    ShiftAnimationFactory saf;
    Map mp;
    AnimationManager am;


    std::shared_ptr<Tile> ui    = stf.createTile("res/bisnes.png", 50,50, 800, 620);
    std::shared_ptr<Tile> ui2   = stf.createTile("res/bisnes.png", 50,50, 800, 320);
    std::shared_ptr<Tile> panel = stf.createTile("res/map.png", 480, 700, 1280, 10);
    
   
    am.addAnimation(saf.createAnimation(ui,  {100,620}, 2));
    am.addAnimation(saf.createAnimation(ui2, {400,685}, 2));


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Num4) {
                    if (panel->getPosition().x >= 1280) {
                        am.addAnimation(saf.createAnimation(panel, { 1280 - 490, 10 }, 0.2));
                    }
                    else {
                        am.addAnimation(saf.createAnimation(panel, { 1280, 10 }, 0.2));
                    }
                    
                }
                else if (event.key.code == sf::Keyboard::Escape) {
                    std::cout << "Escape key pressed" << std::endl;
                    window.close(); 
                }
                else {
                    std::cout << "Some other key pressed: " << event.key.code << std::endl;
                }
            }
        }

        window.clear();
        mp.draw(window);
        am.update();
        ui->draw(window);
        ui2->draw(window);
        panel->draw(window);
        window.display();
    }
}
