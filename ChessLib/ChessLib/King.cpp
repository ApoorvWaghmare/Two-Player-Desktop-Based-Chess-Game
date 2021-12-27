#include "stdafx.h"
#include <iostream>
#include <vector>
#include "King.h"
#include "Game.h"

using namespace std;

King::King(int iInitial, int jInitial, bool colour, Board* chessBoard) :
	Piece(iInitial, jInitial, colour, chessBoard)
{

}

bool King::checkValidMove(King* king, int iNext, int jNext)
{
	bool move = false;
	bool checkValidMove = false; 

	checkKill(iNext, jNext);

	if (checkMoveCheck(iNext, jNext) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		if (jNext == m_j && iNext == m_i + 1 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
		{
			checkValidMove = true;
		}

		if (jNext == m_j - 1 && iNext == m_i && m_chessBoard->getPiece(iNext, jNext) == nullptr)
		{
			checkValidMove = true;
		}

		if (jNext == m_j && iNext == m_i - 1 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
		{
			checkValidMove = true;
		}

		if (jNext == m_j + 1 && iNext == m_i && m_chessBoard->getPiece(iNext, jNext) == nullptr)
		{

			checkValidMove = true;
		}

		if (checkValidMove == true && checkConstrainedMove(iNext, jNext) == true)
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

void King::printPiece()
{
	if (m_colour == true)
	{
		cout << "Kin:W";
	}

	if (m_colour == false)
	{
		cout << "Kin:B";
	}
}

bool King::checkMoveCheck(int iNext, int jNext)
{
	bool checkDueToMove = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_chessBoard->getPiece(i, j) != nullptr && m_chessBoard->getPiece(i, j)->getColour() != this->getColour() && m_chessBoard->getPiece(i, j)->checkValidMove(this, iNext, jNext) == true)
			{
				check = true;	
			}
		}
	}

	return checkDueToMove;		
}

void King::checkCheck()			
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_chessBoard->getPiece(i, j) != nullptr && m_chessBoard->getPiece(i, j)->getColour() != this->getColour() && m_chessBoard->getPiece(i, j)->checkValidMove(this, m_i, m_j) == true)
			{
				check = true;
			}
		}
	}	
}

bool King::returnCheckCondition()
{
	return check;
}

bool King::returnCheckMateCondition()
{
	return checkMate;
}

void King::setCheckMateCondition(bool mate)
{
	checkMate = mate;
}

King::~King()
{

}