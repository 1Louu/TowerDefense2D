#ifndef TEXT_H__
#define TEXT_H__
#include "Entity.h"
#include <iostream>

class Text : public Entity  // Purpose of a class Text itself isnt that meaningful bc we have sf::Text although this one isnt inherited through Entity so decided to make a class Text that inherit entity. 
{
	int font_size; 
public:
	Text(float _x, float _y, sf::Font& _font, int _size);
	void setText(std::string);
};

#endif
