#ifndef GAME_H
#define GAME_H

#include "Field.h"
namespace TicTacToe {

class Game
{
public:
	Game();
	bool Iteration();
private:
	Field mField;
	bool mPlayer; // current player
	std::uint8_t mFullness;
	bool CheckWinCondition();
	char PlayerSymbol();
};

}
#endif /*GAME_H*/
