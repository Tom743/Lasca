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
	gWindow->setFramerateLimit(mFrameRateLimit); // This state's frame rate limit
}

bool GameState::ProcessInput()
{
	sf::Vector2f static offset;
	sf::Vector2f oldPos, newPos;
	bool static isMove;
	sf::Event event;
	while (gWindow->pollEvent(event))
	{
		if (event.type == sf::Event::Closed) return true;

		/////drag and drop test//////
		sf::Vector2f mousePos = sf::Vector2f(sf::Mouse::getPosition(*gWindow));

		if (event.type == sf::Event::MouseButtonPressed)
		{
			if (event.mouseButton.button == sf::Mouse::Left)
			{
				if (mTestpiece.GetSprite().getGlobalBounds().contains(mousePos))
				{
					oldPos = mTestpiece.GetSprite().getPosition();
					offset = mousePos-oldPos;
					isMove=true;
				}
			}
		}
		if (event.type == sf::Event::MouseButtonReleased)
		{
			if (event.mouseButton.button == sf::Mouse::Left && isMove)
			{
				newPos = mousePos-offset;
				mTestpiece.SetPosition(newPos);         
				isMove=false;          
			}    
		}
		if (isMove) {
			newPos = mousePos-offset;
			mTestpiece.SetPosition(newPos);  
		}
	}
	return false;
}

void GameState::Draw()
{
	// test
	gWindow->draw(mTestpiece.GetSprite());
}