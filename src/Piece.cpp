#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Codes.h"

Piece::Piece(bool color, Cell* cell)
{
	LoadTexture(color, cell->getRadius()*2);
	AttachToCell(cell);
}


Piece::Piece(bool color, float cellSize, sf::Vector2f pos)
{
	LoadTexture(color, cellSize);
	SetSpritePosition(pos);
}

sf::Sprite Piece::GetSprite() 
{
	return mSprite;
}

void Piece::AttachToCell(Cell* cell) 
{
	sf::Vector2f cellPos = cell->getPosition();
	float cellSize = cell->getRadius()*2;
	sf::Vector2f scaleFactors = mSprite.getScale();
	sf::Vector2u size = mTexture.getSize();
	size.x *= scaleFactors.x;
	size.y *= scaleFactors.y;

	sf::Vector2f piecePos = cellPos;
	piecePos.x+=(cellSize-size.x)/2;
	piecePos.y+=(cellSize-size.y)/2;
	SetSpritePosition(piecePos);

}

void Piece::LoadTexture(bool color, float cellSize)
{
	// Texture settings
    mTexture.loadFromFile(color ? "res/BlackChecker.png" : "res/WhiteChecker.png");
	mTexture.setSmooth(true);

	// Scale
	sf::Vector2u textureSize = mTexture.getSize();
	float scaleFactor = (cellSize-10) / std::max(textureSize.x, textureSize.y);
	mSprite.setTexture(mTexture);
	mSprite.setScale(scaleFactor, scaleFactor);
}

void Piece::SetSpritePosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos);
}

void Piece::SetSpritePosition(float x, float y)
{
	Piece::SetSpritePosition(sf::Vector2f(x, y));
}

sf::Vector2f Piece::GetPosition() 
{
	return mSprite.getPosition();
}

Piece::~Piece() {
    
}
