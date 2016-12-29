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
		{if ((placed == 'X' || placed == 'O') && i < m_dimension && j < m_dimension) { boardContents[i][j] = placed; }}
	char getFromSquare(size_t i, size_t j)              
		{if (i < m_dimension && j < m_dimension)                                     { return boardContents[i][j] ;  }}
	friend std::ostream& operator<< (std::ostream &out, const TicTacToeBoard &tttBoard);
private:
	const std::size_t m_dimension;
	char** boardContents;

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


int main()
{
	std::string playerNames[2];
	getMultPlayerNames(playerNames, 2, std::cin, std::cout);
	std::cout << "First player name read as " << *playerNames << std::endl;
	TicTacToeBoard myBoard;
	myBoard.placeInSquare(0, 0, 'X');
	myBoard.placeInSquare(0, 1, 'O');
	myBoard.placeInSquare(1, 1, 'X');
	myBoard.placeInSquare(2, 2, 'O');
	std::cout << myBoard;
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
