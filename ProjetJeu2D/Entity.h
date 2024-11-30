#ifndef ENTITY_H__
#define ENTITY_H__
#include <SFML/Graphics.hpp>

class Entity : public sf::Transformable, public sf::Drawable {
protected:
	sf::Sprite m_visual;
	sf::Text m_text; 
	Entity(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length); // constructor for sprites
	Entity(float _x, float _y); // constructor for non sprite entity ( text for exmple ) 
	int flagDestroy; 
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::Sprite getVisual();
	virtual void setVisual(sf::Texture& _texture, int _textcordX, int _textcordY, int textsizex, int textsizey, float _width, float _length);
	virtual void update(float dt) {}


};

#endif