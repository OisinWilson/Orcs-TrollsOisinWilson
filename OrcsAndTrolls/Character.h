#pragma once
#include<time.h>
#include<stdlib.h>

class Character
{
public:
	// constructor for character
	Character();
	
	// this will be how the player choses the character
	virtual void characterChoice() = 0;

	// input for character
	int characterInput;

	//combat update loop
	virtual void update() = 0;

	//combat options
	virtual void melee() = 0;

	virtual void ranged() = 0;

	virtual void magic() = 0;

	virtual void shield() = 0;


	// to decide if its the player or not
	bool player;

	// hit points 
	int hp;

	// number of shields left
	int shieldsRemaining;
	
	// combat values
	int meleeValue;
	int rangedValue;
	int magicValue;
	bool shieldValue;

	// ledgendy wepons
	bool sword;
	bool crossbow;
	bool wand;

private:
};