#ifndef GAMEOVER_H__
#define GAMEOVER_H__
#include <iostream>
#include "Scene.h"
#include "Text.h"
#include "Background.h"
#include "Button.h"
#include <vector>
#include "App.h"
#include "Mob.h"

class Gameover : public Scene
{
protected:
	sf::Texture textureMenu;
	sf::Texture texturebackground;
	sf::Font fontMenu;
	Text* texttitle;
	Background* bg;
	App* CurrentApp;
public:
	Gameover(App* app);
	virtual void init();
};

#endif