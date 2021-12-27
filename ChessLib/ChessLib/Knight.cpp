#include "stdafx.h"
#include <iostream>
#include "Knight.h"

using namespace std;

Knight::Knight(int iInitial, int jInitial, bool colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

bool Knight::checkValidMove(King* king, int iNext, int jNext)
{
	bool move = false;
	bool checkNull = true;

	checkKill(iNext, jNext);

	if (checkDueToMove(king) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		if (iNext == m_i + 2 && jNext == m_j + 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)			
			{
				checkNull = false;
			}
		}

		if (iNext == m_i + 2 && jNext == m_j - 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (jNext == m_j - 2 && iNext == m_i + 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (iNext == m_i - 2 && jNext == m_j - 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (iNext == m_i - 2 && jNext == m_j + 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (jNext == m_j + 2 && iNext == m_i - 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (jNext == m_j + 2 && iNext == m_i + 1)
		{
			if (m_chessBoard->getPiece(iNext, jNext) != nullptr)
			{
				checkNull = false;
			}
		}

		if (checkNull == true && checkConstrainedMove(iNext, jNext) == true)
		{
			move = true;
		}
	}
	else
	{
		move = false;
	}

	return move;
}

void Knight::printPiece()
{
	if (m_colour == true)
	{
		cout << "Kni:W";
	}

	if (m_colour == false)
	{
		cout << "Kni:B";
	}
}

Knight::~Knight()
{

}