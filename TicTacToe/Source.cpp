#include "TicTacToeGame.h"
#include <iostream>

int main()
{
	TicTacToeGame game("Brad", "Tina");
	while (game.IsGameOver() == false)
	{
		std::cout << game;
		std::cout << "Player's turn: " << game.WhoseTurnIsIt();
		std::cout << std::endl << std::endl;
		std::cout << "Which square to fill? ";
		int square;
		std::cin >> square;
		game.MakeTurn(square);
	}
	
	std::cout << game;
	system("PAUSE");
	return 0;
}