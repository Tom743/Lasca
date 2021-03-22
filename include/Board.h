#include <vector>
#include "Piece.h"

// The cells of the board. Each cell contains its pieces
// Board.GetCells()[row][not column but index of cell in this row]
// TODO make accessible with ID
class Board {
public:
	Board();

	// Initiate the board
	void Init(int mCellSize);
	// Get a 2D matrix array with all the cells
	std::vector<std::vector<Cell*>> GetCells();
	// Get a pointer to the cell using an ID.
	Cell* GetCellByID(codes::CellID ID);
private:
	std::vector<std::vector<Cell*>> mBoardCells;
};