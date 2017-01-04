#pragma once
#include <string>
#include "gameutils.h"

class TicTacToeBoard
{
public:
	TicTacToeBoard(std::size_t dimension = 3);
	~TicTacToeBoard();
	void placeInSquare(std::size_t i, std::size_t j, char placed);
	char getFromSquare(size_t i, size_t j)
	{
		if (i < m_dimension && j < m_dimension) { return boardContents[i][j]; }
	}
	friend std::ostream& operator<< (std::ostream &out, const TicTacToeBoard &tttBoard);
	bool victoryReached();
	bool gameTied();
	char currPlayer() { return getFromSquare(lastPlacedRow, lastPlacedCol); }
	bool noPlaysYet() { return (lastPlacedRow == m_dimension || lastPlacedCol == m_dimension); }
private:
	const std::size_t m_dimension;
	char** boardContents;
	std::size_t lastPlacedRow, lastPlacedCol;

};

class TicTacToeGame
{
public:
	TicTacToeGame(std::size_t dimension = 3);
	~TicTacToeGame();
	bool checkEnding();
	std::string playerFromIdent(char ident);
	void playTurn();
	char nextPlacedIdent();

private:
	TicTacToeBoard* m_board;
	GamePlayer* m_playerNameList;

};

