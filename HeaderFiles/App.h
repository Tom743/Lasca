#include <SFML/Graphics.hpp>
#include "Codes.h"
#include "StateManager.h"

class App {
public:
	App();
	void ProcessArguments(int argc, char* argv[]);
	int Run();
	~App();

private:
	// Running flag. Set to true when App::Run starts excecuting
	// and to false when it finishes.
	bool mRunning = false;

	// Whenever an anomaly occurs, change this to the respective code
	int mExitCode = Codes::StatusNoError;

	// To store all the states and process the active state only
	StateManager mStateManager = StateManager();

	// Renderer assets TODO move to renderer or whatever
	sf::RenderWindow *mWindow;

private:
	void InitSettingsConfig();
	void InitRenderer();
	void GameLoop();
	void CleanUp();
};