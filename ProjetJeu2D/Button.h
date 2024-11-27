#ifndef BUTTON_H__
#define BUTTON_H__
#include "Entity.h"
#include "App.h"

class Button : public Entity
{
	App* app;
public:
	Button(float _x, float _y, sf::Texture& _texture, float _width, float _lenght, App* _app);
	void ClickedOn();
	void update(float dt) override;
};

#endif

