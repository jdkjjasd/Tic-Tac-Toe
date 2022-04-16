// Tic_Tac_Toe_rec.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include "Board.h"
#include "AI.h"

int main()
{
    bool next_is_user;
    Board new_board;
    AI new_ai;
    int ai, user;

    // set char
    std::cout << "pick 1 : O , 2 : X" << std::endl;
    int pick = 0;
    std::cin >> pick;
    if (pick == 1)
    {
        user = 0;
        ai = 1;
    }
    else
    {
        user = 1;
        ai = 0;

    }
    new_ai.setChar(ai,user);

    std::cout << "play fisrt? 1/2" << std::endl;
    std::cin >> pick;
    if (pick == 1)
    {
        next_is_user = true;
    }
    else
    {
        next_is_user = false;
    }

    // start to play


    while (!new_board.win())
    {
        new_board.printBoard();
        //user play
        if (next_is_user)
        {
            std::cout << "input your choice" << std::endl;
            std::cin >> pick;
            if (new_board.play(user, pick))
            {
                next_is_user = !next_is_user;
            }
            else
            {
                std::cout << "wrong input" << std::endl;
            }
        }
        //ai play
        else
        {
            if (new_board.play(ai, new_ai.turn(new_board)))
            {
                next_is_user = !next_is_user;
            }
            else
            {
                std::cout << "some goes wrong" << std::endl;
            }
        }



    }



    if (new_board.returnWinner() == 'T')
    {
        std::cout << "Tie!" << std::endl;
    }
    else
    {
        std::cout << "Winner is: " << new_board.returnWinner() << std::endl;
    }

    new_board.printBoard();





}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
