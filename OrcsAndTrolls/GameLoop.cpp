#include "GameLoop.h"


GameState::GameState()
{
	loopInput = 0;
	game = true;
	Update();
}

void GameState::Update()
{
	// character select
	while (loopInput == 0)
	{
		std::cout << "To claim the state the Orc clan and Troll nation has sent there greatist warriors to do decide the outcome,\nWhich side will you control:\n1) The Orcs\n2) The Trolls" << std::endl;
		std::cin >> loopInput;
		std::cout << "\n";

		switch (loopInput)
		{
		case 1:
			system("CLS");
			player = &Orc();
			enemy = &Troll();
			player->characterChoice();
			break;

		case 2:
			system("CLS");
			player = &Troll();
			enemy = &Orc();
			player->characterChoice();
			break;
			
		default:
			std::cout << "Error entering choice\n" << std::endl;
			loopInput = 0;
			break;
		}
	}


	// game loop
	while (game == true)
	{
		if (player->hp == 0)
		{
			system("CLS");
			std::cout << "You have met your end and brought disapointment to everyone in the imediate area,\n\tGame Over" << std::endl;
			system("Pause");
			game = false;
		}
		else
		{
			std::cout << "Players health: " << player->hp << ", enemys remaining: " << enemy->hp << std::endl;
			system("Pause");

			player->update();
			enemy->update();
			lastRoundHp = enemy->hp;
			damageCalculation();
		}
	}
}

//win, lose or draw calculations
void GameState::damageCalculation()
{
	if (player->shieldValue == true)
	{
		std::cout << "You use a shield to block the enemy attack" << std::endl;
		system("Pause");
		player->shieldValue = false;
	}
	else
	{
		//melee
		if (player->meleeValue > 0)
		{
			if (player->meleeValue == enemy->meleeValue)
			{ 
				std::cout << "Both you and your opponent use the same wepon and come to a draw" << std::endl;
				system("Pause");
			}
			else if (player->meleeValue == 1 && enemy->meleeValue == 2
				|| player->meleeValue == 2 && enemy->meleeValue == 3
				|| player->meleeValue == 3 && enemy->meleeValue == 1)
			{
				std::cout << "You take a swing and chop your opponents head clean off\nThe croud goes wild" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else if (player->meleeValue == 4)
			{
				std::cout << "You draw your spoon and eat some cerial, your opponent gets scared and decide to retire to a simpler life and leaves the battlefield" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else
			{
				std::cout << "You try to swing but miss and get stabed in the groin\nThe croud grows silent, then laughs at you" << std::endl;
				player->hp -= 1;
				system("Pause");
			}

		}

		//ranged
		else if (player->rangedValue > 0)
		{
			if (player->rangedValue == enemy->rangedValue)
			{
				std::cout << "Both you and your opponent fire your wepons and the shots collide mid air" << std::endl;
				system("Pause");
			}
			else if (player->rangedValue == 1 && enemy->rangedValue == 2
				|| player->rangedValue == 2 && enemy->rangedValue == 3
				|| player->rangedValue == 3 && enemy->rangedValue == 1)
			{
				std::cout << "You fire your wepon and blow a hole in your opponents chest\nThe croud goes wild" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else if (player->rangedValue == 4)
			{
				std::cout << "You load the Trebuchet with crossbows and fire them into the air raining both arrows and crossbows onto your enemy" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else
			{
				std::cout << "You fire you wepon but miss, the enemys arrow goes straight into your knee\nThe croud grows silent, then laughs at you" << std::endl;
				player->hp -= 1;
				system("Pause");
			}
		}

		//magic 
		else if (player->magicValue > 0)
		{
			if (player->magicValue == enemy->magicValue)
			{
				std::cout << "You both use the same spell on one another and end up canceling out the magic" << std::endl;
				system("Pause");
			}
			else if (player->magicValue == 1 && enemy->magicValue == 2
				|| player->magicValue == 2 && enemy->magicValue == 3
				|| player->magicValue == 3 && enemy->magicValue == 1)
			{
				std::cout << "You fire a magical esence towards your oppnnent and land the devistating blow\nThe croud goes wild" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else if (player->magicValue == 4)
			{
				std::cout << "You use the spell of spells and your opponents pants drop to the floor, he is killed with embrasement" << std::endl;
				enemy->hp -= 1;
				system("Pause");
			}
			else
			{
				std::cout << "You miss your spell and get turned into a sheep\nThe croud grows silent, then laughs at you" << std::endl;
				player->hp -= 1;
				system("Pause");
			}
		}

		loot();
	}

	if (enemy->hp == 0)
	{
		system("CLS");
		std::cout << "Congradulations you have defeated many foes and won the deed to the land" << std::endl;
		system("Pause");
		game = false;
	}
}

void GameState::loot()
{
	if (lastRoundHp > enemy->hp)
	{
		system("CLS");
		randomNum = rand() % 100 + 1;

		if (randomNum <= 30 && randomNum >= 1 && player->sword == false)
		{
			std::cout << "You found loot - The spoon of Destiny" << std::endl;
			player->sword = true;
		}
		else if (randomNum <= 60 && randomNum > 31 && player->crossbow == false)
		{
			std::cout << "You found loot - The Trebuchet of Torment" << std::endl;
			player->crossbow = true;
		}
		else if (randomNum <= 90 && randomNum >= 61 && player->wand == false)
		{
			std::cout << "You found loot - The Spell of Spells" << std::endl;
			player->wand = true;
		}
		else
		{
			std::cout << "You didnt find any loot" << std::endl;
		}

		system("Pause");
	}
}