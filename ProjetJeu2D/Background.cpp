#include "Background.h"

Background::Background(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length): 
	Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length)
{
	
}

void Background::setColor(sf::Color _color)
{
	m_visual.setColor(_color); 
}
