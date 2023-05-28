#include "SnakeGame.h"

SnakeGame::SnakeGame()
{
	while (!snake.empty())
		snake.pop_back();
	snake.push_front({Wight / 2, Hight / 2});
	snake.push_back({Wight / 2 - 1, Hight / 2});
	snake.push_back({Wight / 2 - 2, Hight / 2});
}

void SnakeGame::printMap()
{
	char map[Hight + 1][Wight + 1];

	for (int i = 1; i <= Hight; i++)
	{
		for (int j = 1; j <= Wight; j++)
		{
			map[i][j] = ' ';
		}
	}
	// 绘制边框
	for (int i = 1; i <= Wight; i++)
	{
		map[1][i] = '#';
		map[Hight][i] = '#';
	}
	for (int i = 1; i <= Hight; i++)
	{
		map[i][1] = '#';
		map[i][Wight] = '#';
	}
	map[this->food_y][this->food_x] = '*';
	// 绘制贪吃蛇
	int cnt = 0;
	for (const auto &snakePart : snake)
	{
		if (cnt == 0)
		{
			map[snakePart.y][snakePart.x] = '@';
			cnt++;
			continue;
		}
		int x = snakePart.x;
		int y = snakePart.y;
		map[y][x] = '+';
	}

	// 打印地图
	std::stringstream ss;
	for (int i = 1; i <= Hight; i++)
	{
		for (int j = 1; j <= Wight; j++)
		{
			ss << map[i][j];
		}
		ss << '\n';
	}
	std::cout << ss.str();
}

void SnakeGame::create_food()
{
	this->food_x = rand() % Wight + 1;
	this->food_y = rand() % Hight + 1;
	while ((this->food_x == 1 || this->food_x == Wight) || (this->food_y == 1 || this->food_y == Wight))
	{
		this->food_x = rand() % Wight + 1;
		this->food_y = rand() % Hight + 1;
	}
	int flag = 1;
	while (flag)
	{
		flag = 0;
		for (auto it : snake)
		{
			if (it.x == this->food_x && it.y == this->food_y)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			this->food_x = rand() % Wight + 1;
			this->food_y = rand() % Hight + 1;
			while ((this->food_x == 1 || this->food_x == Wight) || (this->food_y == 1 || this->food_y == Wight))
			{
				this->food_x = rand() % Wight + 1;
				this->food_y = rand() % Hight + 1;
			}
		}
	}
}

void SnakeGame::game_loop()
{
	srand(time(NULL));
	Snake Head_snake;
	Snake End_snake;
	if (this->fist_op)
	{
		this->fist_op = false;
		create_food();
		dir = getch();
	}
	system("cls");
	this->printMap();
	while (true)
	{
		// cout << "debug" << endl;
		//	cout << "debug" << endl;
		Head_snake = snake.front();
		End_snake = snake.back();
		snake.pop_back();

		if (dir == 'w')
		{
			Head_snake.y--;
		}
		else if (dir == 's')
		{
			Head_snake.y++;
		}
		else if (dir == 'a')
		{
			Head_snake.x--;
		}
		else if (dir == 'd')
		{
			Head_snake.x++;
		}
		if (Head_snake.x == food_x && Head_snake.y == food_y)
		{
			this->score += 1;
			snake.push_back(End_snake);
			create_food();
		}
		if (!this->judgeCrash())
		{
			return;
		}
		if (_kbhit())
		{
			this->userInput();
		}
		snake.push_front(Head_snake);
		Sleep(80);
		this->SetPos(0, 0);
		printMap();
	}
}

void SnakeGame::userInput()
{
	char c = getch();
	if (c != 'w' && c != 's' && c != 'a' && c != 'd')
		return;
	if (dir == 'w' && c != 's')
	{
		dir = c;
	}
	else if (dir == 's' && c != 'w')
	{
		dir = c;
	}
	else if (dir == 'a' && c != 'd')
	{
		dir = c;
	}
	else if (dir == 'd' && c != 'a')
	{
		dir = c;
	}
}

bool SnakeGame::judgeCrash()
{
	Snake Head = snake.front();
	if (Head.x == 1 || Head.x == Wight || Head.y == 1 || Head.y == Hight)
	{
		cout << "Game Over" << endl;
		return false;
	}
	bool cnt = 0;
	for (auto it : snake)
	{
		if (cnt == 0)
		{
			cnt = 1;
			continue;
		}
		else
		{
			if (Head.x == it.x && Head.y == it.y)
			{
				cout << "Game Over" << endl;
				return false;
			}
		}
	}
	return true;
}

int SnakeGame::getScore()
{
	return this->score;
}

void SnakeGame::SetPos(short x, short y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position = {x, y};
	SetConsoleCursorPosition(hConsole, position);
}