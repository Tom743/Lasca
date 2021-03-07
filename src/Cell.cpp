#include "Cell.h"

Cell::Cell(float diameter, sf::Vector2f pos, codes::CellID ID) : CircleShape(diameter/2), mID(ID)
{
	CircleShape::setPointCount(40);
	CircleShape::setPosition(pos);
	mTexture.loadFromFile("res/Wood1.jpg", sf::IntRect(0, 0, diameter, diameter));
	mTexture.setSmooth(true);
	CircleShape::setTexture(&mTexture);
	CircleShape::setOutlineColor(sf::Color(36, 28, 24));
	CircleShape::setOutlineThickness(3);
};

codes::CellID Cell::GetID() {return mID;}

Cell::~Cell()
{

}