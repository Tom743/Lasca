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
			if (to.GetID().y()*direction > from.GetID().y()*direction) return false;
			// Is it trying to move long distance (without a king)?
			else if (abs(to.GetID().y()-from.GetID().y()) > 2) return false;
			// Is it trying to just move?
			else if (abs(to.GetID().y()-from.GetID().y()) == 1)
			{
				// Is it trying to move without taking
				if (AreAnyTakesAvailable(color, board)) return false;
				else {
					if (move) Move(&to, &from);
					return true;
				}
			}
			// Is it trying to take a piece of the same color?
			else if (board.GetCellByID(CellID((from.GetID().x()+to.GetID().x())/2, (from.GetID().y()+to.GetID().y())/2))
					->GetTop()->GetColor() == color) return false;
		}
	}

	// If we got here it means it is legal and we take
	if (move)
	{
		Cell* takenCell = board.GetCellByID(CellID((from.GetID().x()+to.GetID().x())/2, (from.GetID().y()+to.GetID().y())/2));
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
	if (to->GetID().y() == (to->GetTop()->GetColor()==codes::Colors::Black ? 0 : 6))
		to->GetTop()->SetKing();
}

bool Mover::AreAnyTakesAvailable(bool color, Board& board)
{
	for (std::vector<Cell*> r : board.GetCells()) for (Cell* c : r)
	{
		// TODO What if I store the number of pieces of each player to reduce the length of this loop?
		if (c->GetTop()) if (c->GetTop()->GetColor()==color)
		{
			// Check if this piece can capture
			CellID position = c->GetID();
			Piece* piece = c->GetTop();
			bool isKing = piece->IsKing();

			int i = 0, ii = 3;
			if (!isKing)
			{
				// Limit Y movement for its color 
				if (color == Colors::White) i=2;
				else ii=1;
			}
			for (; i<=ii; i++)
			{
				int x_dir =      (i&1) == 0 ? -1 : 1; // LSB of 0 to 3 represents x direction, -1 or 1
				int y_dir = ((i&2)>>1) == 0 ? -1 : 1; // MSB is y
				int x_now = position.x()+x_dir;
				int y_now = position.y()+y_dir;

				// Iterate over the diagonal
				while (1 <= x_now and 1 <= y_now and 5 >= x_now and 5 >= y_now)
				{
					if (board.GetCellByID(CellID(x_now, y_now))->GetTop()) // If is not empty, there might be an enemy
					{
						if (board.GetCellByID(CellID(x_now, y_now))->GetTop()->GetColor() == color) break; // Can't jump over a friend
						else { // It is an enemy
							// May be possible to jump over this one
							x_now = x_now + x_dir;
							y_now = y_now + y_dir;

							if (board.GetCellByID(CellID(x_now, y_now))->GetTop() == nullptr) return true; // Is empty, can take
							else break;
						}
					}
					if (!isKing) break; // Only kings move before taking 
					x_now = x_now + x_dir;
					y_now = y_now + y_dir;
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
	if (abs(ID1.x()-ID2.x()) == abs(ID1.y()-ID2.y())) return true;
	return false;
}
