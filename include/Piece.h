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
	// Set the position of the sprite. mOffset will be added to the given position
	void SetSpritePosition(sf::Vector2f pos);
	void SetSpritePosition(float x, float y);
	// Make the piece a king
	void SetKing();
	bool IsKing() {return mIsKing;}
	// Get the position of the sprite
	sf::Vector2f GetPosition();
	// Get the cell where this piece is
	codes::CellID GetCellID();

	bool GetColor();

private:
	sf::Sprite mSprite;
	sf::Texture mTexture;

	bool mColor;
	bool mIsKing = false;

	// Size of the cells of the board, given on the constructors
	float gCellSize;

	// The cell where this piece is
	codes::CellID mCellID = codes::CellID(0, 0);

	// Set the cell where this piece is
	void SetCellID(codes::CellID ID);

	sf::Vector2f mOffset = sf::Vector2f(0, 0);

	// Load the correct texture and scale to the correct size
	void LoadTexture(bool king = false);
};