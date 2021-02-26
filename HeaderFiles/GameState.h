#include "SFML/Graphics.hpp"

class GameState {
public:
	GameState();
	~GameState();

	// Load assets
	void Init(sf::RenderWindow* window);

	// Process user input. Returns true if the app whould quit
	bool ProcessInput();

	// Draw the state's screen
	void Draw();

private:
	sf::RenderWindow* gWindow;
};