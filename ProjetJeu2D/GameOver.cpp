#include "Gameover.h"

Gameover::Gameover(App* app)
{
	std::cout << "GameOverSc Created" << std::endl;

	CurrentApp = app;
}

void Gameover::init()
{
	if (!texturebackground.loadFromFile("image/selfmadetilemap.png"))
	{
		std::cout << "Error Texture" << std::endl;
	};
	if (!fontMenu.loadFromFile("font/arial/arial_light.ttf"))
	{
		std::cout << "Error Font" << std::endl;
	}
	float posx = CurrentApp->getWindow().getSize().x / 2; // Middle of window on axis X
	float posy = CurrentApp->getWindow().getSize().y / 2; // Middle of window on axis Y
	float btnsizeX = 500;
	float btnsizeY = 150;
	bg = new Background(0, 0, texturebackground, 1 * 8, 2 * 8, 8, posx * 2, posy * 2);

	texttitle = new Text(posx - (30 * 10), posy / 2.5, fontMenu, 60);
	texttitle->setText("GAMEOVER");


	VisualEntityList.push_back(bg);
	VisualEntityList.push_back(texttitle);
}
