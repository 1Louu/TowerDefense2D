#ifndef BULLET_H__
#define BULLET_H__
#include <iostream>
#include "AMovable.h"
#include "Entity.h"
#include "Mob.h"

class Bullet : public Entity , public AMovable
{
	Mob* target; 
	float animationtime; 
	int animationindex; 
public:
	Bullet(float _x, float _y, sf::Texture& _texture, Mob* _target);
	virtual void move(float dt) override;
	virtual void update(float dt) override;

};

#endif

