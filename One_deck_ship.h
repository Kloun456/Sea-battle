#pragma once
#include "Ship.h"

class One_deck_ship :
    public Ship
{
public:
    One_deck_ship() :Ship(1) {};
    void Death() override { cout << "\nOne-deck ship is death.\n"; }

};

