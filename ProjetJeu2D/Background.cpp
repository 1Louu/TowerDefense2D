#include "Background.h"

Background::Background(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length): Entity(_x, _y, _texture)
{
	m_visual.setTextureRect(sf::IntRect(_textcordX, _textcordY, textsize, textsize));
	m_visual.setPosition(sf::Vector2f(_x, _y));
	m_visual.setScale(_width/textsize, _length/textsize);
}

void Background::setColor(sf::Color _color)
{
	m_visual.setColor(_color); 
}
