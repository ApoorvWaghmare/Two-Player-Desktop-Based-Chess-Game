#include "stdafx.h"
#include "Rook.h"
#include <iostream>
#include "MoveChecker.h"

using namespace std;
 
Rook::Rook(int iInitial, int jInitial, bool colour, Board* chessBoard) : 
	Piece(iInitial, jInitial, colour, chessBoard)
{
	
}

bool Rook::checkValidMove(King* king, int iNext, int jNext)
{
	bool move = false;							

	MoveChecker checkMove;

	if (checkDueToMove(king) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		if (iNext == m_i || jNext == m_j)
		{
			move = checkMove.checkNullPtr(this, m_chessBoard, iNext, jNext);
		}
	}
	else
	{
		move = false;
	}

	return move;
}

void Rook::printPiece()
{
	if (m_colour == true)
	{
		cout << "Roo:W";
	}

	if (m_colour == false)
	{
		cout << "Roo:B";
	}
}

Rook::~Rook()
{

}