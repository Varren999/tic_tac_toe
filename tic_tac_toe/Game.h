#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

class Game
{
	int num{ 0 }, step{ 0 };
	bool run = true;
	std::string msg[2] = { "\x1b[32mИгрок победил!\x1b[0m\n","\x1b[32mПобедил компьютер!\x1b[0m\n" };
	char cross = 'X', zero = 'O';
	std::vector<char> Endaged{'1','2','3','4','5','6','7','8','9'};

	std::string screen = "-------------\n| 1 | 2 | 3 |\n-------------\n| 4 | 5 | 6 |\n-------------\n| 7 | 8 | 9 |\n-------------\n";
	// 1 = 16, 2 = 20, 3 = 24, 4 = 44, 5 = 48, 6 = 52, 7 = 72, 8 = 76, 9 = 80

	// Проверяем занято поле.
	bool Is_Endaged(int value, char ch)
	{
		if (Endaged[value] != cross && Endaged[value] != zero)
		{
			Endaged[value] = ch;
			return true;
		}
		else
			return false;
	}

	// Ничья
	bool Is_Draw()
	{
		for (int i = 0; i < Endaged.size(); i++)
		{
			if (Is_Endaged(i, (char)(i + 49)))
				return false;
		}
		std::cout << "Ничья\nДля выход нажмите любую кнопку\n";
		system("pause");
		return true;
	}

	// Метод проверяет выигрышные ситуации.
	bool Is_Winner()
	{
		// 1 == 2 == 3
		if (Endaged[0] == Endaged[1] && Endaged[1] == Endaged[2])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 4 == 5 == 6
		if (Endaged[3] == Endaged[4] && Endaged[4] == Endaged[5])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 7 == 8 == 9
		if (Endaged[6] == Endaged[7] && Endaged[7] == Endaged[8])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 1 == 4 == 7
		if (Endaged[0] == Endaged[3] && Endaged[3] == Endaged[6])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 2 == 5 == 8
		if (Endaged[1] == Endaged[4] && Endaged[4] == Endaged[7])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 3 == 6 == 9
		if (Endaged[2] == Endaged[5] && Endaged[5] == Endaged[8])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 1 == 5 == 9
		if (Endaged[0] == Endaged[4] && Endaged[4] == Endaged[8])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}

		// 3 == 5 == 7
		if (Endaged[2] == Endaged[4] && Endaged[4] == Endaged[6])
		{
			std::cout << msg[step];
			system("pause");
			return true;
		}
		return false;
	}

	// 
	void ComLogic(char ch)
	{
		bool cycle = true;
		std::cout << "Ход компьютера\n";
		std::cout << "Компьютер играет " << ch << "\n";
		do
		{
			num = rand() % 8;
			if (Is_Endaged(num, zero))
				cycle = false;
		} while (cycle);
		Sleep(2000);
	}

	//
	void Player(char ch)
	{
		bool cycle = true;
		std::cout << "Ход игрока\n";
		std::cout << "Вы играете " << ch << "\n";
		while (cycle)
		{
			std::cout << "Введите номер свободной ячейки: "; std::cin >> num;
			if (!Is_Endaged(num - 1, cross))
			{
				std::cout << "\x1b[31mТакой ход уже был!\x1b[0m\n";
				system("pause");
			}
			else
				cycle = false;
		}
	}

	// 
	void Step()
	{
		if (step == 0)
		{
			ComLogic(zero);
			step = 1;
		}
		else
		{
			Player(cross);
			step = 0;
		}
	}

	// Отрисовка экрана.
	void Screen()
	{
		for (int i{ 0 }, m{0}, j{ 16 }; i < 9; i++)
		{
			screen[j] = Endaged[i];
			if (m >= 0 && m <= 1)
			{
				j += 4;
				m++;
			}
			else
			{
				j += 20;
				m = 0;
			}
		}
		system("cls");
		std::cout << "\x1b[32mИгра крестики - нолики\x1b[0m\n";
		std::cout << screen;
		std::cout << "\x1b[33mВы играете крестиком\x1b[0m\n";
	}

public:
	// Игровой цикл.
	void Play()
	{
		step = rand() % 2;
		do
		{
			Screen();
			Step();
			Screen();
		} while (!Is_Winner() && !Is_Draw());
	}
};