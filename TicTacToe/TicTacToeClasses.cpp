#include "stdafx.h"
#include "TicTacToeClasses.h"

TicTacToeBoard::TicTacToeBoard(std::size_t dimension = 3) :m_dimension(dimension)
{
	boardContents = new char*[dimension];
	boardContents[0] = new char[dimension * dimension];
	for (size_t i = 0; i < dimension; i++)
	{
		if (i != 0) boardContents[i] = boardContents[i - 1] + dimension;
		for (size_t j = 0; j < dimension; j++)
			boardContents[i][j] = '_';
	}
}

bool TicTacToeBoard::victoryReached()
{
	bool rowWin = true;
	bool colWin = true;
	bool diagDownRightWin = (lastPlacedCol == lastPlacedRow);
	bool diagUpRightWin = (lastPlacedCol + lastPlacedRow + 1 == m_dimension);
	for (size_t i = 0; i < m_dimension; i++)
	{
		rowWin = rowWin && (getFromSquare(lastPlacedRow, i) == getFromSquare(lastPlacedRow, lastPlacedCol));
		colWin = colWin && (getFromSquare(i, lastPlacedCol) == getFromSquare(lastPlacedRow, lastPlacedCol));
		diagDownRightWin = diagDownRightWin && (getFromSquare(i, i) == getFromSquare(lastPlacedRow, lastPlacedCol));
		diagUpRightWin = diagUpRightWin && (getFromSquare(i, m_dimension - 1 - i) == getFromSquare(lastPlacedRow, lastPlacedCol));
	}
	return rowWin || colWin || diagDownRightWin || diagUpRightWin;
}