#include <SFML/Graphics.hpp>
#include "App.h"

/*
TODO: Implement a statemanager and game states, move the input processing loop and draw functions 
to each state and call them form the state manager
*/


App::App()
{
	
}


void App::ProcessArguments(int argc, char* argv[]) {
    
}

int App::Run() 
{

	// The app started to run
	mRunning = true;

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

void App::InitRenderer()
{
	// TODO get settings from config file
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	mWindow = new sf::RenderWindow(sf::VideoMode(700, 700), "Lasca", sf::Style::Titlebar | sf::Style::Close, settings);
	mWindow->setPosition(sf::Vector2i(10, 50));
	mWindow->setFramerateLimit(30);  // Initial framerate. Can be changed by the states
}

void App::GameLoop() 
{
	// TODO make statemanager take care of init and every other thing about gamestates
	mMainState.Init(mWindow);

	while(mRunning && mWindow->isOpen())
	{
		// Input processing loop
		bool quit = mMainState.ProcessInput();
		if (quit) mWindow->close();

		// Clear the screen
		mWindow->clear(mMainState.getBackGroundColor());

		// Let the current game state draw its things
		mMainState.Draw();

		// Display render window to the screen
		mWindow->display();	

		// Handle Cleanup of any recently removed states at this point as needed
		CleanUp(); 
	}

	// No errors happened. Errors would make this function return before it reaches this line
	mExitCode = codes::ExitStatus::Success;
}

void App::CleanUp() {}

App::~App() 
{
    // Make sure the running flag sets to false
	mRunning = false;
}
