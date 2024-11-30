#ifndef GAME_H__
#define GAME_H__
#include <iostream>
#include "Scene.h"
#include "Mob.h"
#include "Background.h"
#include "App.h"
#include "Button.h"
#include "Tower.h"
#include "Path.h"
#include "Text.h"

class Game : public Scene
{
protected:
	std::vector <Path*> itinerary;
	std::vector <Mob*> mobmanager; 
	sf::Font fontMenu;
	int HP; 
	int coins; 
	Mob* e;
	Button* btn; 
	Path* path; 
	Tower* tower;
	Background* bg; 
	sf::Texture textureMap;
	Text* texts; 
	Bullet* bullet; 
	App* CurrentApp;
public: 
	Game(App* app);
	virtual void init();
	void updatePath(); 
	void fillPath(int _index); 
};

#endif
