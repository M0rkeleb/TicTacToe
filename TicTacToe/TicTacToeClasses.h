#pragma once
#include <string>

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
private:
	const std::size_t m_dimension;
	char** boardContents;
	std::size_t lastPlacedRow, lastPlacedCol;

};