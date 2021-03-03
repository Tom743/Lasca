#include "GameState.h"

GameState::GameState()
{
	// Create some test pieces
	for (int i=0; i<10; i++) {
		mPieces.push_back(new Piece(i%2==0, sf::Vector2f(i*10, 0)));
	}
	// Create some test cells
	for (int i=0; i<3; i++) {
		mCells.push_back(new Cell(50, sf::Vector2f(i*150, 0)));
	}
}

GameState::~GameState()
{

}

void GameState::Init(sf::RenderWindow* window)
{
	gWindow = window;
	gWindow->setFramerateLimit(mFrameRateLimit); // This state's frame rate limit
}

bool GameState::ProcessInput()
{
	// Temporary variables for drag and drop functionality
	static sf::Vector2f offset;
	sf::Vector2f oldPos, newPos;
	static Piece* movingObject;

	// Position of the mouse at this iteration of the game loop
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*gWindow));

	// Event loop
	sf::Event event;
	while (gWindow->pollEvent(event))
	{
		// Close button was clicked
		if (event.type == sf::Event::Closed) return true;

		// Mouse events
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			// Left mouse button events
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				// If the user user is trying to move a piece move it
				for (Piece* p : mPieces)
				{
					if (p->GetSprite().getGlobalBounds().contains(mousePos))
					{
						oldPos = p->GetSprite().getPosition();
						offset = mousePos-oldPos;
						movingObject=p;
					}
				}
			}
		}
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			// If the user was moving a piece, drop it
			if (event.mouseButton.button == sf::Mouse::Left && movingObject!=nullptr)
			{
				newPos = mousePos-offset;
				movingObject->SetPosition(newPos);         
				movingObject=nullptr;          
			}    
		}

		// If we were in the middle of moving a piece, keep it on the cursor
		if (movingObject!=nullptr) 
		{
			newPos = mousePos-offset;
			movingObject->SetPosition(newPos);  
		}
	}
	return false;
}

void GameState::Draw()
{
	// Draw everything
	for (Cell* c : mCells) gWindow->draw(*c);
	for (Piece* p : mPieces) gWindow->draw(p->GetSprite());
}

sf::Color GameState::getBackGroudColor()
{
	return mBackgroundColor;
}