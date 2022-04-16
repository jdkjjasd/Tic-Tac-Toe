#include "AI.h"


AI::AI()
{
	next = 0;
	ai = ' ';
	user = -1;
	ai = -1;
}

int AI::turn(const Board &bd)
{


	if (NextMove(bd))
	{
		std::cout << "AI take: " << next << std::endl;
		return next;
	}


}

bool AI::NextMove(const Board &bd)
{
	next = 0;
	
	int val = INT_MIN;
	
	for (int i = 0; i < 9; i++)
	{
		if (bd.board[i] != players[0] && bd.board[i] != players[1])
		{
			Board temp_board=bd;

			temp_board.play(ai, i + 1);

			int temp_val = minimax(temp_board, 0, false);
			// std::cout << "val : " << temp_val<<"\tin point: "<<i+1 << std::endl;

			temp_board.undo(ai, i + 1);

			if (temp_val > val)
			{
				val = temp_val;
				next = i + 1;
			}



		}
	}

	return true;

}

void AI::setChar(int a,int u)
{
	ai =a ;
	user = u;
	std::cout <<"AI take: " << players[ai] << std::endl;
}

//Key!
//win=100
//lose=-100
//tie=0
int AI::minimax(Board &bd, int depth, bool next_is_ai)
{
	if (bd.win())
	{
		//std::cout << "guess: "<<bd.returnWinner();// << std::endl;
		//bd.printBoard();
		if (bd.returnWinner() == players[ai])
		{
			return 100;
		}
		else if (bd.returnWinner() == players[user])
		{
			return -100;
		}
		else
		{
			return 0;
		}
	}

	

	if (next_is_ai)
	{
		int score = -5000;
		for (int i = 0; i < 9; i++)
		{
			
			if (bd.board[i] != players[0] && bd.board[i] != players[1])
			{
				if (bd.play(ai, i + 1))
				{
					//score = std::max(score, minimax(bd, depth + 1, !next_is_ai));
					score = std::max(score, minimax(bd, depth + 1, !next_is_ai)-depth);
				}
				else // should not shows
				{
					std::cout << "!!!!!!!" << std::endl;
				}
				bd.undo(ai, i + 1);
			}
		}
		return score;
	}
	else
	{
		int score = 5000;
		for (int i = 0; i < 9; i++)
		{
			if (bd.board[i] != players[0] && bd.board[i] != players[1])
			{
				if (bd.play(user, i + 1))
				{
					score = std::min(score, minimax(bd, depth + 1, !next_is_ai)-depth);
					//score = std::minx(score, minimax(bd, depth + 1, !next_is_ai));
				}
				else // should not shows
				{
					std::cout << "!!!!!!!" << std::endl;
				}
				bd.undo(user, i + 1);
			}
		}
		return score;
	}

	





}