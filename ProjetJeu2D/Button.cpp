#include "Button.h"
#include <iostream>
Button::Button(float _x, float _y, sf::Texture& _texture, float _width, float _lenght, App* _app) : Entity(_x, _y, _texture)
{
	m_visual.setTextureRect(sf::IntRect(6 * 32, 0 * 32, 32, 32));
	m_visual.setPosition(sf::Vector2f(_x, _y)); 
	m_visual.setScale(_width / 32, _lenght / 32);
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
