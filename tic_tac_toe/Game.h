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
	bool Is_Endaged(int num, char sim)
	{
		switch (num)
		{
		case 1:
		{
			if (Endaged[0] == '1')
			{
				Endaged[0] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 2:
		{
			if (Endaged[1] == '2')
			{
				Endaged[1] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 3:
		{
			if (Endaged[2] == '3')
			{
				Endaged[2] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 4:
		{
			if (Endaged[3] == '4')
			{
				Endaged[3] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 5:
		{
			if (Endaged[4] == '5')
			{
				Endaged[4] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 6:
		{
			if (Endaged[5] == '6')
			{
				Endaged[5] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 7:
		{
			if (Endaged[6] == '7')
			{
				Endaged[6] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 8:
		{
			if (Endaged[7] == '8')
			{
				Endaged[7] = sim;
				return true;
			}
			else
				return false;
		}break;

		case 9:
		{
			if (Endaged[8] == '9')
			{
				Endaged[8] = sim;
				return true;
			}
			else
				return false;
		}break;

		default:
		{
			std::cout << "Введены некорректные данные!\n";
			system("pause");
			return false;
		}
		}
	}

	// Ничья
	bool Is_Draw()
	{
		for (int i = 1; i <= Endaged.size(); i++)
		{
			if (Is_Endaged(i, (char)(i + 48)))
				return true;
		}
		std::cout << "Ничья\nДля выход нажмите любую кнопку\n";
		system("pause");
		return false;
	}

	// Метод проверяет выигрышные ситуации.
	bool Is_Winner()
	{
		// cross == 1 == 2 == 3
		if (cross == Endaged[0] && Endaged[0] == Endaged[1] && Endaged[1] == Endaged[2])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 4 == 5 == 6
		if (cross == Endaged[3] && Endaged[3] == Endaged[4] && Endaged[4] == Endaged[5])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 7 == 8 == 9
		if (cross == Endaged[6] && Endaged[6] == Endaged[7] && Endaged[7] == Endaged[8])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 1 == 5 == 9
		if (cross == Endaged[0] && Endaged[0] == Endaged[4] && Endaged[4] == Endaged[8])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 3 == 5 == 7
		if (cross == Endaged[2] && Endaged[2] == Endaged[4] && Endaged[4] == Endaged[6])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 1 == 4 == 7
		if (cross == Endaged[0] && Endaged[0] == Endaged[3] && Endaged[3] == Endaged[6])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 2 == 5 == 8
		if (cross == Endaged[1] && Endaged[1] == Endaged[4] && Endaged[4] == Endaged[7])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// cross == 3 == 6 == 9
		if (cross == Endaged[2] && Endaged[2] == Endaged[5] && Endaged[5] == Endaged[8])
		{
			std::cout << msg[0];
			system("pause");
			return false;
		}

		// zero == 1 == 2 == 3
		if (zero == Endaged[0] && Endaged[0] == Endaged[1] && Endaged[1] == Endaged[2])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 4 == 5 == 6
		if (zero == Endaged[3] && Endaged[3] == Endaged[4] && Endaged[4] == Endaged[5])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 7 == 8 == 9
		if (zero == Endaged[6] && Endaged[6] == Endaged[7] && Endaged[7] == Endaged[8])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 1 == 5 == 9
		if (zero == Endaged[0] && Endaged[0] == Endaged[4] && Endaged[4] == Endaged[8])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 3 == 5 == 7
		if (zero == Endaged[2] && Endaged[2] == Endaged[4] && Endaged[4] == Endaged[6])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 1 == 4 == 7
		if (zero == Endaged[0] && Endaged[0] == Endaged[3] && Endaged[3] == Endaged[6])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 2 == 5 == 8
		if (zero == Endaged[1] && Endaged[1] == Endaged[4] && Endaged[4] == Endaged[7])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		// zero == 3 == 6 == 9
		if (zero == Endaged[2] && Endaged[2] == Endaged[5] && Endaged[5] == Endaged[8])
		{
			std::cout << msg[1];
			system("pause");
			return false;
		}

		return true;
	}

	// 
	void ComLogic(char simbol)
	{
		bool cycle = true;
		std::cout << "Ход компьютера\n";
		std::cout << "Компьютер играет " << simbol << "\n";
		do
		{
			num = rand() % 8 + 1;
			if (Is_Endaged(num, zero))
				cycle = false;
		} while (cycle);
		Sleep(2000);
	}

	//
	void Player(char simbol)
	{
		bool cycle = true;
		std::cout << "Ход игрока\n";
		std::cout << "Вы играете " << simbol << "\n";
		while (cycle)
		{
			std::cout << "Введите номер свободной ячейки: "; std::cin >> num;
			if (!Is_Endaged(num, cross))
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
			Player(cross);
			step++;
		}
		else
		{
			ComLogic(zero);
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
		} while (Is_Winner() && Is_Draw());
	}
};