#include "SFML/Graphics.hpp"

class Piece
{
public:
	Piece();
	~Piece();
	sf::Sprite GetSprite();

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;
};