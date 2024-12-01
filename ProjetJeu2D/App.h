#ifndef APP_H__
#define APP_H__
#include <SFML/Graphics.hpp>
#include "SceneManager.h"

class App //Sert tout simplement d'avoir un interface 
{
	sf::RenderWindow _window;
	SceneManager* sm;
public:
	void init();
	void run();
	sf::RenderWindow& getWindow();};

#endif

