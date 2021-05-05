#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Codes.h"

// Bottom Bar. Meant to contain all elements such as indicators or stats. Only a square now
class BBar {
public:
	BBar();

	// Change the color of the player on turn indicator. If not specified, changes it to the opposite color.
	void ChangePlayerColor(bool color);
	void ChangePlayerColor();

	// Call this method to draw all the elements on the BBar.
	void Draw(sf::RenderWindow* window);

	~BBar();

private:
	sf::RectangleShape mRectangleShape;

	bool mCurrentPlayer;

	// The color that the turn indicator will show
	sf::Color mWhiteColor = sf::Color(239, 239, 239);
	sf::Color mBlackColor = sf::Color(53, 53, 53);
};