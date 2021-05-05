#include <SFML/Graphics.hpp>
#include "Mover.h"
#include "BBar.h"

class GameState {
public:
	GameState();
	~GameState();

	// Load assets
	void Init(sf::RenderWindow* window);

	// Process user input. Returns true if the app should quit
	bool ProcessInput();

	// Draw the state's screen
	void Draw();

	// Get the color that should fill the window on clear
	sf::Color getBackGroundColor();

private:
	// Contains all the cell of the board. Each cell will contain its pieces
	Board mBoardCells = Board();
	// The cell that owns the currently moving tower of pieces. nullptr if not dragging
	Cell* mMovingTowerCell;

	// The bottom bar that contains indicators and stats
	BBar mBBar = BBar();

	// The player that is currently playing
	bool mPlayerOnTurn = codes::Colors::White;

	// Move validator and performer
	Mover mMover = Mover();

	// Window and window configuration
	sf::RenderWindow* gWindow;
	sf::Color mBackgroundColor = sf::Color(56, 45, 39);
	const int mFrameRateLimit = 60; // This state's frame rate limit
	int mCellSize; // Size of the cell in pixels. Defined by the size of the given window
};