#include <SFML/Graphics.hpp>

class App {
public:
	App();
	void ProcessArguments(std::string args);
	int Run();
	~App();

private:
	sf::RenderWindow window;
	sf::CircleShape shape;
};