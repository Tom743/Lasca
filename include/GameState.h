#include "SFML/Graphics.hpp"
#include "Piece.h"

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

private:
	// All the pieces of the game
	std::vector<Piece*> mPieces;

	sf::RenderWindow* gWindow;
	const int mFrameRateLimit = 60;
};