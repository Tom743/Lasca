#include "SFML/Graphics.hpp"

class Piece
{
public:
	Piece(sf::Vector2f pos = sf::Vector2f(0, 0));
	~Piece();
	sf::Sprite GetSprite();
	void SetPosition(sf::Vector2f pos);
	void SetPosition(float x, float y);
	sf::Vector2f GetPosition();

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;
};