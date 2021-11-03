#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

class Ship
{
public:
	Ship(int hp); 
	void Death();
	bool Hit();
	void Set_coordinates(int x, int y, int numb_point);
	void Show();
	int Get_hp() { return hp; }
	int Get_x(int numb_point) { return coordinates[numb_point][0]; } // получаем координату х
	int Get_y(int numb_point) { return coordinates[numb_point][1]; } // получаем координату у
private:
	int hp, deck;
	vector <vector<int>> coordinates; // вектор координат
};
