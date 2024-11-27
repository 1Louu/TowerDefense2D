#include <iostream>

#include "Mob.h"

Mob::Mob(float _x, float _y, float _maxHP, float _vit, sf::Vector2f _direction, sf::Texture& _texture)
	: Entity(_x, _y, _texture), Alive(_maxHP), AMovable(_direction, _vit) {
	m_visual.setTextureRect(sf::IntRect(3 * 8, 3 * 8, 8, 8));
	m_visual.setScale(500 / 32, 500 / 32);
	m_visual.setPosition(sf::Vector2f(_x, _y));
	std::cout << "Mob just created at x = " << _x << "and y =" << _y << "with " << _maxHP << " life with direction " << _direction.x << " and y = " << _direction.y << std::endl;
};

void Mob::takeDMG(float _DMG) {
	Alive::takeDMG(_DMG);
	if (getHP() <= 0) {
		std::cout << "Mob just died" << std::endl;
	}
}

void Mob::move(float dt) {
	setPosition(sf::Vector2f(this->getPosition().x + direction.y * vit * dt, this->getPosition().y + direction.y * vit * dt));
	std::cout << "Mob just moved" << std::endl;
}
