#include "Text.h"

Text::Text(float _x, float _y, sf::Font& _font, int _size) : Entity(_x, _y), font_size(_size)
{
	m_text.setFont(_font);
	m_text.setCharacterSize(font_size);
	m_text.setFillColor(sf::Color::White);
	m_text.setPosition(sf::Vector2f(_x, _y));
	m_text.setString("Empty ... ");
}

void Text::setText(std::string _text)
{
	  m_text.setString(_text);
}
