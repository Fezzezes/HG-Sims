#ifndef GETALIVELIST_H
#define GETALIVELIST_H

using PlayerVector = std::vector <Player>;

//getAliveList for array 
int getAlive(AllPlayers& playerList);
PlayerVector getAliveList(AllPlayers& playerList, int aliveCount);
PlayerVector aliveCheck(AllPlayers& playerList);

//getAliveList for vector
int getAlive(PlayerVector& playerList);
PlayerVector getAliveList(PlayerVector& playerList, int aliveCount);
PlayerVector aliveCheck(PlayerVector& playerList);

//for test purposes
void printAlive(PlayerVector &playerList);
void printAlive(AllPlayers& playerList);
void killPlayerTest(AllPlayers &playerList);
void killPlayerTest(PlayerVector& playerList);

#endif // !GETALIVELIST_H
