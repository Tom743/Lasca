#include "Piece.h"
#include "SFML/Graphics.hpp"

Piece::Piece(sf::Vector2f pos = sf::Vector2f(0, 0)) {
    mTexture.loadFromFile("res/BlackChecker.png");
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
