#include <iostream>
#include "Entity.h"
Entity::Entity(float _x, float _y, sf::Texture& _path)
{

	m_visual.setTexture(_path);
	this->setPosition(_x, _y);

}

Entity::Entity(float _x, float _y)
{
	this->setPosition(_x, _y);
}

void Entity::draw(sf::RenderTarget& _target, sf::RenderStates _states) const
{
	// _states.transform = _states.transform.combine(this->getTransform());
	// 
	// Reason why im disabling line above here is bc localbound of m_visual *isnt* updated.
	// Best to find a better way to do this

	_target.draw(m_visual, _states);
	_target.draw(m_text, _states); 
}

sf::Sprite Entity::getVisual()
{
	return sf::Sprite();
}
