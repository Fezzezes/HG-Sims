#ifndef GETALIVELIST_H
#define GETALIVELIST_H

int getAlive(AllPlayers& playerList);

std::vector <Player> getAliveList(AllPlayers& playerList, int aliveCount);

std::vector <Player> aliveCheck(AllPlayers& playerList);


#endif // !GETALIVELIST_H
