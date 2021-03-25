#include "Board.h"

// Validates and performes moves
class Mover {
public:
	Mover();
	
	// Checks if a move is valid
	bool ValidateMove(Cell& from, Cell& to, Board& board);
	// Validates moves and if valid, performs it
	bool ValidateAndMove(Cell& from, Cell& to, Board& board);
private:
	// Checks if two cells are diagonal to each other
	bool AreDiagonal(Cell& c1, Cell&c2);
	// Checks if it is possible for the player to capture an enemy tower
	bool AreAnyTakesAvailable(bool color, Board& board);
};