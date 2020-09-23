#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

#include"EnumClass.h"
#include"InitializeGame.h"
#include"GetAliveList.h"

void killPlayerTest(AllPlayers& playerList)
{
	playerList[0].status = Status::S_DEAD;
	std::cout << playerList[0].name << " was killed\n";

	playerList[4].status = Status::S_DEAD;
	std::cout << playerList[4].name << " was killed\n";

	playerList[8].status = Status::S_DEAD;
	std::cout << playerList[8].name << " was killed\n";

	playerList[21].status = Status::S_DEAD;
	std::cout << playerList[21].name << " was killed\n";

	playerList[7].status = Status::S_DEAD;
	std::cout << playerList[7].name << " was killed\n";

	playerList[11].status = Status::S_DEAD;
	std::cout << playerList[11].name << " was killed\n";
}

int getAlive(AllPlayers& playerList)
{
	int aliveCount{ 0 };

	for (auto player : playerList)					//check how many players are still alive
	{
		if (player.status == Status::S_ALIVE)
		{
			++aliveCount;							//the number of alive players
		}
	}

	auto maxPlayer{ static_cast<int>(PlayerID::ID_MAX) - 1 };

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

	return aliveCount;
}

PlayerVector getAliveList(AllPlayers& playerList, int aliveCount)
{
	std::vector<Player> aliveList(aliveCount);			//create a list the size of the number of alive players

	for (int index{ 0 }; index < aliveCount; ++index)	//since the playerlist was sorted "Alive first" we fill the alivelist until we meet a dead player(aliveCount+1)
	{
		aliveList[index] = playerList[index];
	}

	return aliveList;									//return a vector made only of alive players
}

void printAlive(std::vector<Player>& playerList)
{
	for (const auto& newPlayer : playerList)
	{
		printPlayer(newPlayer);
		std::cout << '\n';
	}
}

PlayerVector aliveCheck(AllPlayers& playerList)
{
	int aliveCount{ getAlive(playerList) };
	PlayerVector aliveList{ getAliveList(playerList,aliveCount) };

	return aliveList;
}