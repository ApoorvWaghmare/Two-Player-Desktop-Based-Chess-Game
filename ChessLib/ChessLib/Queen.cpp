#include "stdafx.h"
#include <iostream>
#include "Queen.h"
#include "MoveChecker.h"


using namespace std;

Queen::Queen(int iInitial, int jInitial, bool colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

bool Queen::checkValidMove(King* king, int iNext, int jNext)
{
	bool move = false;

	MoveChecker checkMove;

	if (checkDueToMove(king) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		move = checkMove.checkNullPtr(this, m_chessBoard, iNext, jNext);
	}

	return move;
}

void Queen::printPiece()
{
	if (m_colour == true)
	{
		cout << "Que:W";
	}

	if (m_colour == false)
	{
		cout << "Que:B";
	}
}

Queen::~Queen()
{

}