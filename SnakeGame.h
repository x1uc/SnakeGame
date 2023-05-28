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
	deque<Snake> snake;  //一个双端的队列 ，来存储蛇身体每一块的坐标
	HANDLE hOut;         //移动光标需要的
	COORD pos;	     //同上，实际没用上，我在SetPos函数中重写了一个			
	double spped = 200;  //本来想加一个选择速度的功能，最后懒得加了，配合game_loop中的sleep可以控制刷新速度
	int food_x, food_y;  //食物的坐标
	int score = 0;       // 分数
	bool fist_op = true; // 如果时第一次操作需要尽心一些操作，后面实现时发现也是脱裤子放屁
	char dir;            // 贪吃蛇当前前进的方向
};
