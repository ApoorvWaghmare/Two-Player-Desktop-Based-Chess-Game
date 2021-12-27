#include "stdafx.h"
#include "Bishop.h"
#include <iostream>
#include "MoveChecker.h"

using namespace std;

Bishop::Bishop(int iInitial, int jInitial, bool colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{
	
}

bool Bishop::checkValidMove(King* king, int iNext, int jNext)						
{
	bool move = false;

	MoveChecker checkMove; 

	if (checkDueToMove(king) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		if (abs(iNext - m_i) == abs(jNext - m_j))
		{
			move = checkMove.checkNullPtr(this, m_chessBoard, iNext, jNext);
		}
	}

	return move;
}

void Bishop::printPiece()
{
	if (m_colour == true)
	{
		cout << "Bis:W";
	}

	if (m_colour == false)
	{
		cout << "Bis:B";
	}
}

Bishop::~Bishop()
{

}

