#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <vector>

#include"EnumClass.h"
#include"InitializeGame.h"
#include"GetAliveList.h"


int main()
{
	AllPlayers playerList{ initializeGame() };

	std::vector <Player> aliveList{ aliveCheck(playerList) };
	
	return 0;
}
