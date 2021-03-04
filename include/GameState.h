#include <SFML/Graphics.hpp>
#include "Piece.h"

class Cell;

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
	sf::Color getBackGroudColor();

private:
	// Drawables of the game
	std::vector<Cell*> mBoard;
	std::vector<Piece*> mPieces;

	// Window and window configuration
	sf::RenderWindow* gWindow;
	sf::Color mBackgroundColor = sf::Color(56, 45, 39);
	const int mFrameRateLimit = 60;
	int mCellSize;
};