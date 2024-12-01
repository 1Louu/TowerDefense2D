#include "VisualElement.h"

VisualElement::VisualElement(float _x, float _y, sf::Texture& _texture, int templatechoice) :
	Entity(_x, _y)
{
	m_visual.setPosition(_x, _y); 
	m_visual.setTexture(_texture);
	m_visual.setScale(32 / 8, 32 / 8); // Assuming I use my tilemap that I made which all are 8px wide and that a tile is 32px
	VisualElementTemplate(templatechoice); 
}

void VisualElement::VisualElementTemplate(int choice)
{
	switch (choice) {
	case 0: // Hearts Full
		m_visual.setTextureRect(sf::IntRect(6 * 8, 4 * 8, 8, 8));
		choice = 0; 
		break; 
	case 1: // Hearts Empty
		m_visual.setTextureRect(sf::IntRect(7 * 8, 4 * 8, 8, 8));
		choice = 1;
		break;
	case 2: // Coins 
		m_visual.setTextureRect(sf::IntRect(6 * 8, 5 * 8, 8, 8));
		choice = 2;
		break; 
	case 3: // Coins in light tone
		m_visual.setTextureRect(sf::IntRect(7 * 8, 5 * 8, 8, 8));
		choice = 3;
		break;
	}
 }

int VisualElement::getVisualElementChoice()
{
	return choice;
}
