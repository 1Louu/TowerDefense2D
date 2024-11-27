#include "Alive.h"

Alive::Alive(float _maxHP) : maxHP(_maxHP), HP(_maxHP) {};

float Alive::getMaxHP() {
	return(this->maxHP);
};

float Alive::getHP() {
	return(this->HP);
};

void Alive::takeDMG(float _DMG) {
	this->HP -= _DMG;
};
