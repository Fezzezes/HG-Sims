#ifndef GETALIVELIST_H
#define GETALIVELIST_H

using PlayerVector = std::vector <Player>;

int getAlive(AllPlayers& playerList);

PlayerVector getAliveList(AllPlayers& playerList, int aliveCount);

PlayerVector aliveCheck(AllPlayers& playerList);


#endif // !GETALIVELIST_H
