#ifndef BUTTON_H__
#define BUTTON_H__
#include "Entity.h"
#include "App.h"

class Button : public Entity
{
	int functiontype; 
	App* app;
public:
	Button(float _x, float _y, sf::Texture& _texture, App* app, int _functiontype);
	Button(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length, App* _app);
	void ClickedOn(int type);
	void update(float dt) override;
};

#endif
