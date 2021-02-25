#include <SFML/Graphics.hpp>
#include "App.h"


App::App()
{

}


void App::ProcessArguments(int argc, char* argv[]) {
    
}

int App::Run() 
{

	// The app started to run
	mRunning = true;

	// Try to open configuration files TODO
	InitSettingsConfig();

	// Set up the window
	InitRenderer();

	// Run game logic
	GameLoop();

	// Do any required cleanup before exiting
	CleanUp();

	// We are no longer running the app
	mRunning=false;

	// Return the exit code given by quit or any error
	return mExitCode;
	
}

void App::InitSettingsConfig(){}
void App::InitRenderer()
{
	// TODO use settings of a settings config file
	mWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Laska");
	mWindow->setFramerateLimit(30);
}

void App::GameLoop() 
{
	// test
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);


	// Make sure we have at least one state active
    if(mStateManager.IsEmpty())
    {
		// Exit with an error since there isn't an active state
		Quit(Codes::StatusAppInitFailed);
    }

	while(mRunning && mWindow->isOpen() && !mStateManager.IsEmpty())
	{
		IState& state = mStateManager.GetActiveState();

		ProcessInput(state);

		// Clear the screen
		mWindow->clear();

		// Let the current game state draw its things
		state.Draw();

		// Display render window to the screen
		mWindow->display();	

		// Handle Cleanup of any recently removed states at this point as needed
		mStateManager.HandleCleanup(); 
	}

	// Main loop TODO mvoe to game class
	while (mWindow->isOpen())
	{
		// Check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (mWindow->pollEvent(event))
		{
			if (event.type == sf::Event::Closed) mWindow->close();
		}
		mWindow->clear();

		// Draw everything
		mWindow->draw(shape);


		mWindow->display();
	}

	// No errors happened. Errors would make this function return before it reaches this line
	mExitCode = Codes::Success;
}

void App::CleanUp() {}

App::~App() 
{
    // Make sure the running flag sets to false
	mRunning = false;
}
