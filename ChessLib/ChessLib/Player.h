#pragma once
#ifndef PLAYER_H_
#define PLAYER_H_

class Piece;
class Board;

class Player
{
public:
	Player(bool colour);
	~Player();
	void setWin(bool win);
	bool getWin();

protected:

private:
	bool m_colour;
	bool m_win;	//win = 0 (no win), win = 1 (win)
};

#endif // PLAYER_H_
