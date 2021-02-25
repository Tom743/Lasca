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
	// TODO use settings of a settings config file
	mWindow = new sf::RenderWindow(sf::VideoMode(200, 200), "Laska");
	mWindow->setFramerateLimit(30);
}

void App::GameLoop() 
{

	while(mRunning && mWindow->isOpen())
	{
		// Input processing loop
		ProcessInput();

		// Clear the screen
		mWindow->clear();

		// Let the current game state draw its things
		Draw();

		// Display render window to the screen
		mWindow->display();	

		// Handle Cleanup of any recently removed states at this point as needed
		CleanUp(); 
	}

	// No errors happened. Errors would make this function return before it reaches this line
	mExitCode = Codes::Success;
}

void App::ProcessInput()
{
	// Check all the window's events that were triggered since the last iteration of the loop
	sf::Event event;
	while (mWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) mWindow->close();
	}
}

void App::Draw()
{
	// test
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

	// Draw everything
	mWindow->draw(shape);
}

void App::CleanUp() {}

App::~App() 
{
    // Make sure the running flag sets to false
	mRunning = false;
}
