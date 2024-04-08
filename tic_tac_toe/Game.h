#pragma once
#include <iostream>
#include <Windows.h>
#include <vector>

class Game
{
	int num{ 0 };
	int step{ 0 };
	bool run = true;
	std::vector<std::string> msg{"\x1b[32m������� �����!\x1b[0m\n","\x1b[32m������� ���������!\x1b[0m\n"};
	char cross = 'X';
	char zero = 'O';
	std::vector<char> Endaged{'1','2','3','4','5','6','7','8','9'};

	// 1 = 16, 2 = 20, 3 = 24, 4 = 44, 5 = 48, 6 = 52, 7 = 72, 8 = 76, 9 = 80
	std::string screen = "-------------\n| 1 | 2 | 3 |\n-------------\n| 4 | 5 | 6 |\n-------------\n| 7 | 8 | 9 |\n-------------\n";

	/// <summary>
	/// ����� ��������� ������ ����.
	/// </summary>
	/// <param name="value"></param>
	/// <param name="ch"></param>
	/// <returns></returns>
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

	/// <summary>
	/// ����� ��������� �����.
	/// </summary>
	/// <returns></returns>
	bool Is_Draw()
	{
		for (int i = 0; i < Endaged.size(); i++)
		{
			if (Is_Endaged(i, (char)(i + 49)))
				return false;
		}
		std::cout << "�����\n��� ����� ������� ����� ������.\n";
		system("pause");
		return true;
	}

	/// <summary>
	/// ����� ��������� ���������� ��������.
	/// </summary>
	/// <returns></returns>
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

	/// <summary>
	/// ����� ���� ����������.
	/// </summary>
	/// <param name="ch"></param>
	void ComLogic(char ch)
	{
		bool cycle = true;
		std::cout << "��� ����������\n";
		std::cout << "��������� ������ " << ch << "\n";
		do
		{
			num = rand() % 9;
			if (Is_Endaged(num, zero))
				cycle = false;
		} while (cycle);
		Sleep(2000);
	}

	/// <summary>
	/// ����� ���� ������.
	/// </summary>
	/// <param name="ch"></param>
	void Player(char ch)
	{
		bool cycle = true;
		std::cout << "��� ������\n";
		std::cout << "�� ������� " << ch << "\n";
		while (cycle)
		{
			std::cout << "������� ����� ��������� ������: "; std::cin >> num;
			if (num > 0 && num < 10)
			{
				if (!Is_Endaged(num - 1, cross))
				{
					std::cout << "\x1b[31m����� ��� ��� ���!\x1b[0m\n";
					system("pause");
				}
				else
					cycle = false;
			}
			else
				std::cout << "\x1b[31m����� ������ ���� �� 1 �� 9!\x1b[0m\n";
		}
	}

	/// <summary>
	/// ����� ����������� ����.
	/// </summary>
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

	/// <summary>
	/// ����� ��������� ������.
	/// </summary>
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
		std::cout << "\x1b[32m���� �������� - ������\x1b[0m\n";
		std::cout << screen;
		std::cout << "\x1b[33m�� ������� ���������\x1b[0m\n";
	}

public:
	/// <summary>
	/// ����� �������� �����.
	/// </summary>
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