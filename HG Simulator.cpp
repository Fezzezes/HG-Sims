#include <iostream>
#include <string>
#include <algorithm>
#include <array>

#include"EnumClass.h"

using AllPlayers = std::array<Player, 24>;
using Index_type = AllPlayers::size_type;

AllPlayers createPlayers()
{
	AllPlayers newPlayer{};
	/*Index_type playerIndex{ 0 }*/;

	auto maxID{ static_cast<int>(PlayerID::ID_MAX)-1 };
	auto maxTeam{ static_cast<int>(PlayerTeam::T_MAX) };
	int teamNB{ 1 };


	for (int id{ 0 }; id < maxID; ++id)
	{
		newPlayer[id].player_ID = static_cast<PlayerID>(id);
		newPlayer[id].player_Status = Status::S_ALIVE;
		newPlayer[id].player_Team = static_cast<PlayerTeam>(teamNB);
		/*newPlayer[playerIndex].player_Name = "Name: UNKNOWN";*/

		++teamNB;
		if (teamNB >= maxTeam)
		{
			teamNB = 1;
		}

		/*++playerIndex;*/
	}
	
	

	return newPlayer;
}

void printPlayer(Player player)
{
	std::string id{};
	std::string name{player.player_Name};
	std::string team{};
	std::string status{};
	int nameLenght{static_cast<int>( player.player_Name.length())};

	switch (player.player_ID)
	{
	case PlayerID::ID_00:
		id = "ID: 00";
		break;
	case PlayerID::ID_01:
		id = "ID: 01";
		break;
	case PlayerID::ID_02:
		id = "ID: 02";
		break;
	case PlayerID::ID_03:
		id = "ID: 03";
		break;
	case PlayerID::ID_04:
		id = "ID: 04";
		break;
	case PlayerID::ID_05:
		id = "ID: 05";
		break;
	case PlayerID::ID_06:
		id = "ID: 06";
		break;
	case PlayerID::ID_07:
		id = "ID: 07";
		break;
	case PlayerID::ID_08:
		id = "ID: 08";
		break;
	case PlayerID::ID_09:
		id = "ID: 09";
		break;
	case PlayerID::ID_10:
		id = "ID: 10";
		break;
	case PlayerID::ID_11:
		id = "ID: 11";
		break;
	case PlayerID::ID_12:
		id = "ID: 12";
		break;
	case PlayerID::ID_13:
		id = "ID: 13";
		break;
	case PlayerID::ID_14:
		id = "ID: 14";
		break;
	case PlayerID::ID_15:
		id = "ID: 15";
		break;
	case PlayerID::ID_16:
		id = "ID: 16";
		break;
	case PlayerID::ID_17:
		id = "ID: 17";
		break;
	case PlayerID::ID_18:
		id = "ID: 18";
		break;
	case PlayerID::ID_19:
		id = "ID: 19";
		break;
	case PlayerID::ID_20:
		id = "ID: 20";
		break;
	case PlayerID::ID_21:
		id = "ID: 21";
		break;
	case PlayerID::ID_22:
		id = "ID: 22";
		break;
	case PlayerID::ID_23:
		id = "ID: 23";
		break;
	case PlayerID::ID_24:
		id = "ID: 24";
		break;
		
	default:
		id = "Unkown ID";
	}
	switch (player.player_Team)
	{
	case PlayerTeam::T_01:
		team = "Team: 01";
		break;
	case PlayerTeam::T_02:
		team = "Team: 02";
		break;
	case PlayerTeam::T_03:
		team = "Team: 03";
		break;
	case PlayerTeam::T_04:
		team = "Team: 04";
		break;
	case PlayerTeam::T_05:
		team = "Team: 05";
		break;
	case PlayerTeam::T_06:
		team = "Team: 06";
		break;
	case PlayerTeam::T_07:
		team = "Team: 07";
		break;
	case PlayerTeam::T_08:
		team = "Team: 08";
		break;
	case PlayerTeam::T_09:
		team = "Team: 09";
		break;
	case PlayerTeam::T_10:
		team = "Team: 10";
		break;
	case PlayerTeam::T_11:
		team = "Team: 11";
		break;
	case PlayerTeam::T_12:
		team = "Team: 12";
		break;

	default:
		team = "Unknown Team";
	}
	switch (player.player_Status)
	{
	case Status::S_ALIVE:
		status = "Status: Alive";
		break;
	case Status::S_DEAD:
		status = "Status: Dead";
		break;

	default:
		status = "Unknown Status";
	}


	std::cout << name;

	if(nameLenght < 8)
		std::cout<< "\t\t"<< " | " << id << " | " << team << " | " << status;
	else
		std::cout << '\t' << " | " << id << " | " << team << " | " << status;

	/*std::cout << name   <<'\n';
	std::cout << id	    <<'\n';
	std::cout << team   <<'\n';
	std::cout << status <<'\n';*/
}

void sortTeam(AllPlayers& allPlayers)
{
	auto maxPlayer{ static_cast<int>(PlayerID::ID_MAX)-1};
	
	for (int current{ 0 }; current < maxPlayer; ++current)
	{
		for (int next{ current + 1 }; next < maxPlayer; ++next)
		{
			if (allPlayers[current].player_Team > allPlayers[next].player_Team)
			{
				std::swap(allPlayers[current], allPlayers[next]);

			}
		}
	}

}

void printAllPlayers(AllPlayers &allPlayers)
{
	sortTeam(allPlayers);

	for (const auto& newPlayer : allPlayers)
	{
		printPlayer(newPlayer);
		std::cout << '\n';
	}
}

std::string validatePlayerName()
{
	std::string username;
	int nameLenght{};
	bool invalidInput{ false };

	do
	{
		

		invalidInput = false;
		std::cout << "Enter new contestant's name: ";
		std::cin >> username;
		
		nameLenght = static_cast<int>(username.length());

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid name! (invalid characters)\n";
			invalidInput = true;
		}
		else if (nameLenght >= 15)
		{
			std::cin.ignore(32767, '\n');
			std::cout << "Invalid name! (longer than 15 characters)\n";
			invalidInput = true;
		}
		else
			std::cin.ignore(32767, '\n');

	} while (invalidInput);

	return username;
}

void getPlayerName(AllPlayers &player)
{
	int ID{0};
	int maxPlayer{24};

	for (ID; ID < maxPlayer; ++ID)
	{
		std::cout << "Enter \"-fillrest\" to generate a name for the remaining players\n";
		std::string username{ validatePlayerName()};
		
		if (username == "-fillrest")
			break;
		
		player[ID].player_Name = username;
	}

	for (ID; ID < maxPlayer; ++ID)
	{
		std::string botname;

		switch (ID+1) // too lazy to recount
		{
		case 1:
			botname = "Marvel";
			break;
		case 2:
			botname = "Cato";
			break;
		case 3:
			botname = "Adi-Mundi";
			break;
		case 4:
			botname = "Plokoon";
			break;
		case 5:
			botname = "Yarael-Poof";
			break;
		case 6:
			botname = "Jason";
			break;
		case 7:
			botname = "Windu";
			break;
		case 8:
			botname = "Obiwan";
			break;
		case 9:
			botname = "Kit";
			break;
		case 10:
			botname = "Qui-gon";
			break;
		case 11:
			botname = "Thresh";
			break;
		case 12:
			botname = "Peeta";
			break;
		case 13:
			botname = "Glimmer";
			break;
		case 14:
			botname = "Clove";
			break;
		case 15:
			botname = "Luminara";
			break;
		case 16:
			botname = "Ashoka";
			break;
		case 17:
			botname = "FoxFace";
			break;
		case 18:
			botname = "Secura";
			break;
		case 19:
			botname = "Shaak-ti";
			break;
		case 20:
			botname = "Bariss";
			break;
		case 21:
			botname = "Yaddle";
			break;
		case 22:
			botname = "Gallia";
			break;
		case 23:
			botname = "Rue";
			break;
		case 24:
			botname = "Katniss";
			break;

		default:
			botname = "Unknown name";
		}
		player[ID].player_Name = botname;

	}
}

int main()
{
	AllPlayers All_Player{ createPlayers() };

	getPlayerName(All_Player);
	printAllPlayers(All_Player);

	return 0;
}
