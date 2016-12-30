// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gameutils.h"
#include <iostream>
#include <string>

class TicTacToeBoard
{
public:
	TicTacToeBoard(std::size_t dimension);
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
		{if (i < m_dimension && j < m_dimension)                                     { return boardContents[i][j] ;  }}
	friend std::ostream& operator<< (std::ostream &out, const TicTacToeBoard &tttBoard);
	bool victoryReached();
private:
	const std::size_t m_dimension;
	char** boardContents;
	std::size_t lastPlacedRow, lastPlacedCol;

};

TicTacToeBoard::TicTacToeBoard(std::size_t dimension = 3):m_dimension(dimension)
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
	bool rowWin           = true;
	bool colWin           = true;
	bool diagDownRightWin = (lastPlacedCol == lastPlacedRow);
	bool diagUpRightWin   = (lastPlacedCol + lastPlacedRow + 1 == m_dimension);
	for (size_t i = 0; i < m_dimension; i++) 
	{ 
		rowWin = rowWin && (getFromSquare(lastPlacedRow, i) == getFromSquare(lastPlacedRow, lastPlacedCol));
		colWin = colWin && (getFromSquare(i, lastPlacedCol) == getFromSquare(lastPlacedRow, lastPlacedCol));
		diagDownRightWin = diagDownRightWin && (getFromSquare(i, i) == getFromSquare(lastPlacedRow, lastPlacedCol));
		diagUpRightWin = diagUpRightWin && (getFromSquare(i, m_dimension - 1 - i) == getFromSquare(lastPlacedRow, lastPlacedCol));
	}
	return rowWin || colWin || diagDownRightWin || diagUpRightWin;
}


int main()
{
	/*std::string playerNames[2];
	getMultPlayerNames(playerNames, 2, std::cin, std::cout);
	std::cout << "First player name read as " << *playerNames << std::endl;*/
	TicTacToeBoard myBoard;
	myBoard.placeInSquare(1, 0, 'X');
	myBoard.placeInSquare(0, 1, 'O');
	myBoard.placeInSquare(1, 1, 'X');
	myBoard.placeInSquare(2, 2, 'O');
	myBoard.placeInSquare(0, 2, 'X');
	std::cout << myBoard << std::endl;
	std::cout << "Victory achieved? " << myBoard.victoryReached() << std::endl;
    return 0;
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
