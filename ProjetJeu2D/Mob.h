#ifndef MOB_H__
#define MOB_H__
#include <vector>
#include "AMovable.h" 
#include "Path.h"
#include "Entity.h" 
#include "Alive.h" 

class Mob : public Entity, public Alive, public AMovable {
	int itinerarystep;
	std::vector<Path*>* itinerary; 
public:
	Mob(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, float _maxHP, float _vit, std::vector<Path*>* _itinerary);
	virtual void takeDMG(float _DMG) override;
	virtual void move(float dt) override;
	virtual void update(float dt) override;

	void setTextureSetting(sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length);
	void updateDirection(); 
};

#endif