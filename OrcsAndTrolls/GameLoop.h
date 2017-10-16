#pragma once
#include<iostream>
#include "Character.h"
#include "Orc.h"
#include "Troll.h"

struct GameState
{
	// default constructor
	GameState();

	// main loop for the game
	void Update();

	//compairing the inputs from the player and ai
	void damageCalculation();

	void loot();

	//players inputs
	int loopInput;

	//this ends the game
	bool game;

	//this is used for health comparacents
	int lastRoundHp;

	//this is used for loot drop
	int randomNum;

	Character *player;
	Character *enemy;
}; 