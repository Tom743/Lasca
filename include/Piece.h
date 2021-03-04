#include <SFML/Graphics.hpp>
#include "Cell.h"

class Piece
{
public:
	// This constructor should be given a pointer to a cell so that the piece appears centered on it
	Piece(bool color, Cell* cell);
	// With this one it will appear at the given position
	Piece(bool color, float cellSize, sf::Vector2f pos = sf::Vector2f(0, 0));
	~Piece();
	sf::Sprite GetSprite();
	void AttachToCell(sf::Vector2f cellPos, float cellSize);
	void SetSpritePosition(sf::Vector2f pos);
	void SetSpritePosition(float x, float y);
	sf::Vector2f GetPosition();

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

	void LoadTexture(bool color, float cellSize);
};