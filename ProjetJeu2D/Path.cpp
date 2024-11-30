#include "Path.h"

Path::Path(float _x, float _y, sf::Texture& _texture, int _textcordX, int _textcordY, int textsize, float _width, float _length) :
	Entity(_x, _y, _texture, _textcordX, _textcordY, textsize, _width, _length) {}

Path::Path(float _x, float _y, sf::Texture& _texture, int _pathtype) : Entity(_x, _y) 
// Using secondary constructor of entity then defining what would have been defined in entity primary constructor
{
	updateVisualPath(_pathtype); 
	// need to set up something incase _pathtype isnt in the switch case
	m_visual.setScale(32 / 8, 32 / 8);
	m_visual.setPosition(_x, _y);
	m_visual.setTexture(_texture);
}

void Path::updateVisualPath(int _pathtype) // update
{
	switch (_pathtype) {
	case 0: // Dot
		m_visual.setTextureRect(sf::IntRect(5 * 8, 3 * 8, 8, 8));
		break;
	case 1: // horizontal path
		m_visual.setTextureRect(sf::IntRect(2 * 8, 2 * 8, 8, 8));
		break;
	case 2: // Vertical Path
		m_visual.setTextureRect(sf::IntRect(2 * 8, 3 * 8, 8, 8));
		break;
	case 3: // Corner Left Top Path
		m_visual.setTextureRect(sf::IntRect(3 * 8, 3 * 8, 8, 8));
		break;
	case 4: // Corner Left Bottom Path
		m_visual.setTextureRect(sf::IntRect(4 * 8, 2 * 8, 8, 8));
		break;
	case 5: // Corner Right Top Path
		m_visual.setTextureRect(sf::IntRect(4 * 8, 3 * 8, 8, 8));
		break;
	case 6: // Corner Right Bottom Path
		m_visual.setTextureRect(sf::IntRect(3 * 8, 2 * 8, 8, 8));
		break;
	default:
		std::cout << "Error Path Setting not recognized " << std::endl;
		return;
	}
}
