#include "stdafx.h"
#include <string>
#include "gameutils.h"

std::string getPlayerName(std::istream &inRead)
{
	std::string pName;
	inRead >> pName;
	return pName;
}

void getMultPlayerNames(std::string *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead)
{
	std::string *returnList = playerNameList;
	for (std::size_t i = 0; i < numPlayers; i++)
	{
		outRead << "Enter name for player " << i+1 << std::endl;
		inRead >> *playerNameList;
		playerNameList++;
	}
	playerNameList = returnList;
}
