#include <SFML/Graphics.hpp>
#include "Piece.h"
#include "Cell.h"

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
	std::vector<Cell*> mCells;
	std::vector<Piece*> mPieces;

	// The color that should fill the window on clear
	sf::Color mBackgroundColor = sf::Color(56, 45, 39);

	sf::RenderWindow* gWindow;
	const int mFrameRateLimit = 60;
};