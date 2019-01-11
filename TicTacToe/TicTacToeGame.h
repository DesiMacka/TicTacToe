#pragma once

#include <ostream>
#include <string>

class TicTacToeGame
{
public:
	// Constructor
	TicTacToeGame(const std::string& PlayerXName, 
		          const std::string& PlayerOName);
	// Put a letter into a square
	bool MakeTurn(int Square);
	// Has someone won the game?
	bool IsGameOver();
	// Returns X,O,C if game is over, else blank character
	char WhoWonGame();
	// Returns name of player whose turn it is
	std::string WhoseTurnIsIt();
	// Print out the grid and player information
	friend std::ostream& operator <<(std::ostream& ostr, const TicTacToeGame& game);

private:
	// X player name
	std::string PlayerX;
	// O player name
	std::string PlayerO;
	// Character array
	std::string Grid;
	// Whose turn is it
	char WhoseTurn;
	// How many plays have been made - for cat's game
	int TurnsCompleted;

	// Switch X to O and vice versa
	void SwitchPlayerTurn();
};