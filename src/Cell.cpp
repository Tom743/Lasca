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

Piece* Cell::GetTop()
{
	return mTower.front();
}

bool Cell::PutTower(std::deque<Piece*> newTower)
{
	if (!mTower.empty()) return false;
	mTower = newTower;
	return true;
}

void Cell::CleanTower()
{
	std::deque<Piece*> empty;
	mTower.swap(empty);
}

void Cell::PushPiece(Piece* piece)
{
	mTower.push_back(piece);
}

Piece* Cell::PopPiece()
{
	Piece* p = GetTop();
	mTower.pop_front();
	return p;
}

std::deque<Piece*> Cell::GetTower()
{
	return mTower;
}

codes::CellID Cell::GetID() {return mID;}

Cell::~Cell()
{

}