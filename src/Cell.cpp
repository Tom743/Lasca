#include "Cell.h"

Cell::Cell(float radius, sf::Vector2f pos) : CircleShape(radius)
{
	CircleShape::setPointCount(40);
	CircleShape::setPosition(pos);
	mTexture.loadFromFile("res/Wood1.jpg", sf::IntRect(0, 0, radius*2, radius*2));
	mTexture.setSmooth(true);
	CircleShape::setTexture(&mTexture);
	CircleShape::setOutlineColor(sf::Color(36, 28, 24));
	CircleShape::setOutlineThickness(3);
};

Cell::~Cell()
{

}