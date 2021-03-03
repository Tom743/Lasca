#include <SFML/Graphics.hpp>

class Cell : public sf::CircleShape 
{
public:
	Cell(float diameter, sf::Vector2f pos);
	~Cell();


private:
	sf::Texture mTexture;
};