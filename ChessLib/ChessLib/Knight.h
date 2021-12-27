#pragma once
#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "Piece.h"
#include "Board.h"

class Knight : public Piece
{
public:
	Knight(int iInitial, int jInitial, bool colour, Board* chessBoard);
	~Knight();
	bool checkValidMove(King* king, int iNext, int jNext);
	void printPiece();

protected:

private:

};

#endif // !KNIGHT_H_
