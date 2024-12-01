#include "Tower.h"


Tower::Tower(float _x, float _y, sf::Texture& _texture, int _towertemplate, std::vector<Mob*>* _moblist, std::vector<Entity*>* _VELtemp)
	: Entity(_x, _y), texture(_texture)
{
	target = nullptr;
	VELtemp = _VELtemp;  // Visual Entity List so i can insert the bullet here
	moblist = _moblist; // Moblist so i can read where the mobs are at for my range
	TowerTemplate(_towertemplate);
	m_visual.setPosition(_x, _y);
	m_visual.setTexture(_texture);
	m_visual.setScale(32 / 8, 32 / 8);  // Assuming I use my tilemap that I made which all are 8px wide and that a tile is 32px
}

void Tower::TowerTemplate(int _towertemplate)
{
	switch (_towertemplate) {
	case 0:
		range = 32 * 5; 
		power = 5; 
		firerate = 1.f; 
		price = 3;
		m_visual.setTextureRect(sf::IntRect(8 * 8, 2 * 8, 8, 8));
		break; 
	case 1:
		range = 32 * 8;
		power = 5;
		firerate = 2.f;
		price = 5;
		m_visual.setTextureRect(sf::IntRect(7 * 8, 3 * 8, 8, 8));
		break;
	default: 
		std::cout << "Erreur towertemplate" << std::endl; 
	}
}

void Tower::shootatMob(Mob* _target)
{
	bullet = new Bullet(getPosition().x, getPosition().y, texture, _target, power);
	VELtemp->push_back(bullet); 
}

void Tower::update(float dt)
{
	cooldown += dt; 

	if (target) {
		if (target->getflagDestroy() > 0) {
			target = nullptr;
		}
	}

	if (cooldown > firerate) {

		int moblistsize = moblist->size();
		float distancex, distancey;

		if (target) {
			distancex = target->getPosition().x - getPosition().x;
			distancey = target->getPosition().y - getPosition().y;
			if (distancex <= range && distancey <= range) {
				shootatMob(target);
				cooldown = 0;
			}
		}
		else { 
			for (int i = 0; i < moblistsize; i++) {
				if ((*moblist)[i]->getflagDestroy() < 1 && (!target))
				{
					distancex = (*moblist)[i]->getPosition().x - getPosition().x;
					distancey = (*moblist)[i]->getPosition().y - getPosition().y;
					if (distancex < 0)
						distancex = -distancex;
					if (distancey < 0)
						distancey = -distancey;
					if (distancex <= range && distancey <= range) {
						target = (*moblist)[i];
						shootatMob(target);
						cooldown = 0;
					}
				}
			}
		}
	}
		
}
