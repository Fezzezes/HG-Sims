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
	//create a vector of <Player> with Alive Status
	PlayerVector aliveList{};
	bool noWinner{}; //keep playing?
	bool retry   {}; //play again?
	bool skip {false}; //skip all days

	//game Initialization loop
	do
	{
		//initialize the game (create an 24 <Player> array)
		playerList = initializeGame();

		std::cout << "\n";

		//create a vector of <Player> with Alive Status
		aliveList = aliveCheck(playerList);

		nextDay(playerList, skip);

		//gameLoop
		noWinner = true;
		while (noWinner)
		{
			std::cout << "Today's events: \n-------------------------------------------------------------------------------------- \n";
			setPlayerPhase(aliveList);				 //Print today's event
			std::cout << "\nToday's Results: \n------------------------------------------------------------------------------------- \n";

			updatePlayerList(aliveList, playerList); //update the playerList with the status, modifiers and kills
			printAlive(playerList);					 //Print the scoreboard (playerList)
			
			nextDay(playerList, skip);					 //allow the player to see playerStats if desired or start the next day

			aliveList = aliveCheck(aliveList);		 //create the aliveList for the next day
			noWinner = getWinner(aliveList);		 //Look for a winner (or a tie), if true end the gameLoop

		}

		skip = false;
		retry = playAgain();

	}while (retry);

	return 0;
}
