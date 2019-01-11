#include <iostream>
#include "TicTacToeGame.h"

TicTacToeGame::TicTacToeGame(const std::string& PlayerXName,
                          	 const std::string& PlayerOName)
: PlayerX(PlayerXName),
  PlayerO(PlayerOName),
  Grid("123456789"),
  WhoseTurn('X'),
  TurnsCompleted(0)
{
	// Nothing here...
}

bool TicTacToeGame::IsGameOver()
{
	return (WhoWonGame() != ' ');
}

char TicTacToeGame::WhoWonGame()
{
	// Horizontal wins
	if ((Grid[0] == Grid[1]) && (Grid[1] == Grid[2]))
	{
		return Grid[0];
	}
	if ((Grid[3] == Grid[4]) && (Grid[4] == Grid[5]))
	{
		return Grid[3];
	}
	if ((Grid[6] == Grid[7]) && (Grid[7] == Grid[8]))
	{
		return Grid[6];
	}
	
	// Vertical wins
	if ((Grid[0] == Grid[3]) && (Grid[3] == Grid[6]))
	{
		return Grid[0];
	}
	if ((Grid[1] == Grid[4]) && (Grid[4] == Grid[7]))
	{
		return Grid[1];
	}
	if ((Grid[2] == Grid[5]) && (Grid[5] == Grid[8]))
	{
		return Grid[2];
	}

	// Diagonals wins
	if ((Grid[0] == Grid[4]) && (Grid[4] == Grid[8]))
	{
		return Grid[0];
	}
	if ((Grid[2] == Grid[4]) && (Grid[4] == Grid[6]))
	{
		return Grid[2];
	}

	if (TurnsCompleted == 9)
	{
		return 'C';
	}

	return ' ';
}

bool TicTacToeGame::MakeTurn(int Square)
{
	if (IsGameOver() == true)
	{
		return false;
	}

	if ((Square < 1) || (Square > 9))
	{
		return false;
	}

	if (TurnsCompleted == 9)
	{
		return false;
	}

	++TurnsCompleted;
	Grid[Square-1] = WhoseTurn;
	SwitchPlayerTurn();
	return true;
}

void TicTacToeGame::SwitchPlayerTurn()
{
	WhoseTurn = (WhoseTurn == 'X') ? 'O' : 'X';
}

std::ostream& operator <<(std::ostream& ostr, const TicTacToeGame& game)
{
	std::cout << "X: " << game.PlayerX << "\tO: " << game.PlayerO << std::endl;
	std::cout << game.Grid[0] << "  " << game.Grid[1] << "  " << game.Grid[2] << std::endl;
	std::cout << game.Grid[3] << "  " << game.Grid[4] << "  " << game.Grid[5] << std::endl;
	std::cout << game.Grid[6] << "  " << game.Grid[7] << "  " << game.Grid[8] << std::endl;
	return ostr;
}

std::string TicTacToeGame::WhoseTurnIsIt()
{
	return (WhoseTurn == 'X') ? PlayerX : PlayerO;
}