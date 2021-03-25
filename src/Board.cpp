#include "Board.h"

Board::Board() 
{
}

void Board::Init(int mCellSize)
{
	// IDs from left to right, bottom to top
	for (int i=0; i<7; i++) {
		mBoardCells.push_back({});
		for (int j=0; j<3+!(i%2); j++) {
			sf::Vector2f pos = sf::Vector2f(j*mCellSize*2+(i%2)*mCellSize, mCellSize*(6-i));
			Cell* cell = new Cell(mCellSize, pos, codes::CellID((j*2+i%2), i));
			mBoardCells[i].push_back(cell);
			if (i!=3) cell->PushPiece(new Piece(i>3, cell));
		}
	}
}

Cell* Board::GetCellByID(codes::CellID ID)
{
	int x = (ID.x-(ID.y%2))/2;
	int y = ID.y;
	return mBoardCells[y][x];
}

std::vector<std::vector<Cell*>> Board::GetCells()
{
	return mBoardCells;
}
