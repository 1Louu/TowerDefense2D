#ifndef PATH_H__
#define PATH_H__
#include <string>
#include <iostream>
#include "Entity.h"

class Path : public Entity
{
public: 
	// Without 
	Path(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int _textsize, float _width, float _length);

	//Contructor where path type is specified in parameter 
	Path(float _x, float _y, sf::Texture& _texture, int _pathtype);

	void updateVisualPath(int _pathtype);
};

#endif
