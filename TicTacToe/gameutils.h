#pragma once
#include <string>

std::string getPlayerName(std::istream &inRead);

void getMultPlayerNames(std::string *playerNameList, std::size_t numPlayers, std::istream &inRead, std::ostream &outRead);