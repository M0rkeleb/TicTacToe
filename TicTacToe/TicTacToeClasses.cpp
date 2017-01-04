#include "stdafx.h"
#include "TicTacToeClasses.h"
#include "gameutils.h"
#include <iostream>

TicTacToeBoard::TicTacToeBoard(std::size_t dimension) :m_dimension(dimension)
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

TicTacToeBoard::~TicTacToeBoard()
{
	delete[] boardContents[0];
	delete[] boardContents;
}

void TicTacToeBoard::placeInSquare(std::size_t i, std::size_t j, char placed)
{
	if ((placed == 'X' || placed == 'O') && i < m_dimension && j < m_dimension)
	{
		boardContents[i][j] = placed;
		lastPlacedRow = i;
		lastPlacedCol = j;
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

bool TicTacToeBoard::gameTied()
{
	for (std::size_t i = 0; i < m_dimension; i++)
	{
		for (std::size_t j = 0; j < m_dimension; j++)
			if (getFromSquare(i, j) == '_') return false;
	}
	//going to assume victoryReached will be checked first, so a full board is always tied.
	return true;
}

std::ostream & operator<<(std::ostream & out, const TicTacToeBoard & tttBoard)
{
	for (size_t i = 0; i < tttBoard.m_dimension; i++)
	{
		for (size_t j = 0; j < tttBoard.m_dimension; j++) { out << tttBoard.boardContents[i][j] << " "; }
		out << std::endl;
	}
	return out;
}

TicTacToeGame::TicTacToeGame(std::size_t dimension)
{
	m_playerNameList = new GamePlayer[2];
	m_board = new TicTacToeBoard(dimension);
	char tttIdents[2]{ 'X','O' };
	initPlayerList(m_playerNameList, 2, std::cin, std::cout, tttIdents);
}

TicTacToeGame::~TicTacToeGame()
{
	delete m_board;
	delete m_playerNameList;
}