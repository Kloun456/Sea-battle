#pragma once
#include "Ship.h"

class Four_deck_ship :
    public Ship
{
public:
    Four_deck_ship() : Ship(4) {};
    void Death() override { cout << "\nFour-deck ship is death.\n"; }
};

