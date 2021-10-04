#include<iostream>
#include<stdlib.h>
#include<vector>
#include<cassert>
using namespace std;
//包括对局次数，出拳策略选择，胜场，记忆上一轮的策略 纯虚函数
class Game
{
public:
	enum SPS { stone, scissors, paper };
	static int count;//场次计数
	int vplayer{ 0 }, vcomputer{ 0 }, draw{ 0 };//玩家胜场，电脑胜场，平局场次
	static vector<int> a;//数组存放每局结果
	static vector<int> b;//数组存放玩家每次出拳的招数

public:
	virtual int strategy() { return 0; }
	//机制
	void victory(int& comchoice, int& plachoice)
	{
		cout << "第" << Game::count + 1 << "局游戏" << endl;
		int i;
		if ((plachoice == comchoice - 1) || (plachoice == comchoice + 2))
		{
			cout << "you win" << endl;
			Game::a.push_back(1);
			vplayer++;

		}
		if (plachoice == comchoice)
		{
			cout << "a dogfall" << endl;
			Game::a.push_back(0);
			draw++;
		}
		if ((plachoice == comchoice + 1) || (plachoice == comchoice - 2))
		{
			cout << "the computer win" << endl;
			Game::a.push_back(-1);
			vcomputer++;
		}
		Game::b.push_back(plachoice);
		Game::count++;
		//for (int i = 0; i < count; i++)
		//	cout << Game::a[count - 1]; cout << Game::b[count - 1];

	}
	//运算符重载A
	//游戏结果统计
	virtual void result()//(const Game &game)
	{
		cout << "目前游戏结果统计：" << endl;
		cout << "玩家胜场：" << vplayer << endl;
		cout << "电脑胜场：" << vcomputer << endl;
		cout << "平局次数：" << draw << endl;

	}
	//打印双方的出拳
	void printf(const int i)
	{
		if (i == 1)cout << "stone" << endl;
		if (i == 2)cout << "scissors" << endl;
		if (i == 3)cout << "paper" << endl;
	}


};

int Game::count = 0;
vector<int> Game::a;
vector<int> Game::b;

//第一种随机策略:和局数无关
class Fstrategy :public Game
{
public:
	int strategy() override
	{
		return(rand() % 3 + 1);
	}

};
//第二种：使用赢得上一轮策略
class Sstraregy :public Game
{
public:
	int strategy() override
	{
		for (int i = count - 1; i >= 0; i--)
		{
			if (Game::a[i] == 1) return Game::b[i];
			if (i == 0)return(-1);//没有上一轮的情况

		}
		return 0;
	}
};
//第三种：使用目前为止使用招数最少的策略
class Tstraregy :public Game
{
public:
	int strategy() override
	{
		int m{ 0 }, n{ 0 }, x{ 0 };
		for (int i = 0; i < count; i++)
		{
			if (Game::b[i] == 1)m++;
			if (Game::b[i] == 2)n++;
			if (Game::b[i] == 3)x++;
		}
		if (m <= n && m <= x)return 1;
		if (n <= m && n <= x)return 2;
		if (x <= m && x <= n)return 3;
		return 0;
	}
};
int main()
{
	Game* game[3];
	game[0] = new Fstrategy;
	game[1] = new Sstraregy;
	game[2] = new Tstraregy;

	int j{ 0 };
	cout << "按1开始游戏" << endl;
	cin >> j;
	system("cls");
	while (j)
	{
		//游戏程序
		int i{ 0 };
		int comchoice = rand() % 3 + 1;
		cout << "请输入你选择的策略(1,2,3)" << endl;
		cin >> i;
		//保证数组不会溢出
		if (i <= 3)
		{
			assert(i > 1) ;
			int plachoice = game[i - 1]->strategy();
			if (plachoice == -1)break;

			cout << "player选择";
			game[i - 1]->printf(plachoice);

			cout << "computer的选择为";
			game[i - 1]->printf(comchoice);
			//进行比较
			game[i - 1]->victory(comchoice, plachoice);
		}
		else cout << "无效" << endl;

		//查看游戏结果或继续游戏
		cout << "按1继续游戏,按0结束游戏,按2查看结果" << endl;
		cin >> j;
		
		if (j == 2 && i < 3)
		{
			game[i - 1]->result();
			j = 0;
		}

	}

}