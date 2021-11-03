#pragma once
#include <cstring>
#include <iostream>
#include "Ship.h"

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
	bool Shot_bomb(); // функция выстрела бомбой
	bool Shot_torpedo(); // функция выстрела торпедой
	void Shot_ship(int numb_ship, int y, int x); // функция выстрела по кораблю
	void Minus_bomb() { q_bombs--; } // уменьшает количество бомб на 1
	void Minus_torpedo() { q_torpedo--; } // уменьшает количество торпед на 1
	int Choice_ship(int ); // функция выборки корабля
	bool Check_coordinate(int y, int x); // функция проверки занята ли координата
	bool Check_quantity_ships(); // функция проверки на то есть корабли на поле или нет
	void Put_ships_default(); // функция расстановки кораблей по умолчанию
	void Default_quantity_ships() { q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; } // функция устанавливает количество кораблей по умолчанию 
	friend class Game;
private:
	int field[10][10];
	int q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; // количество однопалубных кораблей q_ship1 = 4 и т.д.
	int q_bombs = 2, q_torpedo = 3;
	Ship ship2[3] { Ship(2),Ship(2), Ship(2) }; // массив двупалубных кораблей
	Ship ship1[4] { Ship(1),Ship(1), Ship(1), Ship(1) }; // массив однопалубных кораблей
	Ship ship3[2] { Ship(3),Ship(3) }; // массив трехпалубных кораблей
	Ship ship4[1] { Ship(4) }; // массив четырехпалубных кораблей
};
