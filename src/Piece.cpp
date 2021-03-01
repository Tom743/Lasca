#include "Piece.h"


Piece::Piece() {
    mTexture.loadFromFile("res/BlackChecker.png");
	mTexture.setSmooth(true);
	mSprite.setTexture(mTexture);
}

sf::Sprite Piece::GetSprite() 
{
	return mSprite;
}

void Piece::SetPosition(sf::Vector2f pos)
{
	mSprite.setPosition(pos);
}

void Piece::SetPosition(float x, float y)
{
	mSprite.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Piece::GetPosition() 
{
	return mSprite.getPosition();
}

Piece::~Piece() {
    
}
