#include "Cell.h"

Cell::Cell(float diameter, sf::Vector2f pos) : CircleShape(diameter/2)
{
	CircleShape::setPointCount(40);
	CircleShape::setPosition(pos);
	mTexture.loadFromFile("res/Wood1.jpg", sf::IntRect(0, 0, diameter, diameter));
	mTexture.setSmooth(true);
	CircleShape::setTexture(&mTexture);
	CircleShape::setOutlineColor(sf::Color(36, 28, 24));
	CircleShape::setOutlineThickness(3);
};

Cell::~Cell()
{

}