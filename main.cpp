#include "SnakeGame.h"
struct node
{
	string name;
	int score;
	bool operator<(const node &p)
	{
		return this->score > p.score;
	} // 函数重载 以至于sort可以降序输出
};
node rank_list[5000];  //新加的排行榜模块
int main()
{
	SnakeGame G1;
	cout << "draw you name" << endl;  //输入你的名字 名字和分数会加入后续的排行榜
	string name;
	cin >> name;
	cin.ignore();
	cout << "press 'w' play game" << endl;    
	cout << "w up s down a left d right" << endl;
	G1.game_loop();  //游戏主体
	ofstream ofs;  //游戏结束后把 名字和分数写入文件中保存，以至于下次运行的时候你之前的游戏数据还在排行榜中
	ofs.open("filename.txt", ios::out | ios::app);
	ofs << name << ' ' << G1.getScore() << endl;
	ofs.close();
	ifstream ifs;
	ifs.open("filename.txt", ios::in);
	string name_new;
	int sc;
	cout << "name\tscore" << endl;
	int idx = 0;
	while (ifs >> name_new >> sc)
	{
		rank_list[++idx].name = name_new;
		rank_list[idx].score = sc;
	}
	ifs.close();
	sort(rank_list + 1, rank_list + idx + 1);
	cout << "--------------------------------\n";
	for (int i = 1; i <= idx; i++)
	{
		cout << '|' << rank_list[i].name << "\t|" << rank_list[i].score << "\t|" << endl;
	}
	cout << "--------------------------------";
	system("pause");
	return 0;
}
