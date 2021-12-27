#pragma once
#ifndef KING_H_
#define KING_H_
#include "Board.h"
#include "Piece.h"

class King : public Piece	
{
public:
	King(int iInitial, int jInitial, bool colour, Board* chessBoard);
	~King();
	bool checkValidMove(King* king, int iNext, int jNext);
	void printPiece();
	void checkCheck(); 
	bool checkMoveCheck(int iNext, int jNext);
	bool returnCheckCondition();
	bool returnCheckMateCondition();
	void setCheckMateCondition(bool mate);

protected:

private:
	bool check = false;
	bool checkMate = false;
	bool staleMate = false;

};

#endif // !KING_H_

