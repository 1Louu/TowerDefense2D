#ifndef VISUALELEMENT_H__
#define VISUALELEMENT_H__
#include <iostream>
#include "Entity.h"

class VisualElement : public Entity
{
	int choice; // So I can locate which kind of element. THis is mostly used to update the hearts.
public:
	VisualElement(float _x, float _y, sf::Texture& _texture, int templatechoice);
	void VisualElementTemplate(int choice);
	int getVisualElementChoice();
};

#endif

