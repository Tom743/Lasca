#include <SFML/Graphics.hpp>
#include "Codes.h"
#include "GameState.h"

class App {
public:
	App();
	void ProcessArguments(int argc, char* argv[]);
	int Run();
	void Quit();
	~App();

	// The window to display
	sf::RenderWindow *mWindow;

private:
	// Running flag. Set to true when App::Run starts excecuting
	// and to false when it finishes.
	bool mRunning = false;

	// Whenever an anomaly occurs, change this to the respective code
	int mExitCode = codes::ExitStatus::StatusNoError;

private:
	// TODO move to state manager or sth
	GameState mMainState = GameState();

	void InitRenderer();
	void GameLoop();
	void CleanUp();
};