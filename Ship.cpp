#include "Ship.h"

Ship::Ship(int hp)// конструктор с параметром
{
	this->hp = deck = hp; // присваиваем hp корабля hp которое мы передаем в параметре 
	coordinates.resize(hp); // меняем количество строк у двумерного массива на количество равное hp
	for (int i = 0; i < hp; i++)
		coordinates[i].resize(2); // меняем количество столбцов у двумерного массива на количество равное 2
	for (int i = 0; i < hp; i++)
		for (int j = 0; j < 2; j++)
			coordinates[i][j] = -1; // присваиваем всем координатам корабля -1
}

void Ship::Set_coordinates(int x, int y, int numb_point)
{
	coordinates[numb_point][0] = x; // назначаем координату х
	coordinates[numb_point][1] = y; // назначаем координату у
}

bool Ship::Hit() // функция удара по кораблю
{
	if (hp == 1) // если у корабля осталась 1 жизнь
	{
		hp -= 1; 
		Death(); // вызываем функцию смерти корабля
		return true;
	}
	hp -= 1; // отнимаем одно hp
	return false;
}

void Ship::Show() // функция вывода координат корабля
{
	cout << "\nCoordinates:\n";
	for (int i = 0; i < hp; i++)
	{
		cout << "\nS - " << coordinates[i][1] << "\tc - " << coordinates[i][0] << endl;
	}
}

void Ship::Death()
{
	cout << "\n" << deck << " - deck ship is death.\n";
}
