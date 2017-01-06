#pragma once
#include <string>

std::string getPlayerName(std::istream &inRead);

//Minimal play data, if more is needed then make a class/struct object with one of these structs as a member.
struct GamePlayer
{
	std::string playerName;
	int playerNumber;
	char playerIdentShort;
};

void getMultPlayerNames(GamePlayer *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead);

void getMultPlayerNumbers(GamePlayer *playerNameList, std::size_t numPlayers);

void getMultPlayerIdentShorts(GamePlayer *playerNameList, std::size_t numPlayers, char *shortsList);

void initPlayerList(GamePlayer *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead, char *shortsList);

template <typename T>
T getInput(std::istream &inRead, std::ostream &outRead, std::string prompt, T &user_input)
{
	while (true)
	{
		outRead << prompt;
		inRead >> user_input;
		if (inRead.fail())
		{
			inRead.clear();
			inRead.ignore(100, '\n');
		}
		else if (true)
		{
			inRead.ignore(100, '\n');
			return user_input;
		}
		outRead << "Invalid input, try again. ";
	}
}


