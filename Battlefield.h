#pragma once
#include <cstring>
#include <iostream>
#include "Ship.h"
#include "Two_deck_ship.h"
#include "One_deck_ship.h"
#include "Three_deck_ship.h"
#include "Four_deck_ship.h"

class Battlefield
{
public:
	Battlefield()// конструктор без параметров 
	{
		memset(field, 0, sizeof(field)); // заполнение матрицы нулями 
	}
	void Put_ship(Ship *sheep); // функция постаноовки корабля на поле
	void Show(int flag); // функция показа поля
	bool Shot(int flag); // функция выстрела
	void Shot_ship(int numb_ship, int y, int x); // функция выстрела по кораблю
	int Choice_ship(int ); // функция выборки корабля
	bool Check_coordinate(int y, int x); // функция проверки занята ли координата
	bool Check_quantity_ships(); // функция проверки на то есть корабли на поле или нет
	void Put_ships_default(); // функция расстановки кораблей по умолчанию
	void Default_quantity_ships() { q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; } // функция устанавливает количество кораблей по умолчанию 
	friend class Game;
private:
	int field[10][10];
	int q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; // количество однопалубных кораблей q_ship1 = 4 и т.д.
	Two_deck_ship ship2[3]; // массив двупалубных кораблей
	One_deck_ship ship1[4]; // массив однопалубных кораблей
	Three_deck_ship ship3[2]; // массив трехпалубных кораблей
	Four_deck_ship ship4[1]; // массив четырехпалубных кораблей
};

