#include <SFML/Graphics.hpp>
#include "Codes.h"

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

	// Renderer assets TODO move to renderer or whatever
	sf::RenderWindow *mWindow;

private:
	void InitRenderer();
	void GameLoop();
	void ProcessInput();
	void Draw();
	void CleanUp();
};