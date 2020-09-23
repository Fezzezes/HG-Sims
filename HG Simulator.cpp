#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>

#include"EnumClass.h"
#include"InitializeGame.h"
#include"GetAliveList.h"

void shuffleAliveList(PlayerVector &aliveList)
{
	std::mt19937 seed{ getRandomNumber() };

	std::shuffle(aliveList.begin(), aliveList.end(), seed);
}

int main()
{
	AllPlayers playerList{ initializeGame() };

	PlayerVector aliveList{ aliveCheck(playerList) };
	
	return 0;
}
