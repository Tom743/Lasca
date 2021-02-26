#include "Piece.h"


Piece::Piece() {
    mTexture.loadFromFile("ResourceFiles/BlackChecker.png");
	mTexture.setSmooth(true);
	mSprite.setTexture(mTexture);
}

sf::Sprite Piece::GetSprite() 
{
	return mSprite;
}

Piece::~Piece() {
    
}
