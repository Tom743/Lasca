#include "Board.h"

// Validates and performes moves
class Mover {
public:
	Mover();
	// Checks if a move is valid. If move, it will perform the move on the board
	bool ValidateMove(Cell& from, Cell& to, Board& board, bool move);
private:
	// Checks if two cells are diagonal to each other
	bool AreDiagonal(Cell& c1, Cell&c2);
	// Checks if it is possible for the player to capture an enemy tower
	bool AreAnyTakesAvailable(bool color, Board& board);
};