#include "stdafx.h"
#include "Piece.h"
#include <iostream>
#include "Game.h"
#include "King.h"

using namespace std;

Piece::Piece(int i, int j, bool colour, Board* chessBoard)
{
	m_i = i;
	m_j = j;
	m_colour = colour;
	m_chessBoard = chessBoard;
}

bool Piece::getColour()
{
 	return m_colour;
}

int Piece::getI()
{
	return m_i;
}

int Piece::getJ()
{
	return m_j;
}

void Piece::setI(int i)						
{
	m_i = i;
}

void Piece::setJ(int j)						
{
	m_j = j;
}

bool Piece::checkConstrainedMove(int iNext, int jNext)
{
	bool checkConstrainedMove = true;

	if (iNext < 0 || jNext < 0 || iNext > 7 || jNext > 7)
	{
		checkConstrainedMove = false;
	}

	return checkConstrainedMove;
}

bool Piece::checkKill(int iNext, int jNext)
{
	bool kill = false;
	
	if (m_chessBoard->getPiece(iNext, jNext) != nullptr && m_chessBoard->getPiece(iNext, jNext)->getColour() != m_colour)
	{
		kill = true;
	}

	return kill;
}


void Piece::recordFirstMove()
{
		pieceMoved = true;
}

bool Piece::checkFirstMove()
{
	return pieceMoved;
}

bool Piece::checkDueToMove(King* king)
{
	/*bool checkDueToMove = false;

	int tempI = m_i, tempJ = m_j;

	Piece* tempAddress = m_chessBoard->getAddress(tempI, tempJ);

	m_chessBoard->tempNull(tempI, tempJ);

	king->checkCheck();

	if (king->returnCheckCondition() == true)
	{
		checkDueToMove = true;
	}
	
	m_chessBoard->reassignAddress(tempAddress, tempI, tempJ);

	return checkDueToMove;*/

	return false;
}

Piece::~Piece()
{

}