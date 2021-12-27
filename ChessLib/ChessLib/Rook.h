#pragma once
#ifndef ROOK_H_
#define ROOK_H_
#include "Piece.h"
#include "Board.h"

class Rook : public Piece
{
public:
	Rook(int iInitial, int jInitial, bool colour, Board* board);
	~Rook();
	bool checkValidMove(King* king, int iNext, int jNext); //bool = false : not valid, bool = true : valid
	void printPiece();

protected:

private:
	
};

#endif // !ROOKE_H_

