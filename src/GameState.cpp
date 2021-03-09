#include "GameState.h"

GameState::GameState()
{
	
}

GameState::~GameState()
{

}

void GameState::Init(sf::RenderWindow* window)
{
	gWindow = window;
	gWindow->setFramerateLimit(mFrameRateLimit); // This state's frame rate limit


	mCellSize = std::min(gWindow->getSize().x, gWindow->getSize().y)/7;

	// Initiate the board
	for (int i=0; i<7; i++) {
		for (int j=0; j<3+!(i%2); j++) {
			sf::Vector2f pos = sf::Vector2f(j*mCellSize*2+(i%2)*mCellSize, i*mCellSize);
			Cell* cell = new Cell(mCellSize, pos, codes::CellID(7-(j*2+i%2), 7-i));
			mBoardCells.push_back(cell);
			if (i!=3) cell->PushPiece(new Piece(i<3, cell));
		}
	}
}

bool GameState::ProcessInput()
{
	// Temporary variables for drag and drop functionality
	static sf::Vector2f offset;
	static sf::Vector2f oldPos, newPos;
	static Cell* movingTowerCell; // The cell that owns the currently moving tower

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
				for (Cell* c : mBoardCells)
				{
					if (c->getGlobalBounds().contains(mousePos))
					{
						oldPos = c->GetTop()->GetPosition();
						offset = mousePos-oldPos;
						movingTowerCell = c;
					}
				}
			}
		}
		// Mouse released events
		else if (event.type == sf::Event::MouseButtonReleased)
		{
			// If the user was moving a piece, drop it
			if (event.mouseButton.button == sf::Mouse::Left && movingTowerCell!=nullptr)
			{
				// If this is not an appropiate place to drop the piece, success
				// remains false to later return the piece to its original place
				bool success = false;  
				// TODO Implement an ordered matrix search algorithm to speed 
				// this up unnecessarily
				for (Cell* c : mBoardCells) 
				{
					// Move to that cell if possible
					if (c->getGlobalBounds().contains(mousePos))
					{
						if (CheckLegalMove(*movingTowerCell, *c))
						{
							// If the tower can be moved here
							if (c->PutTower(movingTowerCell->GetTower()))
							{
								// Move the pieces
								for (Piece* p : movingTowerCell->GetTower())
								{
									p->AttachToCell(c);
								}
								movingTowerCell->CleanTower();
								movingTowerCell = nullptr;
								success = true;
							}
						}
						break;
					}
				}
				// Return it to the original place 
				// TODO animate this
				if (!success)
				{
					// TODO change for attachToCell
					for (Piece* p : movingTowerCell->GetTower()) p->SetSpritePosition(oldPos);
					movingTowerCell = nullptr;
				}
				       
			}    
		}

		// If the user was moving a piece, keep it on the cursor
		if (movingTowerCell!=nullptr) 
		{
			newPos = mousePos-offset;
			// TODO change for attachToCell
			for (Piece* p : movingTowerCell->GetTower()) p->SetSpritePosition(newPos); 
		}
	}
	return false;
}

// TODO
bool GameState::CheckLegalMove(Cell& from, Cell& to)
{
	return true;//to.GetID().y == to.GetID().y+
			//(from.GetTop()->GetColor() == codes::Colors::Black ? -1 : 1);
}

// FIXME it renders some pieces before some cells, so when dragging the piece may
// appear behind the cells
void GameState::Draw()
{
	// Draw everything
	for (Cell* c : mBoardCells) 
	{
		gWindow->draw(*c);
		for (Piece* p : c->GetTower()) gWindow->draw(p->GetSprite());
	}
}

sf::Color GameState::getBackGroundColor()
{
	return mBackgroundColor;
}