#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

#include"EnumClass.h"
#include"InitializeGame.h"
#include"GetAliveList.h"


//get number of alive players
int getAliveCount(AllPlayers& playerList)
{
	int aliveCount{ 0 };

	for (auto player : playerList)					//check how many players are still alive
	{
		if (player.status == Status::S_ALIVE)
		{
			++aliveCount;							//the number of alive players
		}
	}

	return aliveCount;
}
void sortByAlive(AllPlayers &playerList)
{
	auto maxPlayer{ static_cast<int>(PlayerID::ID_MAX) };

	for (int current{ 0 }; current < maxPlayer; ++current)	//sort alive first, dead last
	{
		for (int next{ current + 1 }; next < maxPlayer; ++next)
		{
			if (playerList[current].status == Status::S_DEAD)
			{
				std::swap(playerList[current], playerList[next]); //if current is dead, push him down the list
			}
			else
				break;											  //if current is alive, check next player in the list
		}
	}
}

void printAlive(AllPlayers& playerList)
{
	sortID(playerList);

	for (const auto& newPlayer : playerList)
	{
		printPlayer(newPlayer);
		std::cout << '\n';
	}

	std::cout << '\n';
}