#ifndef GAME_H__
#define GAME_H__
#include <iostream>
#include "Scene.h"
#include "Mob.h"
#include "Background.h"
#include "App.h"
#include "Button.h"

class Game : public Scene
{
protected:
	int HP; 
	Mob* e;
	Button* btn; 
	Background* bg; 
	sf::Texture textureMap;
	App* CurrentApp;
public: 
	Game(App* app);
	virtual void init();
};

#endif
