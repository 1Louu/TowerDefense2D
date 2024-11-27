#ifndef BACKGROUND_H__
#define BACKGROUND_H__
#include "Entity.h"
#include <iostream>

class Background : public Entity
{
public: 
	Background(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int _textsize, float _width, float _length);
	void setColor(sf::Color _color);
};

#endif
