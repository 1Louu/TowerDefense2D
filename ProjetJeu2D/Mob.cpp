#include <iostream>

#include "Mob.h"

Mob::Mob(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, float _maxHP, float _vit, std::vector<Path*>* _itinerary, App* _app)
	: Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length), Alive(_maxHP), AMovable(sf::Vector2f(0,0), _vit ){
	currentApp = _app; 
	itinerary = _itinerary; 
	itinerarystep = 1;
	setPosition((*itinerary)[0]->getPosition().x, (*itinerary)[0]->getPosition().y);
	m_visual.setPosition((*itinerary)[0]->getPosition().x, (*itinerary)[0]->getPosition().y);
	setDirection(sf::Vector2f((*itinerary)[1]->getPosition().x - (*itinerary)[0]->getPosition().x, (*itinerary)[1]->getPosition().y - (*itinerary)[0]->getPosition().y));
}

Mob::Mob(float _x, float _y, sf::Texture& _texture, std::vector<Path*>* _itinerary, App* _app, int _templatechoice) : // when constructed, doesnt want to be displayed afterward ... 
	Entity(_x, _y), Alive(10), AMovable(sf::Vector2f(0,0), 10)
{
	m_visual.setTexture(_texture);
	m_visual.setScale(8 / 32, 8 / 32);
	m_visual.setTextureRect(sf::IntRect(6 * 8, 3 * 8, 8, 8)); // default visual 

	mobTemplate(_templatechoice);
	currentApp = _app;
	itinerary = _itinerary;
	itinerarystep = 1;
	setPosition((*itinerary)[0]->getPosition().x, (*itinerary)[0]->getPosition().y);
	setDirection(sf::Vector2f((*itinerary)[1]->getPosition().x - (*itinerary)[0]->getPosition().x, (*itinerary)[1]->getPosition().y - (*itinerary)[0]->getPosition().y));

	m_visual.setPosition((*itinerary)[0]->getPosition().x, (*itinerary)[0]->getPosition().y);
}
;

void Mob::takeDMG(float _DMG) {
	Alive::takeDMG(_DMG);
	if (getHP() <= 0) {
		flagDestroy = 1;
		SceneManager::GetInstance()->GetCurrentScene()->EntityEventHandler(1);
	}
}

void Mob::move(float dt) {
	sf::Vector2f movement = sf::Vector2f(this->getPosition().x + direction.x * vit * dt, this->getPosition().y + direction.y * vit * dt); 
	setPosition(movement);
	m_visual.setPosition(movement);
}

void Mob::update(float dt)
{
	if(flagDestroy <1) 
	{
		move(dt);
		updateDirection();
	}
}

void Mob::mobTemplate(int _template)
{

	std::cout << _template << std::endl;
	switch (_template) {
	case 0: // Ghost
		m_visual.setTextureRect(sf::IntRect(6 * 8, 3 * 8, 8, 8));
		HP = 7; 
		maxHP = 7; 
		vit = 60;
		break; 
	case 1:
		m_visual.setTextureRect(sf::IntRect(6 * 8, 2 * 8, 8, 8));
		HP = 12; 
		maxHP = 12;
		vit = 40;
		break;
	}
}

void Mob::setTextureSetting(sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length)
{
	m_visual.setTexture(_texture);
	m_visual.setTextureRect(sf::IntRect(_textcordX, _textcordY, textsize, textsize));
	m_visual.setScale(_width / textsize, _length / textsize);
}

void Mob::updateDirection()
{
	if (itinerarystep != (*itinerary).size()-1) {
		if (direction.x > 0) // if im going to right
		{
			if (getPosition().x >= (*itinerary)[itinerarystep]->getPosition().x) {
				itinerarystep++;
				setDirection(sf::Vector2f((*itinerary)[itinerarystep]->getPosition().x - getPosition().x, (*itinerary)[itinerarystep]->getPosition().y - getPosition().y));

			}
		}
		else if (direction.x < 0) {
			if (getPosition().x <= (*itinerary)[itinerarystep]->getPosition().x) {
				itinerarystep++;
				setDirection(sf::Vector2f((*itinerary)[itinerarystep]->getPosition().x - getPosition().x, (*itinerary)[itinerarystep]->getPosition().y - getPosition().y));
			}
		}
		if (direction.y > 0) // if im going to right
		{
			if (getPosition().y >= (*itinerary)[itinerarystep]->getPosition().y) {
				itinerarystep++;
				setDirection(sf::Vector2f((*itinerary)[itinerarystep]->getPosition().x - getPosition().x, (*itinerary)[itinerarystep]->getPosition().y - getPosition().y));

			}
		}
		else if (direction.y < 0) {
			if (getPosition().y <= (*itinerary)[itinerarystep]->getPosition().y) {
				itinerarystep++;
				setDirection(sf::Vector2f((*itinerary)[itinerarystep]->getPosition().x - getPosition().x, (*itinerary)[itinerarystep]->getPosition().y - getPosition().y));
			}
		}
	}
	else {
		float directx, directy; 
		directx = (*itinerary)[itinerarystep]->getPosition().x - getPosition().x;
		directy = (*itinerary)[itinerarystep]->getPosition().y - getPosition().y;

		if (directx <= 4 *direction.x && directy <= 4* direction.y) {
			this->flagDestroy = 1;
			SceneManager::GetInstance()->GetCurrentScene()->EntityEventHandler(0);
		}
	}
}

