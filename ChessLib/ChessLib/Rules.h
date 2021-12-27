#pragma once
#ifndef RULES_H_
#define RULES_H_

class Pawn;
class Piece;
class Board;
class King;
class Rook;

class Rules
{
public:
	Rules();
	~Rules();
	Piece* promotionRule(Pawn* pawn, Board* chessBoard);
	int checkCastleCondition(King* king, Rook* leftRook, Rook* rightRook, Board* chessBoard);
	bool castlePossible = false;

protected:

private:
	
};

#endif // !RULES_H_

