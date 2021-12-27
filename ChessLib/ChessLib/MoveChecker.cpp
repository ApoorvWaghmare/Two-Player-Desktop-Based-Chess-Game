#include "stdafx.h"
#include <iostream>
#include "MoveChecker.h"
#include "Piece.h"
#include "Board.h"

using namespace std;

MoveChecker::MoveChecker()
{

}

bool MoveChecker::checkNullPtr(Piece* piece, Board* chessBoard, int iNext, int jNext)
{
	int a = 0;
	bool checkNullPtr = true;

	Piece* nextPiece = chessBoard->getPiece(iNext, jNext);

	if (nextPiece != nullptr && nextPiece->getColour() == piece->getColour())
	{
		checkNullPtr = false;
	}
	
	if (checkNullPtr == true)				
	{
		a = 1;
		if (jNext == piece->getJ())	//vertical movement		
		{
			if (iNext > piece->getI()) ///up
			{
				a = 2;
				for (int i = piece->getI() + 1; i < iNext; i++)
				{
					if (chessBoard->getPiece(i, piece->getJ()) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
			else if (iNext < piece->getI()) ///down
			{
				a = 3;
				for (int i = piece->getI() - 1; i > iNext; i--)
				{
					if (chessBoard->getPiece(i, piece->getJ()) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
		}
		else if (iNext == piece->getI()) //horizontal movement
		{
			if (jNext > piece->getJ()) ///left
			{
				a = 4;
				for (int i = piece->getJ() + 1; i < jNext; i++)
				{
					if (chessBoard->getPiece(piece->getI(), i) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
			else if (jNext < piece->getJ()) ///right
			{
				a = 5;
				for (int i = piece->getJ() - 1; i > jNext; i++)
				{
					if (chessBoard->getPiece(piece->getI(), i) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
		}
		else if (iNext - piece->getI() == jNext - piece->getJ()) //diagonal movement 45 degree
		{
			if (iNext > piece->getI() && jNext > piece->getJ()) ///north-east
			{
				a = 6;
				for (int i = piece->getI() + 1, j = piece->getJ() + 1; i < iNext, j < jNext; i++, j++)
				{
					if (chessBoard->getPiece(i, j) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
			else if (iNext < piece->getI() && jNext < piece->getJ()) ///south-west
			{
				a = 7;
				for (int i = piece->getI() - 1, j = piece->getJ(); i > iNext, j > jNext; i--, j--)
				{
					if (chessBoard->getPiece(i, j) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
		}
		else if (iNext - piece->getI() == -(jNext - piece->getJ())) //diagonal movement 135 degree
		{
			if (iNext > piece->getI() && jNext < piece->getJ()) ///north-west
			{
				a = 8;
				for (int i = piece->getI() + 1, j = piece->getJ() - 1; i < iNext, j > jNext; i++, j--)
				{
					if (chessBoard->getPiece(i, j) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
			else if (iNext < piece->getI() && jNext > piece->getJ()) ///south-east
			{
				a = 9;
				for (int i = piece->getI() - 1, j = piece->getJ() + 1; i > iNext, j < jNext; i--, j++)
				{
					if (chessBoard->getPiece(i, j) != nullptr)
					{
						checkNullPtr = false;
						break;
					}
				}
			}
		}
		else
		{
			checkNullPtr = false;
		}
	}

	return checkNullPtr;
}

MoveChecker::~MoveChecker()
{

}