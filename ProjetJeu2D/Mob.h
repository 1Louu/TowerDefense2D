#ifndef MOB_H__
#define MOB_H__

#include "AMovable.h" 
#include "Entity.h" 
#include "Alive.h" 

class Mob : public Entity, public Alive, public AMovable {
public:
	Mob(float _x, float _y, float _maxHP, float _vit, sf::Vector2f _direction, sf::Texture& _texture);
	virtual void takeDMG(float _DMG) override;
	virtual void move(float dt) override;
};

#endif