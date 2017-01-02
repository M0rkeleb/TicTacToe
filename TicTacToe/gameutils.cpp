#include "stdafx.h"
#include <string>
#include "gameutils.h"

std::string getPlayerName(std::istream &inRead)
{
	std::string pName;
	inRead >> pName;
	return pName;
}

void getMultPlayerNames(GamePlayer *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead)
{
	for (std::size_t i = 0; i < numPlayers; i++)
	{
		outRead << "Enter name for player " << i+1 << std::endl;
		inRead >> (*(playerNameList+i)).playerName;
	}
}

void getMultPlayerNumbers(GamePlayer *playerNameList, std::size_t numPlayers)
{
	for (std::size_t i = 0; i < numPlayers; i++) (*(playerNameList + i)).playerNumber = i + 1;
}

void getMultPlayerIdentShorts(GamePlayer *playerNameList, std::size_t numPlayers, char *shortsList)
{
	for (std::size_t i = 0; i < numPlayers; i++) (*(playerNameList + i)).playerIdentShort = *(shortsList + i);
}

void initPlayerList(GamePlayer *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead, char *shortsList)
{
	getMultPlayerNames(playerNameList, numPlayers, inRead, outRead);
	getMultPlayerNumbers(playerNameList, numPlayers);
	getMultPlayerIdentShorts(playerNameList, numPlayers, shortsList);
}