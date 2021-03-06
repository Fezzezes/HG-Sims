#ifndef GAMELOOP_H
#define GAMELOOP_H

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

//Shuffle AliveList
void shuffleAliveList(AllPlayers& playerList);

//Print Weapons
std::string printWeapons(AllPlayers& playerList, const int player);
std::string printWeaponsDeath(AllPlayers& playerList, const int player);

//Mod Check
int weaponsCheck(AllPlayers& playerList, const int player);
void actionModCheck(int& maxSTK, int& maxATK, AllPlayers& playerList, const int offPlayer);
void actionModCheck(AllPlayers& playerList, const int offPlayer, const int defPlayer, Die& die);

//Sub Action Roll 
void craftingRoll(AllPlayers& playerList, const int player);
void sponsorRoll(AllPlayers& playerList, const int player);
void randomEvent(AllPlayers& playerList, const int player);

//Execute Action Roll
void attackRoll(AllPlayers& playerList, const int offPlayer, const int defPlayer);
void stalkRoll(AllPlayers& playerList, const int offPlayer, const int defPlayer);
void idleRoll(AllPlayers& playerList, const int player);

//Get Action Roll
void getActionRoll(AllPlayers& playerList, const int offPlayer, const int defPlayer);
void setPlayerPhase(AllPlayers& playerList);

//udpate Player Status on the PlayerList based on the most recent AliveList
void showPlayerStats(AllPlayers& playerList, const int index);
void nextDay(AllPlayers& playerList, bool& skip);

//Check if there is a winner(vector size 1) or a tie(vector size 0)
bool getWinner(AllPlayers& playerList);
//Ask the user if he wants to play again
bool playAgain();
#endif // !GAMELOOP_H

