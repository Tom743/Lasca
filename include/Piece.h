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
	// Get the sprite of the piece
	sf::Sprite GetSprite();
	// Move the sprite centered to a cell
	void AttachToCell(Cell* cell);
	// Set the position of the sprite
	void SetSpritePosition(sf::Vector2f pos);
	void SetSpritePosition(float x, float y);
	// Get the position of the sprite
	sf::Vector2f GetPosition();

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

	// Load the correct texture and scale to the correct size
	void LoadTexture(bool color, float cellSize);
};