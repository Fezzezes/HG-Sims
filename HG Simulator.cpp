#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

#include"EnumClass.h"
#include"InitializeGame.h"

void killPlayerTest(AllPlayers& allPlayers)
{
	allPlayers[0].status = Status::S_DEAD;
	std::cout << allPlayers[0].name << " was killed\n";

	allPlayers[4].status = Status::S_DEAD;
	std::cout << allPlayers[4].name << " was killed\n";

	allPlayers[8].status = Status::S_DEAD;
	std::cout << allPlayers[8].name << " was killed\n";

	allPlayers[21].status = Status::S_DEAD;
	std::cout << allPlayers[21].name << " was killed\n";

	allPlayers[7].status = Status::S_DEAD;
	std::cout << allPlayers[7].name << " was killed\n";

	allPlayers[11].status = Status::S_DEAD;
	std::cout << allPlayers[11].name << " was killed\n";
}

int getAlive(AllPlayers &allPlayers)
{
	int stillAlive{ 0 };

	for (auto player : allPlayers)					//check how many players are still alive
	{
		if (player.status == Status::S_ALIVE)
		{
			++stillAlive;
		}
	}

	auto maxPlayer{ static_cast<int>(PlayerID::ID_MAX) - 1 };

	for (int current{ 0 }; current < maxPlayer; ++current)	//sort alive first, dead last
	{
		for (int next{ current + 1 }; next < maxPlayer; ++next)
		{
			if (allPlayers[current].status == Status::S_DEAD)
			{
			/*	std::cout << "Swapping " << allPlayers[current].name << "(dead) for " << allPlayers[next].name << '\n';*/ //Print the sawpping for testing
				std::swap(allPlayers[current], allPlayers[next]);
			}
			else
				break;
		}
	}
	
	return stillAlive;
}

void printAlive(AllPlayers& allPlayers)
{
	for (const auto& newPlayer : allPlayers)
	{
		printPlayer(newPlayer);
		std::cout << '\n';
	}
}

//std::vector <Player, > getOffensive(AllPlayers allPlayers)
//{
//	std::vector <Player> offensivePlayer;
//
//	return offensivePlayer;
//}

int main()
{
	AllPlayers allPlayers{ initializeGame() };

	killPlayerTest(allPlayers);

	int stillAlive{ getAlive(allPlayers) };
	std::cout << "\n\nSort by Alive\n\n";
	printAlive(allPlayers);

	std::cout << "\n\n" << stillAlive << "\n\n"; //check how many alive

	return 0;
}
