#include "GameState.h"

GameState::GameState()
{

}

GameState::~GameState()
{

}

void GameState::Init(sf::RenderWindow* window)
{
	gWindow = window;
}

bool GameState::ProcessInput()
{
	sf::Event event;
	while (gWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) return true;
	}
	return false;
}

void GameState::Draw()
{
	// test
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	
	gWindow->draw(shape);
}