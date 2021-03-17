#include "Board.h"
#include "Piece.h"


Board::Board() 
{
}

void Board::Init(int mCellSize)
{
	for (int i=0; i<7; i++) {
		mBoardCells.push_back({});
		for (int j=0; j<3+!(i%2); j++) {
			sf::Vector2f pos = sf::Vector2f(j*mCellSize*2+(i%2)*mCellSize, i*mCellSize);
			Cell* cell = new Cell(mCellSize, pos, codes::CellID(7-(j*2+i%2), 7-i));
			mBoardCells[i].push_back(cell);
			if (i!=3) cell->PushPiece(new Piece(i<3, cell));
		}
	}
}

std::vector<std::vector<Cell*>> Board::GetCells()
{
	return mBoardCells;
}
