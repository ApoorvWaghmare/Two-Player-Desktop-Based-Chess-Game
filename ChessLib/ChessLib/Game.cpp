#include "stdafx.h"
#include <iostream>
#include <assert.h>
#include "Game.h"
#include "Board.h" 
#include "Pawn.h"				
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Piece.h"
#include "Player.h"
#include "Rules.h"

using namespace std;

Game::Game()
{
	m_chessBoard = new Board;
	                           
//Creating white pieces
	m_chessGamePieces[0] = new Pawn(1, 0, true, m_chessBoard);
	m_chessBoard->set(1, 0, m_chessGamePieces[0]);
	m_chessGamePieces[1] = new Pawn(1, 1, true, m_chessBoard);	
	m_chessBoard->set(1, 1, m_chessGamePieces[1]);
	m_chessGamePieces[2] = new Pawn(1, 2, true, m_chessBoard);
	m_chessBoard->set(1, 2, m_chessGamePieces[2]);
	m_chessGamePieces[3] = new Pawn(1, 3, true, m_chessBoard);
	m_chessBoard->set(1, 3, m_chessGamePieces[3]);
	m_chessGamePieces[4] = new Pawn(1, 4, true, m_chessBoard);
	m_chessBoard->set(1, 4, m_chessGamePieces[4]);
	m_chessGamePieces[5] = new Pawn(1, 5, true, m_chessBoard);
	m_chessBoard->set(1, 5, m_chessGamePieces[5]);
	m_chessGamePieces[6] = new Pawn(1, 6, true, m_chessBoard);
	m_chessBoard->set(1, 6, m_chessGamePieces[6]);
	m_chessGamePieces[7] = new Pawn(1, 7, true, m_chessBoard);
	m_chessBoard->set(1, 7, m_chessGamePieces[7]);

	m_chessGamePieces[8] = m_whiteKing = new King(0, 4, true, m_chessBoard);
	m_chessBoard->set(0, 4, m_chessGamePieces[8]);
	
	m_chessGamePieces[9] = new Queen(0, 3, true, m_chessBoard);
	m_chessBoard->set(0, 3, m_chessGamePieces[9]);

	m_chessGamePieces[10] = new Knight(0, 1, true, m_chessBoard);
	m_chessBoard->set(0, 1, m_chessGamePieces[10]);
	m_chessGamePieces[11] = new Knight(0, 6, true, m_chessBoard);
	m_chessBoard->set(0, 6, m_chessGamePieces[11]);

	m_chessGamePieces[12] = new Bishop(0, 2, true, m_chessBoard);
	m_chessBoard->set(0, 2, m_chessGamePieces[12]);
	m_chessGamePieces[13] = new Bishop(0, 5, true, m_chessBoard);
	m_chessBoard->set(0, 5, m_chessGamePieces[13]);

	m_chessGamePieces[14] = m_leftWhiteRook = new Rook(0, 0, true, m_chessBoard);
	m_chessBoard->set(0, 0, m_chessGamePieces[14]);
	m_chessGamePieces[15] = m_rightWhiteRook = new Rook(0, 7, true, m_chessBoard);
	m_chessBoard->set(0, 7, m_chessGamePieces[15]);

//Creating black pieces
	m_chessGamePieces[16] = new Pawn(6, 0, false, m_chessBoard);
	m_chessBoard->set(6, 0, m_chessGamePieces[16]);
	m_chessGamePieces[17] = new Pawn(6, 1, false, m_chessBoard);
	m_chessBoard->set(6, 1, m_chessGamePieces[17]);
	m_chessGamePieces[18] = new Pawn(6, 2, false, m_chessBoard);
	m_chessBoard->set(6, 2, m_chessGamePieces[18]);
	m_chessGamePieces[19] = new Pawn(6, 3, false, m_chessBoard);
	m_chessBoard->set(6, 3, m_chessGamePieces[19]);
	m_chessGamePieces[20] = new Pawn(6, 4, false, m_chessBoard);
	m_chessBoard->set(6, 4, m_chessGamePieces[20]);
	m_chessGamePieces[21] = new Pawn(6, 5, false, m_chessBoard);
	m_chessBoard->set(6, 5, m_chessGamePieces[21]);
	m_chessGamePieces[22] = new Pawn(6, 6, false, m_chessBoard);
	m_chessBoard->set(6, 6, m_chessGamePieces[22]);
	m_chessGamePieces[23] = new Pawn(6, 7, false, m_chessBoard);
	m_chessBoard->set(6, 7, m_chessGamePieces[23]);

	m_chessGamePieces[24] = m_blackKing = new King(7, 4, false, m_chessBoard);
	m_chessBoard->set(7, 4, m_chessGamePieces[24]);

	m_chessGamePieces[25] = new Queen(7, 3, false, m_chessBoard);
	m_chessBoard->set(7, 3, m_chessGamePieces[25]);

	m_chessGamePieces[26] = new Knight(7, 1, false, m_chessBoard);
	m_chessBoard->set(7, 1, m_chessGamePieces[26]);
	m_chessGamePieces[27] = new Knight(7, 6, false, m_chessBoard);
	m_chessBoard->set(7, 6, m_chessGamePieces[27]);

	m_chessGamePieces[28] = new Bishop(7, 2, false, m_chessBoard);
	m_chessBoard->set(7, 2, m_chessGamePieces[28]);
	m_chessGamePieces[29] = new Bishop(7, 5, false, m_chessBoard);
	m_chessBoard->set(7, 5, m_chessGamePieces[29]);

	m_chessGamePieces[30] = m_rightBlackRook = new Rook(7, 0, false, m_chessBoard);
	m_chessBoard->set(7, 0, m_chessGamePieces[30]);
	m_chessGamePieces[31] = m_leftBlackRook = new Rook(7, 7, false, m_chessBoard);
	m_chessBoard->set(7, 7, m_chessGamePieces[31]);
}

void Game::showGame()
{
	m_chessBoard->printBoard();
}

void Game::move(Piece* piece, int iNext, int jNext)
{
	assert(piece);
	assert(iNext >= 0 && iNext < 8 && jNext >= 0 && jNext < 8);

	int i = piece->getI();
	int j = piece->getJ();	
	m_chessBoard->set(i, j, nullptr);

	m_chessBoard->set(iNext, jNext, piece);
	piece->setI(iNext);
	piece->setJ(jNext);
}

void Game::executeCastle(bool turn, King* king, Rook* leftRook, Rook* rightRook, Rules rule, int iNext, int jNext)
{	
	if (rule.checkCastleCondition(king, leftRook, rightRook, m_chessBoard) != 0)
	{
		if (rule.checkCastleCondition(king, leftRook, rightRook, m_chessBoard) == 1 || rule.checkCastleCondition(king, leftRook, rightRook, m_chessBoard) == 2 || rule.checkCastleCondition(king, leftRook, rightRook, m_chessBoard) == 3)
		{
			if (turn == true)
			{
				if (iNext == -1 && jNext == -1) //left castle
				{
					move(king, 0, 2);
					king->recordFirstMove();
					move(leftRook, 0, 3);
					leftRook->recordFirstMove();
				}
				else if (iNext == -2, jNext == -2) //right castle
				{
					move(king, 0, 6);
					king->recordFirstMove();
					move(rightRook, 0, 5);
					rightRook->recordFirstMove();						
				}
			}
			else if (turn == false)
			{
				if (iNext == -1 && jNext == -1) //left castle 
				{
					move(king, 7, 6);
					king->recordFirstMove();
					move(leftRook, 7, 5);
					leftRook->recordFirstMove();						
				}
				else if (iNext == -2, jNext == -2) //right castle
				{
					move(king, 7, 2);
					king->recordFirstMove();
					move(rightRook, 7, 3);
					rightRook->recordFirstMove();
				}
			} 
		}
	} 
}

bool Game::saviourPiece(King* king)
{
	bool saviourPiece = false;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (m_chessBoard->getPiece(i, j) != king && m_chessBoard->getPiece(i, j) != nullptr && m_chessBoard->getPiece(i, j)->getColour() == king->getColour())
			{
				for (int m = 0; m < 8; m++)
				{
					for (int n = 0; n < 8; n++)
					{
						if (m_chessBoard->getPiece(i, j)->checkValidMove(king, m, n) == true)
						{
							saviourPiece = true; 
						}
					}
				}
			}
		}
	}

	return saviourPiece;
}

void Game::checkMate(King* king)
{
	int possibleIs[7], possibleJs[7];			

	possibleIs[0] = king->getI() + 1, possibleJs[0] = king->getJ() + 1;
	possibleIs[1] = king->getI() + 1, possibleJs[1] = king->getJ();
	possibleIs[2] = king->getI() + 1, possibleJs[2] = king->getJ() - 1;
	possibleIs[3] = king->getI(), possibleJs[3] = king->getJ() - 1;
	possibleIs[4] = king->getI() - 1, possibleJs[4] = king->getJ() - 1;
	possibleIs[5] = king->getI() - 1, possibleJs[5] = king->getJ();
	possibleIs[6] = king->getI() - 1, possibleJs[6] = king->getJ() + 1;

	if (king->returnCheckCondition() == true)				
	{	
		for (int i = 0, j = 0; i < 7, j < 7; i++, j++)
		{
			if (king->checkConstrainedMove(possibleIs[i], possibleJs[j]) == true && king->checkValidMove(king, possibleIs[i], possibleJs[j]) == true && 
				saviourPiece(king) == true)
			{
				break;
			}
			else
			{																		
 				king->setCheckMateCondition(true);
			}
		}
	}
}		

//////////////////////////////////// console application execute only ////////////////////////////////////////////////////

void Game::gameExecution()
{
	King* whiteKing = dynamic_cast <King*> (m_chessGamePieces[8]);
	Rook* whiteLeftRook = dynamic_cast <Rook*> (m_chessGamePieces[14]);
	Rook* whiteRightRook = dynamic_cast <Rook*> (m_chessGamePieces[15]);
	
	King* blackKing = dynamic_cast <King*> (m_chessGamePieces[24]);
	Rook* blackLeftRook = dynamic_cast <Rook*> (m_chessGamePieces[31]);
	Rook* blackRightRook = dynamic_cast <Rook*> (m_chessGamePieces[30]);
	
	Rules rule;

	bool turn = true;
	
	while (1)	
	{
		showGame();	

		King* king = nullptr;
		Rook* leftRook = nullptr, *rightRook = nullptr;
		if (turn == true)
		{
			king = whiteKing, leftRook = whiteLeftRook, rightRook = whiteRightRook;
		}
		else
		{
			king = blackKing, leftRook = blackLeftRook, rightRook = blackRightRook;
		}

		if (turn == true && king->returnCheckMateCondition() == true)
		{
			cout << "Black Wins!!!" << endl;
			break;
		}
		else if (turn == false && king->returnCheckMateCondition() == true)
		{
			cout << "White Wins!!!" << endl;
			break;
		}

		cout << "Select a Piece" << endl;
		int i = -10, j = -10;
		cin >> i >> j;						

		Piece* selectedPiece = m_chessBoard->getPiece(i, j);

		if (selectedPiece->checkConstrainedMove(i, j) == true && selectedPiece != nullptr && selectedPiece->getColour() == turn)
		{
			King* selectedking = dynamic_cast <King*> (selectedPiece);

			if (selectedking != nullptr && rule.checkCastleCondition(selectedking, leftRook, rightRook, m_chessBoard) != 0)
			{
				cout << "Enter i = -1 and j = -2 for left castle" << endl;
				cout << "Enter i = -2 and j = -2 for right castle" << endl;

				int iNext, jNext;
				cin >> iNext >> jNext;

				executeCastle(turn, selectedking, leftRook, rightRook, rule, iNext, jNext);
				turn = !turn;
			}
			else
			{
				cout << "Select new Position" << endl;
				int iNext = -1, jNext = -1;			
				cin >> iNext >> jNext;				

				Piece* newPosition = m_chessBoard->getPiece(iNext, jNext);

				if (selectedPiece->checkConstrainedMove(iNext, jNext) == true && selectedPiece->checkValidMove(king, iNext, jNext) == true)
				{
					if (m_chessBoard->getPiece(i, j)->checkKill(iNext, jNext) == true)
					{
						m_chessBoard->kill(iNext, jNext);
						move(selectedPiece, iNext, jNext);
						turn = !turn;
						selectedPiece->recordFirstMove();
					}
					Pawn* pawn = dynamic_cast <Pawn*> (selectedPiece);
					if (pawn != nullptr && ( (selectedPiece->getColour() == true && iNext == 7) || (selectedPiece->getColour() == false && iNext == 0) ))
					{
						Piece* upgradedPiece = rule.promotionRule(pawn, m_chessBoard);
					}
					else
					{
						move(selectedPiece, iNext, jNext);
						turn = !turn;
						selectedPiece->recordFirstMove();
					}
					cout << "moving a pawn" << endl;
				}
				else
				{
					cout << "Invalid move" << endl;
				}
			}

		}
		else
		{	
			cout << "Invalid selection" << endl;
		}
			
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Game::checkAndKillPiece(Piece* piece, int iNext, int jNext)
{
	if (piece->checkKill(iNext, jNext) == true)
	{
		m_chessBoard->kill(iNext, jNext);
	}
	else
		return;
}

Piece* Game::returnPiece(int i)
{
	return m_chessGamePieces[i];
}

Board* Game::returnBoard()
{
	return m_chessBoard;
}

bool Game::isSelectionValid(int i, int j)
{
	bool validSelection = false;
	Piece* tempPiece = m_chessBoard->getPiece(i, j);

	if (tempPiece != nullptr)
	{
		if (tempPiece->getColour() == m_whiteTurn)
		{
			validSelection = true;
		}
	}
	
	return validSelection;
}

bool Game::makeValidMove(int i, int j, int iNext, int jNext)
{
	bool moveMade = false;

	Piece* tempPiece = m_chessBoard->getPiece(i, j);

	if (m_whiteTurn == true)
	{
		if (tempPiece->checkValidMove(m_whiteKing, iNext, jNext) == true)
		{
			move(tempPiece, iNext, jNext);
			m_whiteTurn = !m_whiteTurn;
			moveMade = true;
		}
	}
	else
	{
		if (tempPiece->checkValidMove(m_blackKing, iNext, jNext) == true)
		{
			move(tempPiece, iNext, jNext);		
			m_whiteTurn = !m_whiteTurn;
			moveMade = true;
		}
	}

	return moveMade;
}

Game::~Game()
{
	
}