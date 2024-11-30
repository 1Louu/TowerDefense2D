#ifndef SCENE_H__
#define SCENE_H__
#include <vector>
#include <iostream>
#include "Entity.h"
#include <SFML/Graphics.hpp>

class Scene : public sf::Drawable
{
protected:
	std::vector <Entity*> VisualEntityList;

public:
	virtual void init() = 0;
	virtual void update(float deltatime);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void resetscene();
};

#endif

