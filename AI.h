#pragma once
#include "Board.h"
class AI
{
public:
	AI();
	void setChar(int a,int u);
	int turn(const Board &bd);

private:
	bool NextMove(const Board &bd);
	int minimax(Board &bd, int depth, bool next_is_ai);
	int ai,user;
	int next;
	char players[2] = { 'O','X' };

};

