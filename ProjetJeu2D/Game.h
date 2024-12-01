#ifndef GAME_H__
#define GAME_H__
#include <iostream>
#include <stdlib.h>
#include "Scene.h"
#include "Mob.h"
#include "Background.h"
#include "App.h"
#include "Button.h"
#include "Tower.h"
#include "Path.h"
#include "Text.h"
#include "VisualElement.h"

class Game : public Scene
{
protected:
	// Variables/Vectors for Managers specifics
	std::vector <sf::Vector2f> purchaseslots; // temporary until i implement the function of choosing tower slot position.
	int indexslots; // Again, temporary until i implement the option of making that
	std::vector <Path*> itinerary;
	std::vector <Mob*> mobmanager; 


	sf::Font fontMenu;
	int HP; 
	int coins; 

	float cooldown; // Cooldown between spawning
	float timer; // time that has elapsed  
	float cdfastgen; 
	int mobleftgen; 
	int mobgen; // Number of mobs to generate



	// Variables for objects specifics 
	Mob* e;
	Button* btn; 
	Path* path; 
	Tower* tower;
	Background* bg; 
	sf::Texture textureMap;
	Text* texts; 
	Bullet* bullet; 
	VisualElement* VE; 
	App* CurrentApp;
public: 
	Game(App* app);
	virtual void init();
	void updatePath(); 
	void fillPath(int _index);
	virtual void buttonPress(int _case) override;
	virtual void update(float dt) override;
	virtual void EntityEventHandler(int _case) override;

	void generateMob(); 

	void updateCoinsValue();
	void updateHearts(); 

	void fillPurchaseSlots(float _GameScreenX, float _GameScreenY);
};

#endif
