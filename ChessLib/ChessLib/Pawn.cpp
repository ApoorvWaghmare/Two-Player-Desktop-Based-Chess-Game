#include "stdafx.h"
#include <iostream>
#include "Pawn.h"
#include "Board.h"

using namespace std;

Pawn::Pawn(int iInitial, int jInitial, bool colour, Board* chessBoard) : 
	Piece(iInitial, jInitial, colour, chessBoard)		
{

}

bool Pawn::checkValidMove(King* king, int iNext, int jNext)
{
	bool move = false;
	bool checkNull = true;		

	if (checkDueToMove(king) == false && (m_chessBoard->getPiece(iNext, jNext) == nullptr || m_chessBoard->getPiece(iNext, jNext)->getColour() != this->getColour()))
	{
		if (checkNull == true && checkConstrainedMove(iNext, jNext) == true)
		{
			if (m_colour == true)
			{
				if (m_i == 1 && jNext == m_j && iNext == m_i + 2 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
				{
					move = true;
				}
				else if (jNext == m_j && iNext == m_i + 1 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
				{
					move = true;
				}
				else if (jNext == m_j - 1 && iNext == m_i + 1)
				{
					if (m_chessBoard->getPiece(iNext, jNext) == nullptr)
					{
						move = false;
					}
					else if (m_chessBoard->getPiece(iNext, jNext)->getColour() != m_colour)
					{
						move = true;
					}
				}
				else if (jNext == m_j + 1 && iNext == m_i + 1)
				{
					if (m_chessBoard->getPiece(iNext, jNext) == nullptr)
					{
						move = false;
					}
					else if (m_chessBoard->getPiece(iNext, jNext)->getColour() != m_colour)
					{
						move = true;
					}
				}
			}
			else //m_colour == false
			{
				if (m_i == 6 && jNext == m_j && iNext == m_i - 2 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
				{
					move = true;
				}
				else if (jNext == m_j && iNext == m_i - 1 && m_chessBoard->getPiece(iNext, jNext) == nullptr)
				{
					move = true;
				}
				else if (jNext == m_j + 1 && iNext == m_i - 1)
				{
					if (m_chessBoard->getPiece(iNext, jNext) == nullptr)
					{
						move = false;
					}
					else if (m_chessBoard->getPiece(iNext, jNext)->getColour() != m_colour)
					{
						move = true;
					}
				}
				else if (jNext == m_j - 1 && iNext == m_i - 1)
				{
					if (m_chessBoard->getPiece(iNext, jNext) == nullptr)
					{
						move = false;
					}
					else if (m_chessBoard->getPiece(iNext, jNext)->getColour() != m_colour)
					{
						move = true;
					}
				}
			}
		}
	}

	return move;
}

void Pawn::printPiece()
{
	if (m_colour == true)		
	{
		cout << "Paw:W";
	}

	if (m_colour == false)
	{
		cout << "Paw:B";
	}
}

Pawn::~Pawn()
{

}