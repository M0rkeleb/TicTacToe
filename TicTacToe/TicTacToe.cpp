// TicTacToe.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "gameutils.h"
#include "TicTacToeTests.h"
#include "TicTacToeClasses.h"
#include <iostream>
#include <string>





int main()
{
	/*std::string playerNames[2];
	getMultPlayerNames(playerNames, 2, std::cin, std::cout);
	std::cout << "First player name read as " << *playerNames << std::endl;*/

	//Section for testing victory condition, comment out when not needed.
	/*int testResult = testVictoryCondition();
	if (testResult == 0) { std::cout << "No failures." << std::endl; }
	else { std::cout << "Failed test " << testResult << "." << std::endl; }*/

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
