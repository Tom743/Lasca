#include "BBar.h"

// TODO make this depend on the size of the window
// TODO make this look good
BBar::BBar() {
	mCurrentPlayer=codes::Colors::White;
	mRectangleShape.setSize(sf::Vector2f(200, 60));
	ChangePlayerColor(mCurrentPlayer);
	mRectangleShape.setOutlineColor(sf::Color::Black);
	mRectangleShape.setOutlineThickness(5);
	mRectangleShape.setPosition(5, 855);    
}

void BBar::ChangePlayerColor(bool color) {
	mCurrentPlayer=color;
	mRectangleShape.setFillColor(mCurrentPlayer == codes::Colors::White ? mWhiteColor : mBlackColor);
}

void BBar::ChangePlayerColor() {
	ChangePlayerColor(!mCurrentPlayer);
}

void BBar::Draw(sf::RenderWindow* window) {
	window->draw(mRectangleShape);
}


BBar::~BBar() {
    
}
