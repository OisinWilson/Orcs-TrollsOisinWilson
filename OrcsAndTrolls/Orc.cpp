#include "Orc.h"

Orc::Orc()
{
	//initialisation
	player = false;
	hp = 2;
	shieldsRemaining = 0;
	characterInput = 0;

	meleeValue =0;
	rangedValue =0;
	magicValue =0;
	shieldValue =false;

	sword = false;
	crossbow = false;
	wand = false;

	srand(time(NULL));
}

void Orc::characterChoice()
{
	player = true;
	hp = 6;
	shieldsRemaining = 4;
}

void Orc::update()
{
	if (player == true)
	{
		system("CLS");
		characterInput = 0;
		meleeValue = 0;
		rangedValue = 0;
		magicValue = 0;
		while (characterInput == 0)
		{
			std::cout << "A challenger approaches what do you do:\n1) Melee\n2) Ranged\n3) magic\n4) shield (" << shieldsRemaining << " left)" << std::endl;
			std::cin >> characterInput;
			std::cout << "\n";

			if (characterInput == 4 && shieldsRemaining > 0)
			{
				shield();
			}
			else
			{
				switch (characterInput)
				{
				case 1:
					melee();
					break;
				case 2:
					ranged();
					break;
				case 3:
					magic();
					break;

				default:
					std::cout << "Unable to excacute command" << std::endl;
					characterInput = 0;
					break;
				}
			}
		}
	}
	else
	{
		//ai commands
		system("CLS");
		std::cout << "The Orc flexes to intemedate you, then goes for an attack:\n" << std::endl;

		meleeValue = rand() % 3 + 1;
		rangedValue = rand() % 3 + 1;
		magicValue = rand() % 3 + 1;
	}
}

void Orc::melee()
{
	system("CLS");
	meleeValue = 0;
	while (meleeValue == 0)
	{
		std::cout << "Your melee options are:\n1) Rapier\n2) Katana\n3) Claymore" << std::endl;
		if (sword == true)
		{
			std::cout << "4) The spoon of Destiny" << std::endl;
		}
		std::cin >> meleeValue;

		if (meleeValue == 4 && sword == true)
		{ 
		}
		else 
		{
			switch (meleeValue)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;

			default:
				meleeValue = 0;
				break;
			}
		}
	}
}

void Orc::ranged()
{
	system("CLS");
	rangedValue = 0;
	while (rangedValue == 0)
	{
		std::cout << "Your ranged options are:\n1) Sling\n2) Longbow\n3) Crossbow" << std::endl;
		if (crossbow == true)
		{
			std::cout << "4) The Trebuchet of Torment" << std::endl;
		}
		std::cin >> rangedValue;

		if (rangedValue == 4 && crossbow == true)
		{
		}
		else
		{
			switch (rangedValue)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;

			default:
				rangedValue = 0;
				break;
			}
		}
	}
}

void Orc::magic()
{
	system("CLS");
	magicValue = 0;
	while (magicValue == 0)
	{
		std::cout << "Your magic options are:\n1) Fire\n2) Ice\n3) Wind" << std::endl;
		if (wand == true)
		{
			std::cout << "4) The Spell of Spells" << std::endl;
		}
		std::cin >> magicValue;

		if (magicValue == 4 && wand == true)
		{
		}
		else
		{
			switch (magicValue)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			default:
				magicValue = 0;
				break;
			}
		}
	}
}

void Orc::shield()
{
	system("CLS");
	shieldValue = true;
	shieldsRemaining -= 1;
}