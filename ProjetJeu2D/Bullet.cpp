#include "Bullet.h"


Bullet::Bullet(float _x, float _y, sf::Texture& _texture, Mob* _target) :
	Entity(_x, _y), AMovable(sf::Vector2f(0,0), 150)
{
	target = _target;
	m_visual.setTexture(_texture); 
	animationindex = 0; 
	animationtime = 0; 
	m_visual.setPosition(_x+1.5f*4, _y+1.5f*4);
	m_visual.setTextureRect(sf::IntRect(9 * 8, 2 * 8, 5, 5));
	m_visual.setScale(32 / 8, 32 / 8);
}

void Bullet::move(float dt)
{
	sf::Vector2f movement = sf::Vector2f(this->getPosition().x + direction.x * vit * dt, this->getPosition().y + direction.y * vit * dt);
	setPosition(movement);
	m_visual.setPosition(movement.x +1.5f*4, movement.y+1.5f*4);
}

void Bullet::update(float dt)
{
	if (target) {
		float distancex = target->getPosition().x - getPosition().x;
		float distancey = target->getPosition().y - getPosition().y;
		setDirection(sf::Vector2f(distancex, distancey));
	}
	// if enemy touch visual then mob take dmg and free bullet from entitylist then delete bullet

	animationtime += dt; 
	if (animationtime > 0.75) {
		animationtime = 0; 
		switch (animationindex) {
		case 0:
			m_visual.setTextureRect(sf::IntRect(9 * 8, 3 * 8, 5, 5));
			animationindex = 1; 
			break; 
		case 1:

			m_visual.setTextureRect(sf::IntRect(9 * 8, 2 * 8, 5, 5));
			animationindex = 0;
			break; 
		}
	}
}
