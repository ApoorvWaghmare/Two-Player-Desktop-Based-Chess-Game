#pragma once
#ifndef GAME_H_
#define GAME_H_

class Board;
class Piece;
class King;
class Queen;
class Rook;
class Bishop;
class Knight;
class Pawn;
class Player;
class Rules;

class Game
{
public:
	Game();
	~Game();	
	void move(Piece* piece, int iNext, int jNext); //moves piece to another location
	void showGame(); //displays game on the console
	void gameExecution(); // only for console
	void executeCastle(bool turn, King* king, Rook* leftRook, Rook* rightRook, Rules rule, int iNext, int Next); // only for console
	void checkMate(King* king);
	bool saviourPiece(King* king);
	Piece* returnPiece(int i);
	Board* returnBoard();
	bool isSelectionValid(int i, int j);
	bool makeValidMove(int i, int j, int iNext, int jNext);
	void checkAndKillPiece(Piece* piece, int iNext, int jNext);

protected: 

private:
	Piece* m_chessGamePieces[32];	
	Board* m_chessBoard;
	bool m_whiteTurn = true;
	King* m_whiteKing;
	King* m_blackKing;
	Rook* m_leftWhiteRook, *m_rightWhiteRook, *m_leftBlackRook, *m_rightBlackRook;
};

#endif // !GAME_H_
