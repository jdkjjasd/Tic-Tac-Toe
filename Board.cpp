#include "Board.h"

Board::Board()
{
	for (int i = 1; i <= 9; i++)
	{
		board[i-1] = i+48;
	}

	is_win = false;
	winner = 'p';
	round = 0;


}

Board::Board(const Board& bd)
{
	for (int i = 0; i < 9; i++)
	{
		board[i] = bd.board[i];
	}


	is_win = false;
	winner = 'T';
	round = bd.round;
}


void Board::checkWinner()
{
	for (int i = 0; i < 8; i++)
	{
		if (board[wincase[i][0]-1] == board[wincase[i][1]-1] && board[wincase[i][1]-1] == board[wincase[i][2]-1])
		{
			is_win = true;
			winner = board[wincase[i][0]-1];
			return;
		}

	}

	if (round == 9 && (!is_win))
	{
		is_win = true;
		winner = 'T';
		return;
	}
	is_win = false;
	
}

void Board::printBoard()
{
	std::cout << "Board:\n===========================================";
	for (int i = 0; i < 9; i++)
	{
		if (i % 3 == 0)
		{
			std::cout << "\n\n";
		}
		std::cout << board[i] << "\t";
	}
	std::cout << "\n===========================================\n\n\n";
}

char Board::returnWinner()
{
	return winner;
}

bool Board::play(int player, int target)
{
	if (player > 1 || player < 0)
	{
		return false;
	}

	target--;

	if (board[target] != players[0] && board[target] != players[1])
	{
		board[target] = players[player];
		round++;
		//std::cout << "round:¡¡" << round << "\t " << players[player] << "take:" << target + 1;
		checkWinner();
		return true;
	}
	else
	{
		std::cout << "wrong step!" << std::endl;
		return false;
	}
}

bool Board::win()
{
	return is_win;
}

void Board::undo(int player, int target)
{
	target--;
	board[target] = target+48+1;
	round--;
}
