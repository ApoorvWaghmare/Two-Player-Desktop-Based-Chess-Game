#pragma once
#ifndef	MOVECHECKER_H_
#define MOVECHECKER_H_

class Piece;
class Board;

class MoveChecker
{
public:
	MoveChecker();
	~MoveChecker();
	bool checkNullPtr(Piece* piece, Board* chessBoard, int iNext, int jNext);
	

protected:

private:

};

#endif // !CHECKNULLPTR_H_

