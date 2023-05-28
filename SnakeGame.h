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
const int Wight = 120;  //地图宽度
const int Hight = 40;  // 地图长度
struct Snake //代表贪吃蛇一个块的坐标
{
	int x, y;
};

class SnakeGame
{
public:
	SnakeGame();
	void printMap();     //打印函数 包括地图 贪吃蛇本身
	void game_loop();    // 游戏实现的function
	void create_food();  // 随机生成一个地图内有效食物坐标
	void userInput();    // 获取用户输入
	bool judgeCrash();   // 判断该次操作结束后，蛇头会不会与身体相撞，或者碰到边界
	int getScore();      // 每吃一个食物加一分，最后输出总得分
	void SetPos(short x, short y);   //  把光标移动到 (0,0)
					 // 第一版方案是直接system("cls")，然后输出 ，导致刷新时有屏幕频繁闪烁
					 // 搜索后发现 直接把光标移动到(0,0) 然后输出 可以解决屏幕闪烁问题

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
