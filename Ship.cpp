#include "Ship.h"

Ship::Ship(int hp)// ����������� � ����������
{
	this->hp = hp; // ����������� hp ������� hp ������� �� �������� � ���������
	coordinates.resize(hp); // ������ ���������� ����� � ���������� ������� �� ���������� ������ hp
	for (int i = 0; i < hp; i++)
		coordinates[i].resize(2); // ������ ���������� �������� � ���������� ������� �� ���������� ������ 2
	for (int i = 0; i < hp; i++)
		for (int j = 0; j < 2; j++)
			coordinates[i][j] = -1; // ����������� ���� ����������� ������� -1
}

void Ship::Set_coordinates(int x, int y, int numb_point)
{
	coordinates[numb_point][0] = x; // ��������� ���������� �
	coordinates[numb_point][1] = y; // ��������� ���������� �
}

bool Ship::Hit() // ������� ����� �� �������
{
	if (hp == 1) // ���� � ������� �������� 1 �����
	{
		hp -= 1; 
		Death(); // �������� ������� ������ �������
		return true;
	}
	hp -= 1; // �������� ���� hp
	return false;
}

void Ship::Show() // ������� ������ ��������� �������
{
	cout << "\nCoordinates:\n";
	for (int i = 0; i < hp; i++)
	{
		cout << "\nS - " << coordinates[i][1] << "\tc - " << coordinates[i][0] << endl;
	}
}