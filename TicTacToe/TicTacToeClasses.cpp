#include "stdafx.h"
#include "TicTacToeClasses.h"
#include "gameutils.h"
#include <iostream>

TicTacToeBoard::TicTacToeBoard(std::size_t dimension) :m_dimension(dimension), lastPlacedRow(dimension), lastPlacedCol(dimension)
{
	boardContents.resize(dimension);
	for (auto &e: boardContents)
	{
		e.resize(dimension);
		for (auto &f: e)
			f = '_';
	}
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
		rowWin = rowWin && (getFromSquare(lastPlacedRow, i) == currPlayer());
		colWin = colWin && (getFromSquare(i, lastPlacedCol) == currPlayer());
		diagDownRightWin = diagDownRightWin && (getFromSquare(i, i) == currPlayer());
		diagUpRightWin = diagUpRightWin && (getFromSquare(i, m_dimension - 1 - i) == currPlayer());
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
	m_playerNameList.resize(2);
	m_board = new TicTacToeBoard(dimension);
	char tttIdents[2]{ 'X','O' };
	initPlayerList(m_playerNameList, std::cin, std::cout, tttIdents);
}

TicTacToeGame::~TicTacToeGame()
{
	delete m_board;
}

bool TicTacToeGame::checkEnding()
{
	//Check if the game is over and print result.
	//First check for a win.
	if ((*m_board).victoryReached())
	{
		std::cout << "Game is won by " << playerFromIdent((*m_board).currPlayer()) << "." << std::endl;
		return true;
	}
	//Check for a tie.
	if ((*m_board).gameTied())
	{
		std::cout << "Game ends in a tie." << std::endl;
		return true;
	}
	return false;
}

std::string TicTacToeGame::playerFromIdent(char ident)
{
	for (auto e: m_playerNameList) if (ident == e.playerIdentShort) return e.playerName;
	return std::string();
}

void TicTacToeGame::playTurn()
{
	int playRow, playCol;
	while (true)
	{
		std::cout << playerFromIdent(nextPlacedIdent()) << ", choose a square to place an " << nextPlacedIdent() << " on." << std::endl;
		playRow = getInput(std::cin, std::cout, "Choose a row. ", playRow, &TicTacToeGame::validLocInput, this);
		playCol = getInput(std::cin, std::cout, "Choose a column. ", playCol, &TicTacToeGame::validLocInput, this);
		if ((*m_board).getFromSquare(playRow - 1, playCol - 1) == '_') { (*m_board).placeInSquare(playRow - 1, playCol - 1, nextPlacedIdent()); return; }
		std::cout << "That square is already full. You cannot place there." << std::endl;
	}
}

char TicTacToeGame::nextPlacedIdent()
{
	if ((*m_board).noPlaysYet()) { return 'X'; }
	if ((*m_board).currPlayer() == 'X') { return 'O'; }
	return 'X';
}

void TicTacToeGame::playGame()
{
	do {
		std::cout << (*m_board);
		playTurn();
	} while (!checkEnding());
	std::cout << (*m_board);
}
