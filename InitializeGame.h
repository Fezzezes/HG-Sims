#ifndef INITIALIZEGAME_H
#define INITIALIZEGAME_H

using AllPlayers = std::array<Player, 24>;
using Index_type = AllPlayers::size_type;

AllPlayers createPlayers();

void printPlayer(Player player);
void sortTeam(AllPlayers& allPlayers);
void printAllPlayers(AllPlayers& allPlayers);
std::string validatePlayerName();
void getPlayerName(AllPlayers& player);

AllPlayers initializeGame();

#endif // !INITIALIZEGAME_H
