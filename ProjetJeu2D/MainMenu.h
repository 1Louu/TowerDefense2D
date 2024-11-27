#ifndef MAINMENU_H__
#define MAINMENU_H__
#include <iostream>
#include "Scene.h"
#include "Text.h"
#include "Background.h"
#include "Button.h"
#include <vector>
#include "App.h"
#include "Mob.h"

class MainMenu : public Scene
{
protected:
	sf::Texture textureMenu;
	sf::Texture texturebackground;
	sf::Font fontMenu; 
	Button* Start;
	Text* texttitle; 
	Background* bg; 
	App* CurrentApp;
public: 
	MainMenu(App* app);
	virtual void init();
};

#endif