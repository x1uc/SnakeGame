#include <iostream>
#include <conio.h>
#include <windows.h>
#include <deque>
#include <ctime>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <algorithm>
using namespace std;
const int Wight = 120;
const int Hight = 40;
struct Snake
{
	int x, y;
};

class SnakeGame
{
public:
	SnakeGame();
	void printMap();
	void game_loop();
	void create_food();
	void userInput();
	bool judgeCrash();
	int getScore();
	void SetPos(short x, short y);

private:
	deque<Snake> snake;
	HANDLE hOut;
	COORD pos;
	double spped = 200;
	int food_x, food_y;
	int score = 0;
	bool fist_op = true;
	char dir;
};
