#include "stdafx.h"	
#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(bool colour)
{
	m_colour = colour;
}

void Player::setWin(bool win)
{
	m_win = win;
}

bool Player::getWin()
{
	bool win = m_win;
	return win;
}

Player::~Player()
{

}