#pragma once
#ifndef PIECE_H_
#define PIECE_H_
#include "Board.h"

class King;

class Piece
{
public:
	Piece(int i, int j, bool colour, Board* chessBoard);
	virtual ~Piece();
	bool getColour(); 
	int getI();		
	int getJ();
	void setI(int i);
	void setJ(int j);	
	virtual bool checkValidMove(King* king, int iNext, int jNext) = 0; 
	bool checkConstrainedMove(int iNext, int jNext);
	bool checkKill(int iNext, int jNext);
	void recordFirstMove();
	bool checkFirstMove();
	bool checkDueToMove(King* king);
	virtual void printPiece() = 0;
	
protected:
	int m_i;
	int m_j;
	bool m_colour; //true = white, false = black
	Board* m_chessBoard;
	bool pieceMoved = false;

private:
	
};

#endif // !PIECE_H_
