#pragma once
#include "Ship.h"

class Two_deck_ship :
    public Ship
{
public:
    Two_deck_ship() : Ship(2) {};
    void Death() override { cout << "\nTwo-deck ship is death.\n"; }

};

