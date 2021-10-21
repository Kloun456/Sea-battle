#include "Game.h"

using namespace std;

void Game::Start_game()
{
	battlefield_2.Put_ships_default(); // ��� �� ���������� ����������� �� ���������
	int choice, choice_ship = 1; 
	cout << "\n Select a ship layout option: \n1 - Your arrangement\n2 - Default arrangement\n";
	cin >> choice; // ����� ������ ����
	system("cls");
	switch (choice)
	{
	case 1:
		while (choice_ship)
		{
			system("cls");
			battlefield_1.Show(1);
			cout << "\nChoice ship 1,2,3,4:\n";
			cin >> choice_ship; // ����� ������� 1 �������� � �.�.
			choice_ship = battlefield_1.Choice_ship(choice_ship); // ������� ������ �������, choice_ship ����� = 0 ���� ��� ������� �����������
		}
		battlefield_1.Default_quantity_ships();
		break;
	case 2:
		battlefield_1.Put_ships_default(); // ����������� �� ��������� 
		break;
	}
	system("cls");
	cout << "\nGame start!\n";
	Battle(); // �������� ������� ��������� ���
}

void Game::Battle()
{
	bool player, AI;
	while (1)
	{
		system("cls");
		cout << "\nYour battlefield:\n";
		battlefield_1.Show(1); // ���������� ���� ������
		cout << "\n\nAI battlefield:\n";
		battlefield_2.Show(0); // ���������� ���� ��
		cout << "\nYour shot:\n";
		player = battlefield_2.Shot(1); // ������� ������
		AI = battlefield_1.Shot(0); // ������� ��
		if (player) // ���� ����� �����
		{
			if (battlefield_2.Check_quantity_ships()) // ��������� ��� �� ������� �������� �� ����
			{
				End_game(0); // ���� �������� ��� ����� �������
				return;
			}
		}
		else if (AI) // ���� �� �����
		{
			if (battlefield_1.Check_quantity_ships())  // ��������� ��� �� ������� �������� �� ����
			{
				End_game(1); // ���� �������� ��� �� �������
				return;
			}
		}
	}
}

void Game::End_game(int flag) // ������� ����� ����
{
	if (flag) // ���� ����� ���� ��� ������
		cout << "\nGame over!\n";
	else // ���� ����� ���� ��� ��
		cout << "\nYou win\n";
}