#pragma once
#include <iostream>

class Board
{
public:
	Board();
	Board(const Board &bd);
	void checkWinner();
	void printBoard();
	char returnWinner();
	bool play(int player,int target); 
	bool win();
	void undo(int player, int target);

	char board[9];
private:
	
	bool is_win;
	char winner;// O X
	char players[2] = {'O','X'};
	int round;

	int wincase[8][3] = {{1,2,3,},
	{4,5,6},
	{7,8,9},
	{1,4,7},
	{2,5,8},
	{3,6,9},
	{1,5,9},
	{3,5,7} };

};

