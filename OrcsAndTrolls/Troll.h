#pragma once

#pragma once
#include "Character.h"
#include <iostream>

class Troll : public Character
{
public:
	//default constructor
	Troll();

	// override inherited function
	virtual void characterChoice() override;

	virtual void update() override;

	virtual void melee() override;

	virtual void ranged() override;

	virtual void magic() override;

	virtual void shield() override;

private:

};