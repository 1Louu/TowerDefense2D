#include <iostream>
#include "Entity.h"
Entity::Entity(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length)
{
	this->setPosition(_x, _y);
	m_visual.setTexture(_texture);
	m_visual.setTextureRect(sf::IntRect(_textcordX, _textcordY, textsize, textsize));
	m_visual.setPosition(sf::Vector2f(_x, _y));
	m_visual.setScale(_width / textsize, _length / textsize);
	flagDestroy = 0; 
}

Entity::Entity(float _x, float _y)
{
	this->setPosition(_x, _y);
	flagDestroy = 0;
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

void Entity::setVisual(sf::Texture& _texture, int _textcordX, int _textcordY, int textsizex, int textsizey, float _width, float _length)
{
	m_visual.setTexture(_texture);
	m_visual.setTextureRect(sf::IntRect(_textcordX, _textcordY, textsizex, textsizey));
	m_visual.setScale(_width / textsizex, _length / textsizey);
}
