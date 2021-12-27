#pragma once
#ifndef QUEEN_H_
#define QUEEN_H_
#include "Board.h"
#include "Piece.h"

class Queen : public Piece
{
public:
	Queen(int iInitial, int jInitial, bool colour, Board* chessBoard);
	~Queen();
	bool checkValidMove(King* king, int iNext, int jNext);
	void printPiece();

protected:

private:

};

#endif // !QUEEN_H_

