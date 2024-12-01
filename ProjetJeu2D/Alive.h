#ifndef ALIVE_H__
#define ALIVE_H__

class Alive {
protected:
	float maxHP;
	float HP;
public:
	Alive(float _maxHP);
	virtual float getMaxHP();
	virtual float getHP();
	virtual void takeDMG(float _DMG);
};

#endif