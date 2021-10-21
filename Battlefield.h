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
	Battlefield()// ����������� ��� ���������� 
	{
		memset(field, 0, sizeof(field)); // ���������� ������� ������ 
	}
	void Put_ship(Ship *sheep); // ������� ����������� ������� �� ����
	void Show(int flag); // ������� ������ ����
	bool Shot(int flag); // ������� ��������
	void Shot_ship(int numb_ship, int y, int x); // ������� �������� �� �������
	int Choice_ship(int ); // ������� ������� �������
	bool Check_coordinate(int y, int x); // ������� �������� ������ �� ����������
	bool Check_quantity_ships(); // ������� �������� �� �� ���� ������� �� ���� ��� ���
	void Put_ships_default(); // ������� ����������� �������� �� ���������
	void Default_quantity_ships() { q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; } // ������� ������������� ���������� �������� �� ��������� 
	friend class Game;
private:
	int field[10][10];
	int q_ship2 = 3, q_ship1 = 4, q_ship3 = 2, q_ship4 = 1; // ���������� ������������ �������� q_ship1 = 4 � �.�.
	Two_deck_ship ship2[3]; // ������ ����������� ��������
	One_deck_ship ship1[4]; // ������ ������������ ��������
	Three_deck_ship ship3[2]; // ������ ������������ ��������
	Four_deck_ship ship4[1]; // ������ ��������������� ��������
};

