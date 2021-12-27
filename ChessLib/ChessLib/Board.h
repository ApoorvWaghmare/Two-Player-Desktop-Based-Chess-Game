#pragma once
#ifndef BOARD_H_
#define BOARD_H_

class Piece;

class Board
{
public:
	Board();
	~Board();
	void set(int i, int j, Piece* piece);
	Piece* getPiece(int i, int j);
	void printBoard();
	void kill(int iNext, int jNext);
	Piece* tempNull(int i, int j);
	void reassignAddress(Piece* tempAddress, int i, int j);
	Piece* getAddress(int i, int j);

protected:

private:
	Piece* m_piecePosition[8][8];	
};

#endif // !BOARD_H_