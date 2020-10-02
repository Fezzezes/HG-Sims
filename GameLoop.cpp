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
void shuffleAliveList(PlayerVector& aliveList)
{
	auto seed{ getRandomNumber() };

	std::shuffle(aliveList.begin(), aliveList.end(), seed);
}

//Print weapons
std::string printWeapons	 (AllPlayers& aliveList, const int player)
{
	if (aliveList[player].weapons == Weapons::WP_ROCK)
	{
		return "rock";
	}
	//WOODEN STICK	 (05)
	else if (aliveList[player].weapons == Weapons::WP_WOODENSTICK)
	{
		return "wooden stick";
	}
	//CRAFTED SPEAR  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSPEAR)
	{
		return "crafted spear";
	}
	//CRAFTED SHIVE  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSHIVE)
	{
		return "crafted shive";
	}
	//KNIFE			 (15)
	else if (aliveList[player].weapons == Weapons::WP_KNIFE)
	{
		return "knife";
	}
	//HAMMER		 (15)
	else if (aliveList[player].weapons == Weapons::WP_HAMMER)
	{
		return "hammer";
	}
	//SWORD			 (20)
	else if (aliveList[player].weapons == Weapons::WP_SWORD)
	{
		return  "sword";
	}
	//BOW			 (20)
	else if (aliveList[player].weapons == Weapons::WP_BOW)
	{
		return  "bow and arrow";
	}
	//SPONSOREDSPEAR (20)
	else if (aliveList[player].weapons == Weapons::WP_SPONSOREDSPEAR)
	{
		return  "spear";
	}
	//TRIDENT		 (30)
	else if (aliveList[player].weapons == Weapons::WP_TRIDENT)
	{
		return  "trident";
	}
	//CROSSBOW		 (30)
	else if (aliveList[player].weapons == Weapons::WP_CROSSBOW)
	{
		return  "crossbow";
	}

	return "no weapon";
}
std::string printWeaponsDeath(PlayerVector& aliveList, const int player)
{
	if (aliveList[player].weapons == Weapons::WP_ROCK)
	{
		return "'s head was smashed with a rock by ";
	}
	//WOODEN STICK	 (05)
	else if (aliveList[player].weapons == Weapons::WP_WOODENSTICK)
	{
		return " was beaten to death  with a wooden stick by ";
	}
	//CRAFTED SPEAR  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSPEAR)
	{
		return " was impaled with a crafted spear by ";
	}
	//CRAFTED SHIVE  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSHIVE)
	{
		return " was stabbed with a crafted shive by ";
	}
	//KNIFE			 (15)
	else if (aliveList[player].weapons == Weapons::WP_KNIFE)
	{
		return " was stabbed with a knife by ";
	}
	//HAMMER		 (15)
	else if (aliveList[player].weapons == Weapons::WP_HAMMER)
	{
		return " was smashed with a hammer by ";
	}
	//SWORD			 (20)
	else if (aliveList[player].weapons == Weapons::WP_SWORD)
	{
		return  " was decapited with a sword by ";
	}
	//BOW			 (20)
	else if (aliveList[player].weapons == Weapons::WP_BOW)
	{
		return  " was pierced by an arrow shot by ";
	}
	//SPONSOREDSPEAR (20)
	else if (aliveList[player].weapons == Weapons::WP_SPONSOREDSPEAR)
	{
		return  " was impaled with a spear by";
	}
	//TRIDENT		 (30)
	else if (aliveList[player].weapons == Weapons::WP_TRIDENT)
	{
		return  " was impaled with a trident by ";
	}
	//CROSSBOW		 (30)
	else if (aliveList[player].weapons == Weapons::WP_CROSSBOW)
	{
		return  " was shot with a crossbow by ";
	}

	return "no weapon";
}

//Mods Check
int weaponsCheck	(PlayerVector& aliveList, const int player)
{
	//ROCK			 (05)
	if (aliveList[player].weapons == Weapons::WP_ROCK)
	{
		return 5;
	}
	//WOODEN STICK	 (05)
	else if (aliveList[player].weapons == Weapons::WP_WOODENSTICK)
	{
		return 5;
	}
	//CRAFTED SPEAR  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSPEAR)
	{
		return 10;
	}
	//CRAFTED SHIVE  (10)
	else if (aliveList[player].weapons == Weapons::WP_CRAFTEDSHIVE)
	{
		return 10;
	}
	//KNIFE			 (15)
	else if (aliveList[player].weapons == Weapons::WP_KNIFE)
	{
		return 15;
	}
	//HAMMER		 (15)
	else if (aliveList[player].weapons == Weapons::WP_HAMMER)
	{
		return 15;
	}
	//SWORD			 (20)
	else if (aliveList[player].weapons == Weapons::WP_SWORD)
	{
		return  20;
	}
	//BOW			 (20)
	else if (aliveList[player].weapons == Weapons::WP_BOW)
	{
		return  20;
	}
	//SPONSOREDSPEAR (20)
	else if (aliveList[player].weapons == Weapons::WP_SPONSOREDSPEAR)
	{
		return  20;
	}
	//TRIDENT		 (30)
	else if (aliveList[player].weapons == Weapons::WP_TRIDENT)
	{
		return  30;
	}
	//CROSSBOW		 (30)
	else if (aliveList[player].weapons == Weapons::WP_CROSSBOW)
	{
		return  30;
	}

	return 0;
}
void actionModCheck (int& maxSTK, int& maxATK, PlayerVector& aliveList, const int offPlayer)
{
	if (aliveList[offPlayer].actionMod.AC_AMBUSH)//check for action mod
	{
		maxSTK += 30; //STK(00,54)	IDLE(55,68)
		maxATK += 20; //ATK(69,69)
	}
	if (aliveList[offPlayer].actionMod.AC_HIDE)//check for action mod
	{
		maxSTK += 10; //STK(00,34)	IDLE(35,68)
		maxATK += 20; //ATK(69,69)
	}
	if (aliveList[offPlayer].actionMod.AC_ARMED)//check for action mod
	{
		maxSTK += 10; //STK(00,34)	IDLE(35,38)	
		maxATK -= 10; //ATK(39,69)	
	}
	if (aliveList[offPlayer].actionMod.AC_WOUNDED)//check for action mod
	{
		maxSTK -= 10; //STK(00,14)	IDLE(15,69)
		maxATK += 20; //ATK(69,69)
	}
	if (aliveList[offPlayer].actionMod.AC_ARMED)//check for action mod
	{
		maxSTK -= 5; //STK(00,19)	IDLE(20,53)
		maxATK += 5; //ATK(54,69)
	}
	if (aliveList[offPlayer].actionMod.AC_WET)//check for action mod
	{
		maxSTK -= 5; //STK(00,19)	IDLE(20,53)
		maxATK += 5; //ATK(54,69)
	}
	if (aliveList[offPlayer].actionMod.AC_STARVING)//check for action mod
	{
		maxSTK -= 10;//STK(00,14)	IDLE(15,53)
		maxATK += 5; //ATK(54,69
	}
	if (aliveList[offPlayer].actionMod.AC_SICK)//check for action mod
	{
		maxSTK -= 5; //STK(00,19)	IDLE(20,58)
		maxATK += 10;//ATK(59,69)
	}
}
void actionModCheck (PlayerVector& aliveList, const int offPlayer, const int defPlayer, Die& die)
{
	//Check Die Type
	if (die.type == DieType::AT_STALK)
	{
		//Check Off Mods
		if (aliveList[offPlayer].actionMod.SM_CAMOUFLAGED)
		{
			die.roll += 20;
		}
		//Check Def Mods
		if (aliveList[defPlayer].actionMod.AC_TIRED)
		{
			die.roll += 10;
		}
		if (aliveList[defPlayer].actionMod.AC_SICK)
		{
			die.roll += 10;
		}
	}
	//Check Die Type
	else if (die.type == DieType::AT_ATK)
	{
		//Check Off Success Mods
		if (aliveList[offPlayer].actionMod.AC_WOUNDED)
		{
			die.roll -= 15;
		}
		if (aliveList[offPlayer].actionMod.AC_AMBUSH)
		{
			die.roll += 15;
		}
		if (aliveList[offPlayer].actionMod.AC_ARMED)
		{
			die.roll += weaponsCheck(aliveList, offPlayer);
		}
		if (aliveList[offPlayer].actionMod.AC_SICK)
		{
			die.roll -= 5;
		}
		if (aliveList[offPlayer].actionMod.AC_STARVING)
		{
			die.roll -= 5;
		}
		if (aliveList[offPlayer].actionMod.AC_TIRED)
		{
			die.roll -= 5;
		}
		if (aliveList[offPlayer].actionMod.AC_WET)
		{
			die.roll = -5;
		}

		//Check Def Success Mods
		if (aliveList[defPlayer].actionMod.AC_WOUNDED)
		{
			die.roll += 15;
		}
		if (aliveList[defPlayer].actionMod.AC_AMBUSH)
		{
			die.roll -= 15;
		}
		if (aliveList[defPlayer].actionMod.AC_ARMED)
		{
			die.roll -= weaponsCheck(aliveList, defPlayer);
		}
		if (aliveList[defPlayer].actionMod.AC_SICK)
		{
			die.roll += 5;
		}
		if (aliveList[defPlayer].actionMod.AC_STARVING)
		{
			die.roll += 5;
		}
		if (aliveList[defPlayer].actionMod.AC_TIRED)
		{
			die.roll += 5;
		}
		if (aliveList[defPlayer].actionMod.AC_WET)
		{
			die.roll += 5;
		}


	}
}

//Sub Action Roll 
void craftingRoll	(PlayerVector& aliveList, const int player)
{
	Die dieCFT{ DieType::AT_CRAFT, getRandomDie(0,49) };

	aliveList[player].actionMod.AC_ARMED = true;
	//Get rock
	if (dieCFT.roll < 9)
	{
		aliveList[player].weapons = Weapons::WP_ROCK;
		std::cout << aliveList[player].name << " found a rock to use as a weapon \n";
	}
	//Get wooden stick
	else if (dieCFT.roll >= 10 && dieCFT.roll < 29)
	{
		aliveList[player].weapons = Weapons::WP_WOODENSTICK;
		std::cout << aliveList[player].name << " found a stick to use as a weapon \n";
	}
	//Get crafted spear
	else if (dieCFT.roll >= 30 && dieCFT.roll < 39)
	{
		aliveList[player].weapons = Weapons::WP_CRAFTEDSPEAR;
		std::cout << aliveList[player].name << " crafted a spear to use as a weapon \n";
	}
	//Get crafted shive
	else if (dieCFT.roll >= 40)
	{
		aliveList[player].weapons = Weapons::WP_CRAFTEDSHIVE;
		std::cout << aliveList[player].name << " crafted a shive to use as a weapon \n";
	}
}
void sponsorRoll	(PlayerVector& aliveList, const int player)
{
	Die dieSPS{ DieType::AT_SPONSER, getRandomDie(0,219) };

	//Get sword
	if (dieSPS.roll < 19)
	{
		aliveList[player].weapons = Weapons::WP_SWORD;
		std::cout << aliveList[player].name << " received a sword from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Bow
	else if (dieSPS.roll >= 20 && dieSPS.roll < 39)
	{
		aliveList[player].weapons = Weapons::WP_BOW;
		std::cout << aliveList[player].name << " received a bow and arrows from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Sponsor Spear
	else if (dieSPS.roll >= 40 && dieSPS.roll < 59)
	{
		aliveList[player].weapons = Weapons::WP_SPONSOREDSPEAR;
		std::cout << aliveList[player].name << " received a metal spear from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Knife
	else if (dieSPS.roll >= 60 && dieSPS.roll < 79)
	{
		aliveList[player].weapons = Weapons::WP_KNIFE;
		std::cout << aliveList[player].name << " received a knife from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Mine (does nothing so far)
	else if (dieSPS.roll >= 80 && dieSPS.roll < 89)
	{
		aliveList[player].weapons = Weapons::WP_NORMAL;
		std::cout << aliveList[player].name << " received an encouragement letter from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Hammer
	else if (dieSPS.roll >= 90 && dieSPS.roll < 99)
	{
		aliveList[player].weapons = Weapons::WP_HAMMER;
		std::cout << aliveList[player].name << " received a hammer from a sponsor \n";
		aliveList[player].actionMod.AC_ARMED = true;
	}
	//Get Bandages
	else if (dieSPS.roll >= 100 && dieSPS.roll < 129)
	{
		aliveList[player].misc = MiscItem::MI_BANDAGES;
		std::cout << aliveList[player].name << " received bandages from a sponsor \n";
	}
	//Get Food
	else if (dieSPS.roll >= 130 && dieSPS.roll < 169)
	{
		aliveList[player].misc = MiscItem::MI_FOOD;
		std::cout << aliveList[player].name << " received food from a sponsor \n";

	}
	//Get Pills
	else if (dieSPS.roll >= 170 && dieSPS.roll < 199)
	{
		aliveList[player].misc = MiscItem::MI_PILLS;
		std::cout << aliveList[player].name << " received medicine from a sponsor \n";
	}
	//Get Camouflage
	else if (dieSPS.roll >= 200 && dieSPS.roll < 219)
	{
		aliveList[player].actionMod.SM_CAMOUFLAGED = true;
		std::cout << aliveList[player].name << " received a camouflage kit from a sponsor \n";
	}

}
void randomEvent	(PlayerVector& aliveList, const int player)
{
	Die dieEvent{ DieType::AT_EVENT, getRandomDie(0,39) };
	bool tossUp{ static_cast<bool>(getRandomDie(0,1)) };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//Falling
	if (dieEvent.roll < 9)
	{
		//Wounded by falling
		if (tossUp)
		{
			aliveList[player].actionMod.AC_WOUNDED = true;
			std::cout << aliveList[player].name << " fell and hurted himself \n";
		}
		//Killed by falling
		else
		{
			SetConsoleTextAttribute(hConsole, 0x0c);
			aliveList[player].status = Status::S_DEAD;
			std::cout << aliveList[player].name << " fell and died \n";
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
	//Crossing Waters
	else if (dieEvent.roll >= 10 && dieEvent.roll < 19)
	{
		//Get wet by crossing waters
		if (tossUp)
		{
			aliveList[player].actionMod.AC_WET = true;
			std::cout << aliveList[player].name << " tried to cross a river and is now wet and cold \n";
		}
		//Died from Drowning
		else
		{
			SetConsoleTextAttribute(hConsole, 0x0c);
			aliveList[player].status = Status::S_DEAD;
			std::cout << aliveList[player].name << " drowned \n";
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
	//Hunger
	else if (dieEvent.roll >= 20 && dieEvent.roll < 29)
	{
		//Is hungry
		if (tossUp)
		{

			aliveList[player].actionMod.AC_STARVING = true;
			std::cout << aliveList[player].name << " is really hungry \n";
		}
		//Starved to death
		else
		{
			SetConsoleTextAttribute(hConsole, 0x0c);
			aliveList[player].status = Status::S_DEAD;
			std::cout << aliveList[player].name << " starved to death \n";
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
	//Poisonned by flora
	else if (dieEvent.roll >= 30 && dieEvent.roll < 39)
	{
		//Get sick by flora
		if (tossUp)
		{
			aliveList[player].actionMod.AC_SICK = true;
			aliveList[player].actionMod.AC_STARVING = false;

			std::cout << aliveList[player].name << " ate some mushrooms and is now sick \n";
		}
		//Kill by flora
		else
		{
			SetConsoleTextAttribute(hConsole, 0x0c);
			aliveList[player].status = Status::S_DEAD;
			std::cout << aliveList[player].name << " ate some mushrooms and died horribly \n";
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
}

//Execute Action Roll
void attackRoll	(PlayerVector& aliveList, const int offPlayer, const int defPlayer)
{
	Die dieATK{ DieType::AT_ATK, getRandomDie(0,94) };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//add mods to die roll
	actionModCheck(aliveList, offPlayer, defPlayer, dieATK);

	//Off is killed
	if (dieATK.roll < 20) //(20)
	{
		//Off is killed
		aliveList[offPlayer].status = Status::S_DEAD;
		aliveList[defPlayer].kills += 1;
		//Def CheckLoot();

		SetConsoleTextAttribute(hConsole, 0x0c);

		//adds the weapon's description to thekill comment
		if (aliveList[defPlayer].actionMod.AC_ARMED == true)
		{
			std::cout << aliveList[offPlayer].name << printWeaponsDeath(aliveList, defPlayer) << aliveList[defPlayer].name << '\n';
		}
		//default kill comment
		else
		{
			std::cout << aliveList[offPlayer].name << " was outmatched by " << aliveList[defPlayer].name << '\n';
		}

		//Def CheckLoot();
		SetConsoleTextAttribute(hConsole, 7);
	}
	//Off is wounded
	else if (dieATK.roll >= 20 && dieATK.roll < 34) //(15)
	{
		//Off is wounded
		aliveList[offPlayer].actionMod.AC_WOUNDED = true;

		std::cout << aliveList[offPlayer].name << " tried to attack " << aliveList[defPlayer].name << " but was wounded \n";
	}
	//Off runs aways
	else if (dieATK.roll >= 35 && dieATK.roll < 44) //(10)
	{
		//Off runs aways
		aliveList[offPlayer].actionMod.AC_TIRED = true;

		std::cout << aliveList[offPlayer].name << " tried to attack " << aliveList[defPlayer].name << " but had to retreat \n";
	}
	//Off and Def are wounded
	else if (dieATK.roll >= 45 && dieATK.roll < 49) //(10)

	{
		//Off is wounded
		aliveList[offPlayer].actionMod.AC_WOUNDED = true;

		//def is wounded
		aliveList[defPlayer].actionMod.AC_WOUNDED = true;

		std::cout << aliveList[offPlayer].name << " attacked " << aliveList[defPlayer].name << " and both were wounded \n";
	}
	//def runs aways
	else if (dieATK.roll >= 50 && dieATK.roll < 59) //(10)
	{
		//def runs aways
		aliveList[defPlayer].actionMod.AC_TIRED = true;

		std::cout << aliveList[offPlayer].name << " attacked but " << aliveList[defPlayer].name << " escaped \n";
	}
	//def is wounded
	else if (dieATK.roll >= 60 && dieATK.roll < 74) //(15)
	{
		//def is wounded
		aliveList[defPlayer].actionMod.AC_WOUNDED = true;

		std::cout << aliveList[offPlayer].name << " attacked and wounded " << aliveList[defPlayer].name << " \n";
	}
	//def is killed
	else if (dieATK.roll >= 75) //(20)
	{
		//def is killed
		aliveList[defPlayer].status = Status::S_DEAD;
		aliveList[offPlayer].kills += 1;

		SetConsoleTextAttribute(hConsole, 0x0c);

		//add the weapon's description to the kill comment
		if (aliveList[defPlayer].actionMod.AC_ARMED == true)
		{
			std::cout << aliveList[defPlayer].name << printWeaponsDeath(aliveList, defPlayer) << aliveList[offPlayer].name << '\n';
		}
		//default kill comment
		else
		{
			//off CheckLoot();
			std::cout << aliveList[offPlayer].name << " attacked and killed " << aliveList[defPlayer].name << " \n";
		}
		SetConsoleTextAttribute(hConsole, 7);

		//off CheckLoot();
	}
}
void stalkRoll	(PlayerVector& aliveList, const int offPlayer, const int defPlayer)
{
	Die dieSTK{ DieType::AT_STALK, getRandomDie(0, 70) };

	//add mods to die roll
	actionModCheck(aliveList, offPlayer, defPlayer, dieSTK);

	//Off is discovered
	if (dieSTK.roll < 20)	//0 to 19 (20)
	{
		//discovered = Normal AttackRoll
		std::cout << aliveList[offPlayer].name << " tried to stalk " << aliveList[defPlayer].name << " but was spotted\n";
		attackRoll(aliveList, offPlayer, defPlayer);

	}
	//Off is heard just before striking
	else if (dieSTK.roll >= 20 && dieSTK.roll < 50)	//20 to 49 (30)
	{
		//Heard
		aliveList[offPlayer].actionMod.AC_AMBUSH = true;
		std::cout << aliveList[offPlayer].name << " ambushed " << aliveList[defPlayer].name << " but " << aliveList[defPlayer].name << " reacted quickly \n";
		attackRoll(aliveList, offPlayer, defPlayer);
		aliveList[offPlayer].actionMod.AC_AMBUSH = false;


	}
	//Off successfully ambush and surprise def
	else if (dieSTK.roll >= 50)	//50 to 70+ (20)
	{
		//Ambush SuccessFul
		aliveList[offPlayer].actionMod.AC_AMBUSH = true;
		aliveList[defPlayer].actionMod.SM_SURPRISED = true;
		std::cout << aliveList[offPlayer].name << " ambushed " << aliveList[defPlayer].name << " and " << aliveList[defPlayer].name << " was surprised \n";
		attackRoll(aliveList, offPlayer, defPlayer);
		aliveList[offPlayer].actionMod.AC_AMBUSH = false;
		aliveList[defPlayer].actionMod.SM_SURPRISED = false;



	}
}
void idleRoll	(PlayerVector& aliveList, const int player)
{
	Die dieIDLE{ DieType::AT_IDLE, getRandomDie(0,84) };

	//Resting
	if (dieIDLE.roll < 19)
	{
		//Resting remove some negative Mods
		if (aliveList[player].actionMod.AC_TIRED == true)
		{
			aliveList[player].actionMod.AC_TIRED = false;

		}
		if (aliveList[player].actionMod.AC_WET == true)
		{
			aliveList[player].actionMod.AC_WET = false;
		}

		std::cout << aliveList[player].name << " found a spot to rest \n";
	}
	//Hiding
	else if (dieIDLE.roll >= 20 && dieIDLE.roll < 39)
	{
		if (aliveList[player].weapons == Weapons::WP_NORMAL)
		{

			aliveList[player].actionMod.AC_HIDE = true;
			std::cout << aliveList[player].name << " found a spot to hide \n";
		}
		else
		{
			aliveList[player].actionMod.AC_AMBUSH = true;
			std::cout << aliveList[player].name << " found a spot to potentially ambush someone \n";
		}


	}
	//Crafting
	else if (dieIDLE.roll >= 40 && dieIDLE.roll < 59)
	{
		craftingRoll(aliveList, player);

	}
	//Sponsor
	else if (dieIDLE.roll >= 60 && dieIDLE.roll < 69)
	{
		sponsorRoll(aliveList, player);
	}
	//Random Event
	else if (dieIDLE.roll >= 70)
	{
		randomEvent(aliveList, player);
	}
}

//Get Action Roll
void getActionRoll	(PlayerVector& aliveList, const int offPlayer, const int defPlayer)
{
	int maxSTK{ 24 };	// 0 to 24 (25) = Action Stalk
	int maxATK{ 49 };	// 0 to 49 (25) = Action Idle
	int maxIDLE{ 69 };	// 0 ti 69 (25) = Action Attack

	//check action modifier
	actionModCheck(maxSTK, maxATK, aliveList, offPlayer);

	auto actionDie{ getRandomDie(0,maxIDLE) }; //create an action die

	//Start a Stalk Roll
	if (actionDie < maxSTK)
	{
		stalkRoll(aliveList, offPlayer, defPlayer);
	}
	//Start an Idle Roll
	else if (actionDie >= maxSTK && actionDie < maxATK)
	{
		idleRoll(aliveList, defPlayer);
		idleRoll(aliveList, offPlayer);
	}
	//Start an Attack Roll
	else if (actionDie >= maxATK)
	{
		attackRoll(aliveList, offPlayer, defPlayer);
	}
}
void setPlayerPhase	(PlayerVector& aliveList)
{
	shuffleAliveList(aliveList);

	int offPlayer{ (static_cast<int>(aliveList.size()) / 2) };
	int secondHalf{ static_cast<int>(aliveList.size()) };

	for (int defPlayer{}; offPlayer < secondHalf; ++defPlayer)
	{
		if (defPlayer == secondHalf)
		{
			aliveList[defPlayer].phase = Phase::PHASE_DEF;
			idleRoll(aliveList, defPlayer);
			++offPlayer;
		}
		else
		{
			aliveList[offPlayer].phase = Phase::PHASE_OFF;
			aliveList[defPlayer].phase = Phase::PHASE_DEF;
			getActionRoll(aliveList, offPlayer, defPlayer);
			++offPlayer;
		}
	}

	////first half is set to DEFENSIVE, if uneven surplus goes to def
	//for (int DefPlayer{}; DefPlayer < firstHalf; ++DefPlayer)
	//{
	//	aliveList[DefPlayer].phase = Phase::PHASE_OFF;
	//}
	////second half is set to OFFENSIVE
	//for (int OffPlayer{ firstHalf }; OffPlayer < secondHalf; ++OffPlayer)
	//{
	//	aliveList[OffPlayer].phase = Phase::PHASE_DEF;
	//	rollOffense(aliveList, OffPlayer);
	//}
}

//udpate Player Status on the PlayerList based on the most recent AliveList
void updatePlayerList	(PlayerVector& aliveList, AllPlayers& playerList)
{
	int aliveListLenght{ static_cast<int>(aliveList.size()) };
	int playerListLenght{ static_cast<int>(playerList.size()) };

	//sort playerList by ID
	for (int current{ 0 }; current < playerListLenght; ++current)
	{
		for (int next{ current + 1 }; next < playerListLenght; ++next)
		{
			if (playerList[current].ID > playerList[next].ID)
			{
				std::swap(playerList[current], playerList[next]);

			}
		}
	}

	//use aliveList's IDs to update the status of Players in playerList
	int playerIndex{};
	for (int player{}; player < aliveListLenght; ++player)
	{

		switch (aliveList[player].ID)
		{
		case PlayerID::ID_00:
			playerIndex = 0;
			break;
		case PlayerID::ID_01:
			playerIndex = 1;
			break;
		case PlayerID::ID_02:
			playerIndex = 2;
			break;
		case PlayerID::ID_03:
			playerIndex = 3;
			break;
		case PlayerID::ID_04:
			playerIndex = 4;
			break;
		case PlayerID::ID_05:
			playerIndex = 5;
			break;
		case PlayerID::ID_06:
			playerIndex = 6;
			break;
		case PlayerID::ID_07:
			playerIndex = 7;
			break;
		case PlayerID::ID_08:
			playerIndex = 8;
			break;
		case PlayerID::ID_09:
			playerIndex = 9;
			break;
		case PlayerID::ID_10:
			playerIndex = 10;
			break;
		case PlayerID::ID_11:
			playerIndex = 11;
			break;
		case PlayerID::ID_12:
			playerIndex = 12;
			break;
		case PlayerID::ID_13:
			playerIndex = 13;
			break;
		case PlayerID::ID_14:
			playerIndex = 14;
			break;
		case PlayerID::ID_15:
			playerIndex = 15;
			break;
		case PlayerID::ID_16:
			playerIndex = 16;
			break;
		case PlayerID::ID_17:
			playerIndex = 17;
			break;
		case PlayerID::ID_18:
			playerIndex = 18;
			break;
		case PlayerID::ID_19:
			playerIndex = 19;
			break;
		case PlayerID::ID_20:
			playerIndex = 20;
			break;
		case PlayerID::ID_21:
			playerIndex = 21;
			break;
		case PlayerID::ID_22:
			playerIndex = 22;
			break;
		case PlayerID::ID_23:
			playerIndex = 23;
			break;
		}

		playerList[playerIndex].status = aliveList[player].status;
		playerList[playerIndex].actionMod = aliveList[player].actionMod;
		playerList[playerIndex].kills = aliveList[player].kills;
		playerList[playerIndex].weapons = aliveList[player].weapons;

	}
}
void showPlayerStats	(AllPlayers& playerList, const int index)
{
	std::cout << playerList[index].name << "'s status: \n\n";

	std::cout << "Kills: " << playerList[index].kills << '\n';

	if (playerList[index].actionMod.AC_AMBUSH)
	{
		std::cout << "Ambushed: Waiting for a potential target\n";
	}
	if (playerList[index].actionMod.AC_SICK)
	{
		std::cout << "Sick: Vulnerable if attacked, looking for medicine \n";
	}
	if (playerList[index].actionMod.AC_STARVING)
	{
		std::cout << "Hungry: Vulnerable if attacked, looking for food  \n";
	}
	if (playerList[index].actionMod.AC_TIRED)
	{
		std::cout << "Tired: Vulnerable if attacked, looking to rest \n";
	}
	if (playerList[index].actionMod.AC_WET)
	{
		std::cout << "Wet: Vulnerable if attacked, looking to rest and dry \n";
	}
	if (playerList[index].actionMod.AC_WOUNDED)
	{
		std::cout << "Wounded: Extremely vulnerable if attacked, looking for bandages \n";
	}
	if (playerList[index].actionMod.AC_ARMED)
	{
		std::cout << "Armed: Has a " << printWeapons(playerList, index) << " and is looking for a fight \n";
	}



}
void nextDay			(AllPlayers& playerList, bool& skip)
{
	if (!skip)
	{
		bool invalidInput{ true };
		std::string input{};
		do
		{
			std::cout << "-------------------------------------------------------------------------------------- \n";
			std::cout << "Enter the ID of a player to see his status, or write \"next\" to start the next day: ";
			std::cin >> input;
			std::cout << "-------------------------------------------------------------------------------------- \n";

			if (input == "next")
				invalidInput = false;				//Continue to next day

			else if (input == "skip")			//skip all days (end game)
			{
				invalidInput = false;
				skip = true;
			}

			else if (input == "00")					//Check player Stats
				showPlayerStats(playerList, 0);
			else if (input == "01")
				showPlayerStats(playerList, 1);
			else if (input == "02")
				showPlayerStats(playerList, 2);
			else if (input == "03")
				showPlayerStats(playerList, 3);
			else if (input == "04")
				showPlayerStats(playerList, 4);
			else if (input == "05")
				showPlayerStats(playerList, 5);
			else if (input == "06")
				showPlayerStats(playerList, 6);
			else if (input == "07")
				showPlayerStats(playerList, 7);
			else if (input == "08")
				showPlayerStats(playerList, 8);
			else if (input == "09")
				showPlayerStats(playerList, 9);
			else if (input == "10")
				showPlayerStats(playerList, 10);
			else if (input == "11")
				showPlayerStats(playerList, 11);
			else if (input == "12")
				showPlayerStats(playerList, 12);
			else if (input == "13")
				showPlayerStats(playerList, 13);
			else if (input == "14")
				showPlayerStats(playerList, 14);
			else if (input == "15")
				showPlayerStats(playerList, 15);
			else if (input == "16")
				showPlayerStats(playerList, 16);
			else if (input == "17")
				showPlayerStats(playerList, 17);
			else if (input == "18")
				showPlayerStats(playerList, 18);
			else if (input == "19")
				showPlayerStats(playerList, 19);
			else if (input == "20")
				showPlayerStats(playerList, 20);
			else if (input == "21")
				showPlayerStats(playerList, 21);
			else if (input == "22")
				showPlayerStats(playerList, 22);
			else if (input == "23")
				showPlayerStats(playerList, 23);

			else
			{
				if (std::cin.fail())
				{
					std::cin.clear();
					std::cin.ignore(32767, '\n');
					std::cout << "Invalid Input, try again! (ex:\"00\",\"next\")\n";
					invalidInput = true;
				}
			}
			std::cin.ignore(32767, '\n');

		} while (invalidInput);

	}
}

//Check if there is a winner(vector size 1) or a tie(vector size 0)
bool getWinner			(PlayerVector& aliveList)
{
	int aliveListSize{ static_cast<int>(aliveList.size()) };

	//if aliveList has a size of 1, then there is a winner!
	if (aliveListSize == 1)
	{
		std::cout << aliveList[0].name << " is victorious! \n";
		return false;
	}

	//If aliveList is 0, then there is no winner...
	if (aliveListSize == 0)
	{
		std::cout << "Everybody died, nobody wins... \n";
		return false;
	}

	//if aliveList is bigger than 1, then the game must continue
	return true;
}

//Ask the user if he wants to play again
bool playAgain()
{
	char retry{};

	while (true)
	{
		std::cout << "Play again? (y/n): ";
		std::cin >> retry;

		//'y' to play again
		if (retry == 'y')
		{
			std::cout << "\n-------------------------------------------------------------------------------------- \n";
			return true;
		}

		//'n' to stop playing
		else if (retry == 'n')
		{
			std::cout << "\n-------------------------------------------------------------------------------------- \n";
			return false;
		}

		//any other input is invalid the while loop the retry question.
		else
		{
			std::cout << "Invalid input! Write 'y' to play again or 'n' to stop playing! \n";
		}

		//if the cin fails
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
		}

		//clear excess cin (happens with string)
		std::cin.ignore(32767, '\n');
	}

	//default but should never happen
	std::cout << "Something went wrong, ending the game. \n";
	return false;
}