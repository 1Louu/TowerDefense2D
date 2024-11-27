#include "AMovable.h"

AMovable::AMovable(sf::Vector2f v, float _vit)
	: direction(normalize(v.x, v.y)), vit(_vit) {

};

void AMovable::setDirection(sf::Vector2f v) {
	this->direction = normalize(v.x, v.y);
}
void AMovable::setDirectionX(float _x)
{
	this->direction = normalize(_x, direction.y);
}

void AMovable::setDirectionY(float _y)
{
	this->direction = normalize(direction.x, _y);
}
;

void AMovable::setVit(float _vit) {
	vit = _vit;
};

sf::Vector2f AMovable::normalize(float _x, float _y) {
	float d = std::sqrt(std::pow(_x, 2) + std::pow(_y, 2));

	if (d == 0)
		return sf::Vector2f(0, 0);

	float x = _x / d;
	float y = _y / d; // 

	return sf::Vector2f(x, y);
}
