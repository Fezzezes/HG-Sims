#include <iostream>
#include <string>
#include <algorithm>
#include <array>
#include <random>
#include <ctime>
#include <Windows.h>


//random number Generation
namespace MyRandom
{
std::mt19937 random{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
}
std::mt19937 getRandomNumber()
{
	return MyRandom::random;
}
int getRandomDie(int min, int max)
{
	std::uniform_int_distribution die{ min, max };
	return die(MyRandom::random);
}

//weapon quality
constexpr int trash		{ 5  };
constexpr int common	{ 10 };
constexpr int uncommon  { 15 };
constexpr int rare		{ 20 };
constexpr int legendary { 30 };

//enum Classes for Player
enum class Status
{
	S_ALIVE,
	S_DEAD,

	S_MAX,
};
enum class PlayerTeam
{
	T_00, T_01, T_02,
	T_03, T_04, T_05,
	T_06, T_07, T_08,
	T_09, T_10, T_11,
	T_12,

	T_MAX,
};
enum class PlayerName
{
	N_BRUTUS,	//0
	N_LYME,		//1
	N_BEETEE,	//2
	N_WIRESS,	//3
	N_TITUS,	//4
	N_BLIGHT,	//5
	N_WOOF,		//6
	N_CECELIA,	//7
	N_SEEDER,	//8
	N_CASHMERE,	//9
	N_GLOSS,	//10
	N_MARVEL,	//11
	N_GLIMMER,	//12
	N_CATO,		//13
	N_CLOVE,	//14
	N_FOXFACE,	//15
	N_THRESH,	//16
	N_RUE,		//17
	N_PEETA,	//18
	N_KATNISS,	//19
	N_YARELPOOF,//20
	N_PLOKOON,	//21
	N_ADIMUNDI,	//22
	N_LUMINARA,	//23
	N_BOB,		//24

	N_MAX
};
enum class PlayerID
{
	ID_00, ID_01, ID_02, ID_03,
	ID_04, ID_05, ID_06, ID_07,
	ID_08, ID_09, ID_10, ID_11,
	ID_12, ID_13, ID_14, ID_15,
	ID_16, ID_17, ID_18, ID_19,
	ID_20, ID_21, ID_22, ID_23,
	

	ID_MAX,
};
enum class Phase
{
	PHASE_DEF,
	PHASE_OFF,

	PHASE_MAX,
};
enum class Weapons
{
	WP_NORMAL,

	WP_CRAFTEDSPEAR,
	WP_CRAFTEDSHIVE,
	WP_ROCK,
	WP_WOODENSTICK,

	WP_SWORD,
	WP_BOW,
	WP_SPONSOREDSPEAR,
	WP_KNIFE,
	WP_HAMMER,
	WP_TRIDENT,
	WP_CROSSBOW,

	WP_MAX,
};
enum class MiscItem
{
	MI_GHILLIEMANTLE,
	MI_PILLS,
	MI_FOOD,
	MI_BANDAGES,
};

//enum Classes for Die
enum class DieType
{
	AT_STALK,
	AT_ATK,
	AT_IDLE,
	AT_CRAFT,
	AT_SPONSER,
	AT_EVENT,
};

//The Player Struct
struct ActionMod
{
	bool AC_NORMAL{};
	bool AC_AMBUSH{}; //
	bool AC_HIDE{};   //
	bool AC_ARMED{};
	bool AC_WOUNDED{};
	bool AC_TIRED{};
	bool AC_WET{};
	bool AC_STARVING{};
	bool AC_SICK{};

	bool SM_CAMOUFLAGED{};
	bool SM_SURPRISED{};
};

struct Player
{
	std::string name{};
	PlayerID	ID{};		//24 id
	PlayerTeam  team{};		//12 team
	Status	    status{};	//2 status
	Phase		phase{};
	ActionMod	actionMod{};
	Weapons		weapons{};
	int			wQuality{};
	MiscItem	misc{};
	int			kills{};
};
struct Die
{
	DieType type{};
	int roll{};
};



