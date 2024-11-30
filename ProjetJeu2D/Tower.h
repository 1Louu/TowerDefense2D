#ifndef TOWER_H__
#define TOWER_H__
#include <iostream>
#include "Entity.h"
#include "Bullet.h"
#include "Mob.h"


class Tower : public Entity
{
	int price; 
	float firerate; 
	float cooldown; 
	float range;
	Mob* target;
	Bullet* bullet; 
	sf::Texture& texture;
	std::vector <Mob*>* moblist;
	std::vector <Entity*>* VELtemp; 
public: 
	Tower(float _x, float _y, sf::Texture& _texture, int _towertemplate, std::vector<Mob*>* _moblist, std::vector<Entity*>* _VELtemp);
	void TowerTemplate(int _towertemplate);
	void shootatMob(Mob* _target);
	virtual void update(float dt) override;
};

#endif

