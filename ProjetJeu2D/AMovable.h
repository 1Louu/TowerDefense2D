#ifndef AMOVABLE_H__
#define AMOVABLE_H__
#include <SFML/Graphics.hpp>

class AMovable {
protected:
	sf::Vector2f direction;
	float vit;
public:
	AMovable(sf::Vector2f _direction, float _vit); // Constructeur
	virtual void setDirection(sf::Vector2f _vectpos);
	virtual void setDirectionX(float _x);
	virtual void setDirectionY(float _y);
	virtual void setVit(float _vit);
	virtual void move(float dt) = 0;
	sf::Vector2f normalize(float _x, float _y);
};

#endif
