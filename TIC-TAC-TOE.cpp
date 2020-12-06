#include <iostream>

#include "Field.h"
#include "Game.h"

int main()
{
    TicTacToe::Game myGame = TicTacToe::Game();

    while (!myGame.Iteration())
    {
    }
    return 0;
}