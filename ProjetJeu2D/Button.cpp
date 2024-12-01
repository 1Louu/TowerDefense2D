#include "Button.h"
#include <iostream>
Button::Button(float _x, float _y, sf::Texture& _texture, App* _app,int _functiontype) :
	Entity(_x,_y), app(_app), functiontype(_functiontype)
{
	m_visual.setPosition(_x, _y); 
	m_visual.setTexture(_texture); 
	m_visual.setTextureRect(sf::IntRect(0 * 8, 4 * 8, 16, 16));
	m_visual.setScale(32/8, 32/8);
}
Button::Button(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, App* _app) :
	Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length)
{	
	functiontype = 0; 
	this->app = _app;
}

void Button::ClickedOn(int type)
{
	SceneManager::GetInstance()->GetCurrentScene()->buttonPress(type);
}

void Button::update(float dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

		if (m_visual.getGlobalBounds().contains(app->getWindow().mapPixelToCoords(sf::Mouse::getPosition(app->getWindow())))) {
			if (functiontype == 0) {// Part for mainmenu only
					SceneManager::GetInstance()->ChangeScene("game");
			
			}
			if (functiontype > 0) {
				ClickedOn(functiontype);
			}
		}
	}
}
