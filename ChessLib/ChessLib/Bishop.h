#pragma once
#ifndef BISHOP_H_
#define BISHOP_H_
#include "Piece.h"
#include "Board.h"

class Bishop : public Piece
{ 
public:
	Bishop(int iInitial, int jInitial, bool colour, Board* chessBoard);
	~Bishop();
	bool checkValidMove(King* king, int iNext, int jNext);
	void printPiece();

protected:

private:

};

#endif // !BISHOP_H_