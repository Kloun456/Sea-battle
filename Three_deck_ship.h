#pragma once
#include "Ship.h"

class Three_deck_ship :
    public Ship
{
public:
    Three_deck_ship() : Ship(3) {};
    void Death() override { cout << "\nThree-deck ship is death.\n"; }
};

