#include "Mover.h"

using namespace codes;

Mover::Mover() {
    
}

bool Mover::ValidateMove(Cell& from, Cell& to, Board& board, bool move)
{
	// Color of the moving tower
	bool color = from.GetTop()->GetColor();

	// If there already are some pieces
	if (!to.GetTower().empty()) return false;

	// If these cells are not diagonal to each other
	if (!AreDiagonal(from, to))
	{
		// Can't be valid
		return false;
	} else {
		// If the piece to move is a king, allow to move longer
		if (from.GetTop()->IsKing()) 
		{
			// TODO complete this section
			return false;
		} else {
			// Is it trying to move backwards?
			int direction = color==Colors::Black ? 1 : -1;
			if (to.GetID().y*direction > from.GetID().y*direction) return false;
			// Is it trying to move long distance (without a king)?
			else if (abs(to.GetID().y-from.GetID().y) > 2) return false;
			// Is it trying to just move?
			else if (abs(to.GetID().y-from.GetID().y) == 1)
			{
				// Is it trying to move without taking
				if (AreAnyTakesAvailable(color, board)) return false;
				else {
					if (move) Move(&to, &from);
					return true;
				}
			}
			// Is it trying to take a piece of the same color?
			else if (board.GetCellByID(CellID((from.GetID().x+to.GetID().x)/2, (from.GetID().y+to.GetID().y)/2))
					->GetTop()->GetColor() == color) return false;
		}
	}

	// If we got here it means it is legal and we take
	if (move)
	{
		Cell* takenCell = board.GetCellByID(CellID((from.GetID().x+to.GetID().x)/2, (from.GetID().y+to.GetID().y)/2));
		Move(&to, &from, takenCell);
	}
	return true;
}

void Mover::Move(Cell* to, Cell* from, Cell* taken)
{
	// Move the pieces to their new place
	if (taken!=nullptr) from->PushPiece(taken->PopPiece());
	to->PutTower(from->GetTower());
	from->CleanTower();
	for (Piece* p : to->GetTower())
		p->AttachToCell(to); // TODO put the attach to cell thing into puttower?

	// Make the tower a king if reaches the back rank
	if (to->GetID().y == (to->GetTop()->GetColor()==codes::Colors::Black ? 0 : 6))
		to->GetTop()->SetKing();
}

bool Mover::AreAnyTakesAvailable(bool color, Board& board)
{
	// TODO kings
	for (std::vector<Cell*> r : board.GetCells()) for (Cell* c : r)
	{
		// Check if this piece can capture
		// TODO What if I store the number of pieces of each player to reduce the length of this loop?
		if (c->GetTop()) if (c->GetTop()->GetColor()==color)
		{
			int advance = color==Colors::Black ? -1 : 1; // The direction towards which the piece advances
			int captureRow = c->GetID().y + advance; // Row where the capture may occur
			if (1 <= captureRow and captureRow <= 5) // Can't land outside the board when capturing
			{
				int cCol = c->GetID().x; // Column where the tower that might be able to capture is before moving

				// Theoretical capture on diagonal to the right (from white's perspective)
				if (cCol<5) // Can't land outside the board when capturing
				{
					// If the piece where the capture may land is empty
					if (board.GetCellByID(CellID(cCol+2, captureRow+advance))->GetTop() == nullptr)
					{
						// Piece to be captured
						Piece* plusoneTop = board.GetCellByID(CellID(cCol+1, captureRow))->GetTop();

						// If there is something to capture and is an enemy
						if (plusoneTop != nullptr) if (plusoneTop->GetColor() != color)
							return true;
					}
				}

				// Theoretical capture on diagonal to the left (from white's perspective)
				if (cCol>1) // Can't land outside the board when capturing
				{
					if (board.GetCellByID(CellID(cCol-2, captureRow+advance))->GetTop() == nullptr)
					{
						Cell* minusone = board.GetCellByID(CellID(cCol-1, captureRow));
						Piece* minusoneTop = minusone->GetTop();
						bool m = minusoneTop == nullptr;
						if (minusoneTop != nullptr) if (minusoneTop->GetColor() != color) 
							return true;
					}
				}
			}
		}
	}
	return false;
}

bool Mover::AreDiagonal(Cell& c1, Cell&c2)
{
	CellID ID1 = c1.GetID();
	CellID ID2 = c2.GetID();
	if (abs(ID1.x-ID2.x) == abs(ID1.y-ID2.y)) return true;
	return false;
}
