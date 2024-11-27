#include "Game.h"

Game::Game(App* app) 
{
	HP = 0; 
	this->CurrentApp = app; 
}

void Game::init()
{
	if (!textureMap.loadFromFile("image/tilemap_packed.png"))
	{
		std::cout << "Error Texture" << std::endl;
	};
	// HP = _hp; 
	float posx = CurrentApp->getWindow().getSize().x / 2; // Middle of window on axis X
	float posy = CurrentApp->getWindow().getSize().y / 2; // Middle of window on axis Y

	bg = new Background(0, 0, textureMap, 4 * 8, 2 * 8, 8, posx * 2, posy * 2);
	e = new Mob(30.f, 12.f, 10, 1, sf::Vector2f(0, 0), textureMap);

	bg->setColor(sf::Color(152, 229, 165));// Removing the point of having texture map on background but its fine

	VisualEntityList.push_back(bg);

	bg = new Background(posx/2, posy/2, textureMap, 4 * 8, 2 * 8, 8, posx, posy);

	VisualEntityList.push_back(bg);
	VisualEntityList.push_back(e);
}
