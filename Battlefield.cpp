#include "Battlefield.h"
#include <queue>

using namespace std;

void Battlefield::Show(int flag) // Отображение поля битвы flag = 1 для игрока flag = 0 для ИИ
{
	cout << "\tA\tB\tC\tD\tE\tF\tG\tH\tI\tJ\n";
	for (int i = 0; i < 10; i++)
	{
		cout << endl << i + 1 << "\t";
		for (int j = 0; j < 10; j++)
		{
			if (flag) // для игрока
			{
				if (!field[i][j]) // если поле пустое отображаем его как *
					cout << "*\t";
				else if (field[i][j] == -1) // если в ячейку поля стреляли отображаем его как #
					cout << "#\t";
				else if (field[i][j] == -2) // если в ячейки поля стреляли в корабль отображаем его как .
					cout << ".\t";
				else // в остальных случаях выводим корабли
					cout << field[i][j] << "\t";
			}
			else // для ИИ
			{
				if (field[i][j] == -1) // если в ячейку поля стреляли отображаем его как #
					cout << "#\t";
				else if (field[i][j] == -2) // если в ячейки поля стреляли в корабль отображаем его как .
					cout << ".\t";
				else // в остальных случаях выводим *
					cout << "*\t";
			}
		}
	}
	
}

bool Battlefield::Check_coordinate(int y, int x) // проверка на то, что в точку можно поставить корабль
{
	if (y == 0) // если это первая строка
	{
		if (x == 0) // если это первый столбец
		{
			if (!field[y][x] && !field[y][x + 1] && !field[y + 1][x] && !field[y + 1][x + 1]) // проверка на свободность клетки
				return true;
		}
		else if (x == 9) // если это последний столбец
		{
			if (!field[y][x] && !field[y][x - 1] && !field[y - 1][x] && !field[y + 1][x - 1])
				return true;
		}
		else
		{
			if (!field[y][x] && !field[y][x - 1] && !field[y][x + 1] && !field[y + 1][x - 1] && !field[y + 1][x] && !field[y + 1][x + 1])
				return true;
		}
	}
	else if (y == 9)
	{
		if (x == 0)
		{
			if (!field[y][x] && !field[y][x + 1] && !field[y - 1][x + 1] && !field[y - 1][x])
				return true;
		}
		else if (x == 9)
		{
			if (!field[y][x] && !field[y][x - 1] && !field[y - 1][x] && !field[y - 1][x - 1])
				return true;
		}
		else
		{
			if (!field[y][x] && !field[y - 1][x - 1] && !field[y - 1][x] && !field[y - 1][x + 1] && !field[y][x - 1] && !field[y][x + 1])
				return true;
		}
	}
	else if (x == 0)
	{
		if (!field[y][x] && !field[y - 1][x] && !field[y - 1][x + 1] && !field[y][x + 1] && !field[y + 1][x] && !field[y + 1][x + 1])
			return true;
	}
	else if (x == 9)
	{
		if (!field[y][x] && !field[y - 1][x - 1] && !field[y - 1][x] && !field[y][x - 1]&& !field[y + 1][x - 1] && !field[y + 1][x])
			return true;
	}
	else
	{
		if (!field[y][x] && !field[y - 1][x - 1] && !field[y - 1][x] && !field[y - 1][x + 1] && !field[y][x - 1] && !field[y][x + 1]
			&& !field[y + 1][x - 1] && !field[y + 1][x] && !field[y + 1][x + 1])
			return true;
	}
	return false;
		
}

void Battlefield::Put_ship(Ship* ship) 
{
	string coordinate;
	queue<int> coordinate_ship; // выделяем динамически память под координаты корабля
	char temp;
	int x , y;
	cout << "\nEnter the coordinates in the following format: A-2\n";
	
	for (int i = 0; i < ship->Get_hp(); i++)
	{
		cin >> coordinate; // ввод координат
		temp = coordinate[0]; // Запоминаем букву из координат
		y = stoi(coordinate.substr(2)) - 1; // получаем подстроку с позиции 2 длиной до конца строки - это цифра из координат
		x = int(temp) - 65; // преобразуем char в int и вычитаем 65 (математика ASCII)
		if (Check_coordinate(y, x)) // проверяем не занята ля координата
		{
			coordinate_ship.push(y);
			coordinate_ship.push(x);
			ship->Set_coordinates(x, y, i); // назначаем кораблю координаты
		}
		else // если координата занята то вводим данные заново
		{
			i = -1; 
			cout << "\nInvalid coordinates re-enter the coordinates:\n";
		}
	}
	for (int i = 0; i < ship->Get_hp(); i++)
	{
		y = coordinate_ship.front();
		coordinate_ship.pop();
		x = coordinate_ship.front();
		coordinate_ship.pop();
		field[y][x] = ship->Get_hp(); // присваиваем полю по координатам х и у номер корабля 1, 2 и т.д.
	}
}

int Battlefield::Choice_ship(int number)
{
	switch (number) // выбор корабля
	{
	case 1: 
		if (q_ship1) // если количество 1 палубных не 0
		{
			for (int i = 0; i < q_ship1; i++)
			{
				cout << "\nEnter coordinate " << i + 1 << " sheep\n";
				Put_ship(&ship1[i]); // функция постановки корабля на поле
				
			}
			q_ship1 = 0;
		}
		else
			cout << "\nAll One-deck ships are placed\n"; // все однопалубные корабли расставлены
		break;
	case 2:
		if (q_ship2)
		{
			for (int i = 0; i < q_ship2; i++)
			{
				cout << "\nEnter coordinate " << i + 1 << " sheep\n";
				Put_ship(&ship2[i]);
				
			}
			q_ship2 = 0;
		}
		else
			cout << "\nAll two-deck ships are placed\n";
		break;
	case 3:
		if (q_ship3)
		{
			for (int i = 0; i < q_ship3; i++)
			{
				cout << "\nEnter coordinate " << i + 1 << " sheep\n";
				Put_ship(&ship3[i]);
				
			}
			q_ship3 = 0;
		}
		else
			cout << "\nAll three-deck ships are placed\n";
		break;
	case 4:
		if (q_ship4)
		{
			q_ship4 -= 1;
			Put_ship(&ship4[0]);
			
		}
		else
			cout << "\nAll four-deck ships are placed\n";
		break;
	}
	if (!q_ship1 && !q_ship2 && !q_ship3 && !q_ship4) // если количество всех кораблей = 0
	{
		cout << "\nAll ship are selected!\n"; // все корабли выбраны
		return 0; // возврат из функции
	}
	return 1;
}

void Battlefield::Put_ships_default() // расстановка кораблей по умолчанию
{
	ship1[0].Set_coordinates(0, 0, 0); // назначаем первому однопалубному кораблю координаты 0-0
	field[0][0] = 1; // на поле с координатами 0-0 ставим 1
	ship1[1].Set_coordinates(0, 2, 0); // назначаем второму однопалубному кораблю координаты 2-0
	field[2][0] = 1; // на поле с координатами 2-0 ставим 1
	ship1[2].Set_coordinates(0, 4, 0);
	field[4][0] = 1;
	ship1[3].Set_coordinates(0, 6, 0);
	field[6][0] = 1;
	
	ship2[0].Set_coordinates(2, 0, 0); // назначаем первому двухпалубному кораблю координаты 0-2
	field[0][2] = 2; // на поле с координатами 0-2 ставим 2
	ship2[0].Set_coordinates(2, 1, 1);
	field[1][2] = 2;
	
	// второй двупалубный
	ship2[1].Set_coordinates(2, 3, 0); 
	field[3][2] = 2;
	ship2[1].Set_coordinates(2, 4, 1);
	field[4][2] = 2;
	
	// третий двупалубный
	ship2[2].Set_coordinates(8, 0, 0);
	field[0][8] = 2;
	ship2[2].Set_coordinates(9, 0, 1);
	field[0][9] = 2;

	// первый трехпалубный
	ship3[0].Set_coordinates(5, 5, 0);
	field[5][5] = 3;
	ship3[0].Set_coordinates(6, 5, 1);
	field[5][6] = 3;
	ship3[0].Set_coordinates(7, 5, 2);
	field[5][7] = 3;

	// второй трехпалубный
	ship3[1].Set_coordinates(4, 3, 0);
	field[3][4] = 3;
	ship3[1].Set_coordinates(5, 3, 1);
	field[3][5] = 3;
	ship3[1].Set_coordinates(6, 3, 2);
	field[3][6] = 3;

	// первый четырехпалубный
	ship4[0].Set_coordinates(9, 9, 0);
	field[9][9] = 4;
	ship4[0].Set_coordinates(9, 8, 1);
	field[8][9] = 4;
	ship4[0].Set_coordinates(9, 7, 2);
	field[7][9] = 4;
	ship4[0].Set_coordinates(9, 6, 3);
	field[6][9] = 4;	
}

bool Battlefield::Shot(int flag) // flag = 1 стреляет игрок flag = 0 стреляет ИИ
{
	string coordinate;
	char temp;
	int x, y;
	if (flag) // стреляет игрок
	{
		cout << "\nEnter the coordinates for shot in the following format: A-2\n";
		cin >> coordinate; // ввод координат
		temp = coordinate[0]; // Запоминаем букву из координат
		y = stoi(coordinate.substr(2)) - 1; // получаем подстроку с позиции 2 длиной до конца строки - это цифра из координат
		x = int(temp) - 65; // преобразуем char в int и вычитаем 65 (математика ASCII)
	}
	else // стреляет ИИ
	{
		y = rand() % 10; 
		x = rand() % 10;
	}
	if (field[y][x] > 0) // если поле содержит корабль
	{
		Shot_ship(field[y][x], y, x); // вызываем функцию удара по кораблю
		field[y][x] = -2; // присваиваем полю где был корабль -2, чтобы обозначить что там больше его нет
		return true;
	}
	else if (!field[y][x]) // если мы выстрелили в пустое поле
		field[y][x] = -1;
	else // если мы стреляли в одно и тоже поле
	{
		cout << "\nInvalid coordinates for shot re-enter the coordinates:\n";
		Shot(flag); 
	}
	return false;
}

void Battlefield::Shot_ship(int numb_ship, int y, int x) // функция удара по кораблю
{
	switch (numb_ship) // номер корабля
	{
	case 1: // однопалубный
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 1; j++)
			{
				if (x == ship1[i].Get_x(j) && y == ship1[i].Get_y(j)) // если х и у из параметров равны координатам корабля
				{
					if (ship1[i].Hit()) // то корабль получает удар
						q_ship1 -= 1; // если удар уничтожил корабль, то отнимаем колчиство кораблей -1
					ship1[i].Set_coordinates(-1, -1, j); // устанавливаем координаты равные -1 -1
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				if (x == ship2[i].Get_x(j) && y == ship2[i].Get_y(j))
				{
					if (ship2[i].Hit())
						q_ship2 -= 1;
					ship2[i].Set_coordinates(-1, -1, j);
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (x == ship3[i].Get_x(j) && y == ship3[i].Get_y(j))
				{
					if (ship3[i].Hit())
						q_ship3 -= 1;
					ship3[i].Set_coordinates(-1, -1, j);
				}
			}
		}
		break;
	case 4:
		for (int j = 0; j < 4; j++)
		{
			if (x == ship4[0].Get_x(j) && y == ship4[0].Get_y(j))
			{
				if (ship4[0].Hit())
					q_ship4 -= 1;
				ship4[0].Set_coordinates(-1, -1, j);
			}
		}
		break;
	}
}

bool Battlefield::Check_quantity_ships()
{
	if (!q_ship1 && !q_ship2 && !q_ship3 && !q_ship4) // Проверяем на то, что количество всех кораблей равно 0
		return true;
	else
		return false;
}