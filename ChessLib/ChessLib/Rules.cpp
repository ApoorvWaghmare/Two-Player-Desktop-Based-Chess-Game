#include "stdafx.h"
#include "Rules.h"
#include <iostream>
#include "Pawn.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "King.h"
#include "Game.h"

using namespace std;

Rules::Rules()			
{

}

Piece* Rules::promotionRule(Pawn* pawn, Board* chessBoard)
{
	cout << "Press 1 for QUEEN" << endl;
	cout << "Press 2 for BISHOP" << endl;
	cout << "Press 3 for KNIGHT" << endl;
	cout << "Press 4 for ROOK" << endl;

	int num;
	cin >> num;

	Piece* upgradedPiece = nullptr;

	if (pawn->getColour() == true)
	{
		if (num == 1)
		{
			upgradedPiece = new Queen(7, pawn->getJ(), true, chessBoard);
		}
		else if (num == 2)
		{
			upgradedPiece = new Bishop(7, pawn->getJ(), true, chessBoard);
		}
		else if (num == 3)
		{
			upgradedPiece = new Knight(7, pawn->getJ(), true, chessBoard);
		}
		else // if (num == 4)
		{
			upgradedPiece = new Rook(7, pawn->getJ(), true, chessBoard);
		}
	}
	else if (pawn->getColour() == false)
	{
		if (num == 1)
		{
			upgradedPiece = new Queen(0, pawn->getJ(), false, chessBoard);
		}
		else if (num == 2)
		{
			upgradedPiece = new Bishop(0, pawn->getJ(), false, chessBoard);
		}
		else if (num == 3)
		{
			upgradedPiece = new Knight(0, pawn->getJ(), false, chessBoard);
		}
		else // if (num == 4)
		{
			upgradedPiece = new Rook(0, pawn->getJ(), false, chessBoard);
		}
	}
	else
	{
		cout << "Invlaid selection" << endl;
	}

	return upgradedPiece;
}

int Rules::checkCastleCondition(King* king, Rook* leftRook, Rook* rightRook, Board* chessBoard)
{
	int typeOfCastle;

	if (king->getColour() == true)
	{
		if (king->checkFirstMove() == false && leftRook->checkFirstMove() == false && chessBoard->getPiece(0, 1) == nullptr && chessBoard->getPiece(0, 2) == nullptr && chessBoard->getPiece(0, 3) == nullptr)
		{
			typeOfCastle = 1; //left castle
			castlePossible = true;
		}
		else if ((king->checkFirstMove() == false && leftRook->checkFirstMove() == false && chessBoard->getPiece(0, 1) == nullptr && chessBoard->getPiece(0, 2) == nullptr && chessBoard->getPiece(0, 3) == nullptr) && (king->checkFirstMove() == false && rightRook->checkFirstMove() == false && chessBoard->getPiece(0, 5) == nullptr && chessBoard->getPiece(0, 6) == nullptr))
		{
			typeOfCastle = 3; //both castles possible
			castlePossible = true;
		}
		if (king->checkFirstMove() == false && rightRook->checkFirstMove() == false && chessBoard->getPiece(0, 5) == nullptr && chessBoard->getPiece(0, 6) == nullptr)
		{
			typeOfCastle = 2; //right castle
			castlePossible = true;
		}
		
	}
	else if (king->getColour() == false)
	{
		if (king->checkFirstMove() == false && leftRook->checkFirstMove() == false && chessBoard->getPiece(7, 1) == nullptr && chessBoard->getPiece(7, 2) == nullptr && chessBoard->getPiece(7, 3) == nullptr)
		{
			typeOfCastle = 2; //right castle
			castlePossible = true;
		}
		else if ((king->checkFirstMove() == false && leftRook->checkFirstMove() == false && chessBoard->getPiece(7, 1) == nullptr && chessBoard->getPiece(7, 2) == nullptr && chessBoard->getPiece(7, 3) == nullptr) && (king->checkFirstMove() == false && rightRook->checkFirstMove() == false && chessBoard->getPiece(7, 5) == nullptr && chessBoard->getPiece(7, 6) == nullptr))
		{
			typeOfCastle = 3; //both castles possible
			castlePossible = true;
		}
		if (king->checkFirstMove() == false && rightRook->checkFirstMove() == false && chessBoard->getPiece(7, 5) == nullptr && chessBoard->getPiece(7, 6) == nullptr)
		{
			typeOfCastle = 1; //left castle
			castlePossible = true;
		}
	}
	else
	{
		typeOfCastle = 0;
	}

	return typeOfCastle;
}

Rules::~Rules()
{

}
