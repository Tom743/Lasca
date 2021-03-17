#include <SFML/Graphics.hpp>
#include "Piece.h"

// TODO each piece should have its own offset based on its position on the tower.
// In that case, don't change this

Piece::Piece(bool color, Cell* cell) : mColor(color)
{
	LoadTexture(color, cell->getRadius()*2);
	AttachToCell(cell);
}


Piece::Piece(bool color, float cellSize, sf::Vector2f pos) : mColor(color)
{
	LoadTexture(color, cellSize);
	SetSpritePosition(pos);
}

sf::Sprite Piece::GetSprite() 
{
	return mSprite;
}

bool Piece::GetColor()
{
	return mColor;
}

void Piece::SetKing()
{
	mIsKing = true;
	// TODO change texture to something that indicates it is a king
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

	SetCellID(codes::CellID(cell->GetID()));
}

codes::CellID Piece::GetCellID()
{
	return mCellID;
}

void Piece::SetCellID(codes::CellID ID)
{
	mCellID = ID;
}


void Piece::LoadTexture(bool color, float cellSize)
{
	// Texture settings
    mTexture.loadFromFile(color==codes::Colors::Black ? "res/BlackChecker.png" : "res/WhiteChecker.png");
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
