#include "Game.h"

TicTacToe::Game::Game()
{
    mPlayer = false;
    mFullness = 0;
    mField = Field();
    std::cout << "TIC-TAC-TOE GAME" << std::endl;
}

bool TicTacToe::Game::Iteration()
{
    int posX, posY;

    if (mPlayer)
        std::cout << "PlayerX please enter coordinates (e.g. 0 2):" << std::endl;
    else
        std::cout << "PlayerO please enter coordinates (e.g. 0 2):" << std::endl;
    
    std::cin >> posX >> posY;
    
    if (posX < 3 && posY < 3 && mFullness != 9)
    {
        char symbol = PlayerSymbol();
        if (mField.Insert(symbol, posX, posY))
        {
            ++mFullness;
            if (mFullness == 9)
            {
                std::cout << mField << std::endl;
                std::cout << "Draw!" << std::endl;
                return true;
            }
            bool result = CheckWinCondition();
            mPlayer = !mPlayer;
            std::cout << mField << std::endl;
            if (result)
            {
                std::cout << "Player" << symbol << " Wins!" << std::endl;
                return true;
            }
            else
                return false;
        }
        else
        {
            std::cout << "Cell is not empty" << std::endl;
            return false;
        }
    }

    else
    {
        if (mFullness == 9)
        {
            std::cout << mField << std::endl;
            std::cout << "Draw!" << std::endl;
            return true;
        }
        else
        {
            std::cout << "Coordinates must be from 0 to 2!" << std::endl;
            return false;
        }
    }
}

bool TicTacToe::Game::CheckWinCondition()
{
    char symbol = PlayerSymbol();
    std::cout << symbol << std::endl;
    // horizontal
    char a = mField.GetValue(0, 0);
    char b = mField.GetValue(0, 1);
    char c = mField.GetValue(0, 2);

    if (symbol == mField.GetValue(0, 0) && symbol == mField.GetValue(0, 1) && symbol == mField.GetValue(0, 2))
        return true;
    if (symbol == mField.GetValue(1, 0) && symbol == mField.GetValue(1, 1) && symbol == mField.GetValue(1, 2))
        return true;

    if (symbol == mField.GetValue(2, 0) && symbol == mField.GetValue(2, 1) && symbol == mField.GetValue(2, 2))
        return true;

    // vertical
    if (symbol == mField.GetValue(0, 0) && symbol == mField.GetValue(1, 0) && symbol == mField.GetValue(2, 0))
        return true;

    if (symbol == mField.GetValue(0, 1) && symbol == mField.GetValue(1, 1) && symbol == mField.GetValue(2, 1))
        return true;

    if (symbol == mField.GetValue(0, 2) && symbol == mField.GetValue(1, 2) && symbol == mField.GetValue(2, 2))
        return true;

    // diagonal
    if (symbol == mField.GetValue(0, 0) && symbol == mField.GetValue(1, 1) && symbol == mField.GetValue(2, 2))
        return true;

    if (symbol == mField.GetValue(0, 2) && symbol == mField.GetValue(1, 1) && symbol == mField.GetValue(2, 0))
        return true;

    return false;
}

char TicTacToe::Game::PlayerSymbol()
{
    char symbol;
    if (mPlayer)
        symbol = 'X';
    else
        symbol = 'O';

    return symbol;
}
