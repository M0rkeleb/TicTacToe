#pragma once
#include <string>

class TicTacToeBoard
{
public:
	TicTacToeBoard(std::size_t dimension = 3);
	~TicTacToeBoard()
	{
		delete[] boardContents[0];
		delete[] boardContents;
	}
	void placeInSquare(size_t i, size_t j, char placed)
	{
		if ((placed == 'X' || placed == 'O') && i < m_dimension && j < m_dimension)
		{
			boardContents[i][j] = placed;
			lastPlacedRow = i;
			lastPlacedCol = j;
		}
	}
	char getFromSquare(size_t i, size_t j)
	{
		if (i < m_dimension && j < m_dimension) { return boardContents[i][j]; }
	}
	friend std::ostream& operator<< (std::ostream &out, const TicTacToeBoard &tttBoard);
	bool victoryReached();
private:
	const std::size_t m_dimension;
	char** boardContents;
	std::size_t lastPlacedRow, lastPlacedCol;

};