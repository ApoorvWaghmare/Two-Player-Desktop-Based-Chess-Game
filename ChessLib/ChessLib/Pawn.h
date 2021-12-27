#pragma once
#ifndef PAWN_H_
#define PAWN_H_
#include "Piece.h"
#include "Board.h"

class Pawn : public Piece
{
public:
	Pawn(int iInitial, int jInitial, bool colour, Board* chessBoard);
	~Pawn();
	bool checkValidMove(King* king, int iNext, int jNext); //bool = false : dont move, bool = true : move
	void printPiece();
	
protected:

private:

};	

#endif // !

