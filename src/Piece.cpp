#include <SFML/Graphics.hpp>
#include "Piece.h"

// TODO each piece should have its own offset based on its position on the tower.
// In that case, don't change this

Piece::Piece(bool color, Cell* cell) : mColor(color)
{
	gCellSize = cell->getRadius()*2;
	LoadTexture();
	AttachToCell(cell);
}


Piece::Piece(bool color, float cellSize, sf::Vector2f pos) : mColor(color), gCellSize(cellSize)
{
	LoadTexture();
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
	LoadTexture(true);
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

	std::deque<Piece*> tower = cell->GetTower();
	mOffset.y = 0;
	for (auto i = tower.rbegin(); i!=tower.rend(); ++i)
	{
		if (*i==this) break;
		mOffset.y-=cell->getRadius()/2.5;
	}
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


void Piece::LoadTexture(bool king)
{
	// Texture settings
	// TODO move hardcoded strings into a resource file
	if (king)
	    mTexture.loadFromFile(mColor==codes::Colors::Black ? "res/BlackCheckerKing.png" : "res/WhiteCheckerKing.png");
	else
    	mTexture.loadFromFile(mColor==codes::Colors::Black ? "res/BlackChecker.png" : "res/WhiteChecker.png");
	mTexture.setSmooth(true);

	// Scale
	sf::Vector2u textureSize = mTexture.getSize();
	float scaleFactor = (gCellSize-10) / std::max(textureSize.x, textureSize.y);
	mSprite.setTexture(mTexture);
	mSprite.setScale(scaleFactor, scaleFactor);
}

void Piece::SetSpritePosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos+mOffset);
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
