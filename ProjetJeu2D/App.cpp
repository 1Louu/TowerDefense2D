#include "App.h"
#include <iostream>
#include "Game.h"
#include "MainMenu.h"

void App::init()
{

    _window.create(sf::VideoMode(1600, 960), "RETRO TOWER DEFENSE");

    sm = SceneManager::GetInstance();
    MainMenu* menu = new MainMenu(this);
    Game* game = new Game(this);
    sm->AddScene("menu", menu);
    sm->AddScene("game", game);
    sm->ChangeScene("menu");  


    sf::View t = _window.getDefaultView();
    _window.setView(t);
}

void App::run()
{
    sf::Clock clock;
    while (_window.isOpen()) {
        sf::Time elapsed = clock.restart();
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        _window.clear();

        sm->GetCurrentScene()->update(elapsed.asSeconds());
        _window.draw(*(sm->GetCurrentScene()));

        _window.display();
    };
}

sf::RenderWindow& App::getWindow()
{
    return this->_window;
}