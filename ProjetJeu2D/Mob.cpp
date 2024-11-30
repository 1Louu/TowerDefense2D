#include <iostream>

#include "Mob.h"

Mob::Mob(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, float _maxHP, float _vit, std::vector<Path*>* _itinerary)
	: Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length), Alive(_maxHP), AMovable(sf::Vector2f(0,0), _vit) {
	itinerary = _itinerary; 
	itinerarystep = 1;
	setPosition((*itinerary)[0]->getPosition().x, (*itinerary)[0]->getPosition().y);
	setDirection(sf::Vector2f((*itinerary)[1]->getPosition().x - (*itinerary)[0]->getPosition().x, (*itinerary)[1]->getPosition().y - (*itinerary)[0]->getPosition().y));

	std::cout << (*itinerary)[0]->getPosition().x << ", " << (*itinerary)[0]->getPosition().y << std::endl;
	std::cout << "Mob just created at x = " << _x << " and y =" << _y << " with " << _maxHP << " life" << std::endl;
};

void Mob::takeDMG(float _DMG) {
	Alive::takeDMG(_DMG);
	if (getHP() <= 0) {
		std::cout << "Mob just died" << std::endl;
	}
}

void Mob::move(float dt) {
	sf::Vector2f movement = sf::Vector2f(this->getPosition().x + direction.x * vit * dt, this->getPosition().y + direction.y * vit * dt); 
	setPosition(movement);
	m_visual.setPosition(movement);
}

void Mob::update(float dt)
{
	move(dt);
	updateDirection();
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
		if (getPosition() == (*itinerary)[itinerarystep]->getPosition()) {
			std::cout << "I have reached my goal. I am now done." << std::endl;
			setDirection(sf::Vector2f(0, 0));
		}
	}
}

