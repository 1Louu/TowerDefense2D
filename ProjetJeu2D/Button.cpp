#include "Button.h"
#include <iostream>
Button::Button(float _x, float _y, sf::Texture& _texture, int _functiontype) :
	Entity(_x,_y)
{
	m_visual.setPosition(_x, _y); 
	m_visual.setTexture(_texture); 
	m_visual.setTextureRect(sf::IntRect(0 * 8, 4 * 8, 16, 16));
}
Button::Button(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, App* _app) :
	Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length)
{
	this->app = _app;
}

void Button::ClickedOn()
{

}

void Button::update(float dt)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		if (m_visual.getGlobalBounds().contains(app->getWindow().mapPixelToCoords(sf::Mouse::getPosition(app->getWindow())))) {
			SceneManager::GetInstance()->ChangeScene("game");
		}
	}
}
