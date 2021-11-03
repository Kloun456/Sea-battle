#include "Game.h"

using namespace std;

void Game::Start_game()
{
	battlefield_2.Put_ships_default(); // для ИИ используем расстановку по умолчанию
	int choice, choice_ship = 1; 
	cout << "Select a ship layout option: \n1 - Your arrangement\n2 - Default arrangement\n";
	cin >> choice; // выбор пункта меню
	system("cls");
	switch (choice)
	{
	case 1:
		while (choice_ship)
		{
			system("cls");
			battlefield_1.Show(1);
			cout << "\nChoice ship 1,2,3,4:\n";
			cin >> choice_ship; // выбор корабля 1 парусный и т.д.
			choice_ship = battlefield_1.Choice_ship(choice_ship); // функция выбора корабля, choice_ship будет = 0 если все корабли расставлены
		}
		battlefield_1.Default_quantity_ships();
		break;
	case 2:
		battlefield_1.Put_ships_default(); // расстановка по умолчанию 
		break;
	}
	system("cls");
	cout << "\nGame start!\n";
	Battle(); // вызываем функцию основного боя
}

void Game::Battle()
{
	bool player = false, AI = false;
	int numb;
	while (1)
	{
		system("cls");
		cout << "\nYour battlefield:\n";
		battlefield_1.Show(1); // показываем поле игрока
		cout << "\n\nAI battlefield:\n";
		battlefield_2.Show(0); // показываем поле ИИ
		cout << "\nYour shot: \n1 - Shot\n2 - Bomb shot (You have " << battlefield_1.q_bombs << " bombs)";
		cout << "\n3 - Toredo shot (You have " << battlefield_1.q_torpedo << " torpedoes)\n";
		cin >> numb;
		switch (numb)
		{
		case 1:
			player = battlefield_2.Shot(1); // обычный выстрел игрока
			break;
		case 2:
			player = battlefield_2.Shot_bomb(); // выстрел бомбой игрока
			if (player)
				battlefield_1.Minus_bomb(); // отнимаем у игрока бомбу
			break;
		case 3:
			player = battlefield_2.Shot_torpedo(); // выстрел торпедой
			if (player)
				battlefield_1.Minus_torpedo(); // отмниаем у игрока торпеду

			break;
		}

		AI = battlefield_1.Shot(0); // выстрел ИИ
		if (player) // если игрок попал
		{
			if (battlefield_2.Check_quantity_ships()) // проверяем все ли корабли остались на поле
			{
				End_game(0); // Если кораблей нет игрок победил
				return;
			}
		}
		else if (AI) // если ИИ попал
		{
			if (battlefield_1.Check_quantity_ships())  // проверяем все ли корабли остались на поле
			{
				End_game(1); // Если кораблей нет ИИ победил
				return;
			}
		}
	}
}

void Game::End_game(int flag) // функция конца игры
{
	if (flag) // если конец игры для игрока
		cout << "\nGame over!\n";
	else // если конец игры для ИИ
		cout << "\nYou win\n";
}
