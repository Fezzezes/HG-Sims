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
void shuffleAliveList(PlayerVector& aliveList);

//Print Weapons
std::string printWeapons(AllPlayers& aliveList, const int player);
std::string printWeaponsDeath(PlayerVector& aliveList, const int player);

//Mod Check
int weaponsCheck(PlayerVector& aliveList, const int player);
void actionModCheck(int& maxSTK, int& maxATK, PlayerVector& aliveList, const int offPlayer);
void actionModCheck(PlayerVector& aliveList, const int offPlayer, const int defPlayer, Die& die);

//Sub Action Roll 
void craftingRoll(PlayerVector& aliveList, const int player);
void sponsorRoll(PlayerVector& aliveList, const int player);
void randomEvent(PlayerVector& aliveList, const int player);

//Execute Action Roll
void attackRoll(PlayerVector& aliveList, const int offPlayer, const int defPlayer);
void stalkRoll(PlayerVector& aliveList, const int offPlayer, const int defPlayer);
void idleRoll(PlayerVector& aliveList, const int player);

//Get Action Roll
void getActionRoll(PlayerVector& aliveList, const int offPlayer, const int defPlayer);
void setPlayerPhase(PlayerVector& aliveList);

//udpate Player Status on the PlayerList based on the most recent AliveList
void updatePlayerList(PlayerVector& aliveList, AllPlayers& playerList);
void showPlayerStats(AllPlayers& playerList, const int index);
void nextDay(AllPlayers& playerList, bool& skip);

//Check if there is a winner(vector size 1) or a tie(vector size 0)
bool getWinner(PlayerVector& aliveList);
//Ask the user if he wants to play again
bool playAgain();
#endif // !GAMELOOP_H

