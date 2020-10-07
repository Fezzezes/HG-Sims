#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>
#include <algorithm>
#include <ctime>
#include <random>
#include <stdio.h>
#include <string>
#include <Windows.h>

#include"EnumClass.h"
#include"InitializeGame.h"
#include"GetAliveList.h"
#include"GameLoop.h"

int main()
{
	//initialize the game (create an 24 <Player> array)
	AllPlayers playerList{};

	bool noWinner{}; //keep playing?
	bool retry   {}; //play again?
	bool skip {false}; //skip all days

	//game Initialization loop
	do
	{
		//initialize the game (create an 24 <Player> array)
		playerList = initializeGame();

		std::cout << "\n";

		nextDay(playerList, skip);

		//gameLoop
		noWinner = true;
		while (noWinner)
		{
			std::cout << "Today's events: \n-------------------------------------------------------------------------------------- \n";
			setPlayerPhase(playerList);				 //Print today's event
			std::cout << "\nToday's Results: \n------------------------------------------------------------------------------------- \n";

			printAlive(playerList);					 //Print the scoreboard (playerList)
			
			nextDay(playerList, skip);				 //allow the player to see playerStats if desired or start the next day

			noWinner = getWinner(playerList);		 //Look for a winner (or a tie), if true end the gameLoop

		}

		skip = false;
		retry = playAgain();

	}while (retry);

	return 0;
}
