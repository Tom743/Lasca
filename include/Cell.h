#include <SFML/Graphics.hpp>
#include "Codes.h"

class Cell : public sf::CircleShape 
{
public:
	Cell(float diameter, sf::Vector2f pos, codes::CellID ID);
	~Cell();

	codes::CellID GetID();

private:
	sf::Texture mTexture;
	codes::CellID mID;
};