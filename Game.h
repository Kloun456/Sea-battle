#pragma once
#include "Battlefield.h"

class Game
{
public:
	
	void Start_game();
	void Battle();
	void End_game(int flag);
private:
	Battlefield battlefield_1, battlefield_2; 
};

