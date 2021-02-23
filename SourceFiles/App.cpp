#include <SFML/Graphics.hpp>
#include "App.h"


App::App() {

}


void App::ProcessArguments(std::string args) {
    
}

int App::Run() {

    sf::RenderWindow window(sf::VideoMode(200, 200), "Laska");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}

App::~App() {
    
}
