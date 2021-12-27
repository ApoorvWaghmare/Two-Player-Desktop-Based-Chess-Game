#include "stdafx.h"
#include <assert.h>
#include "Board.h"
#include <iostream>
#include "Piece.h"

using namespace std;
	
Board::Board()
{
	for (int i = 0; i < 8; i++)	
	{		
		for (int j = 0; j < 8; j++)	
		{	
			m_piecePosition[i][j] = nullptr;
		}
	}
}

void Board::set(int i, int j, Piece* piece)
{
	m_piecePosition[i][j] = piece;
}

Piece* Board::getPiece(int i, int j)
{
	if (i < 0 || i>7 || j < 0 || j>7)
	{
		cout << "Select Valid Piece" << endl;
		return 0;
	}
	else
	{
		return m_piecePosition[i][j];
	}
}				

void Board::printBoard()
{	
	for (int i = 7; i > -1 ; i--) 
	{
		cout<< "\t" << i << "\t";
		for (int j = 0; j < 8; j++)
		{
			if (m_piecePosition[i][j] != nullptr)
			{
				m_piecePosition[i][j]->printPiece();
				cout << "\t";
			}
			if (m_piecePosition[i][j] == nullptr)
			{
				cout << "- \t";
			}
		}
		cout << "\n";
		cout << "\n";
	}

	cout << "\t\t";

	for (int i = 0; i < 8; i++)
	{
		cout << i << "\t";
	}
	cout << "\n" << endl;
}

void Board::kill(int iNext, int jNext)
{
	m_piecePosition[iNext][jNext] = nullptr;
}

Piece* Board::tempNull(int i, int j)
{
	Piece* tempAddress = m_piecePosition[i][j];
	m_piecePosition[i][j] = nullptr;

	return tempAddress;
}

void Board::reassignAddress(Piece* tempAddress, int i, int j)
{
	m_piecePosition[i][j] = tempAddress;
}

Piece* Board::getAddress(int i, int j)
{
	return m_piecePosition[i][j];
}

Board::~Board()
{

}

