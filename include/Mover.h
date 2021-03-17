#include "Board.h"

// Validates and if possible performs the move
class Mover {
public:
	Mover();
	
	// Checks if a move is valid
	bool ValidateMove(Cell& from, Cell& to, Board& board);
};