#include "GameState.h"

// TODO someday: hover mouse over a tower and lift some pieces to reveal if there is a king
// TODO cleanups (unique pointers?)

GameState::GameState()
{
	
}

GameState::~GameState()
{

}

void GameState::Init(sf::RenderWindow* window)
{
	gWindow = window;
	gWindow->setFramerateLimit(mFrameRateLimit);

	mCellSize = std::min(gWindow->getSize().x, gWindow->getSize().y)/7;

	mBoardCells.Init(mCellSize);
}

bool GameState::ProcessInput()
{
	// Temporary variables for drag and drop functionality
	static sf::Vector2f offset;
	static sf::Vector2f oldPos, newPos;

	// Position of the mouse at this iteration of the game loop
	sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*gWindow));

	// Event loop
	sf::Event event;
	while (gWindow->pollEvent(event))
	{
		// Close button was clicked
		if (event.type == sf::Event::Closed) return true;

		// Mouse pressed events
		else if (event.type == sf::Event::MouseButtonPressed)
		{
			// Left mouse button pressed
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				// If the user user is trying to move a piece grab it
				for (std::vector<Cell*> r : mBoardCells.GetCells()) for (Cell* c : r)
				{
					if (c->getGlobalBounds().contains(mousePos))
					{
						if (c->GetTop() != nullptr)
						{
							oldPos = c->GetTop()->GetPosition();
							offset = mousePos-oldPos;
							mMovingTowerCell = c;
						}
						break;
					}
				}
			}
		}
		// Mouse released events
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			// If the user was moving a piece, drop it
			if (event.mouseButton.button == sf::Mouse::Left && 
				mMovingTowerCell!=nullptr)
			{
				// If this is not an appropiate place to drop the piece, success
				// remains false to later return the piece to its original place
				bool success = false;  
				// TODO Implement an ordered matrix search algorithm to speed 
				// this up unnecessarily
				for (std::vector<Cell*> r : mBoardCells.GetCells()) for (Cell* c : r)
				{
					// Move to that cell if possible
					if (c->getGlobalBounds().contains(mousePos))
					{
						// If valid, move will be performed and the turn goes to the other player
						// Otherwise, try again
						if (mMover.ValidateAndMove(*mMovingTowerCell, *c, mBoardCells))
						{
							mMovingTowerCell=nullptr;
							success = true;
						}
						break;
					}
				}
				// Return it to the original place
				// TODO animate this
				if (!success)
				{
					for (Piece* p : mMovingTowerCell->GetTower()) 
						p->AttachToCell(mMovingTowerCell);
					
					mMovingTowerCell = nullptr;
				}
				       
			}    
		}

		// If the user was moving a piece, keep it on the cursor
		if (mMovingTowerCell!=nullptr) 
		{
			newPos = mousePos-offset;
			for (Piece* p : mMovingTowerCell->GetTower())
				p->SetSpritePosition(newPos); 
		}
	}
	return false;
}

void GameState::Draw()
{
	// Draw Board
	for (std::vector<Cell*> r : mBoardCells.GetCells()) for (Cell* c : r)
		gWindow->draw(*c);
	// Draw Pieces
	for (std::vector<Cell*> r : mBoardCells.GetCells()) for (Cell* c : r)
	{
		// TODO test performance of this conditional. If too bad, draw the tower anyways, and draw it again later
		if (c!=mMovingTowerCell)  
		{
			for (Piece* p : c->GetTower()) 
				gWindow->draw(p->GetSprite());
		}
	}
	// Draw the moving tower on top of that 
	if (mMovingTowerCell!=nullptr)
	{
		std::deque<Piece*> tower = mMovingTowerCell->GetTower();
		for (auto it = tower.rbegin(); it!=tower.rend(); ++it)
			gWindow->draw((*it)->GetSprite());
	}
}

sf::Color GameState::getBackGroundColor()
{
	return mBackgroundColor;
}