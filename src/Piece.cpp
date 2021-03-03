#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Codes.h"

Piece::Piece(bool color, sf::Vector2f pos)
{
    mTexture.loadFromFile(color ? "res/BlackChecker.png" : "res/WhiteChecker.png");
	mTexture.setSmooth(true);
	mSprite.setTexture(mTexture);
	SetPosition(pos);
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
