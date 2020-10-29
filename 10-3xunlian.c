#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"   
//game1 实现三子棋  就是一个九宫格的游戏
void menu()
{
	printf("***********************\n");
	printf("***1.play     0.exit***\n");
	printf("***********************\n");
}
void game()
{
	char ret = 0;
	//数组是用来存放走的棋子的信息
	//这里定义一个关于行和列的头文件就可以很好的 在日后想要修改的时候轻松的只改变头文件的内容就可以了  增加了代码的可移植性
	char board[ROW][COL] = { 0 }; //这里可以理解为一开始我们在9宫格内放的内容都是   ------------空格    0也是不可打印的字符  但是他毕竟不是空格
	Initboard(board,ROW,COL);  //初始化棋盘（也是初始化数组）
	//打印棋盘
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//玩家下棋
		//电脑下棋
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')                    //对于这一段代码 我还是不能够很好的理解清楚
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("玩家赢\n");
	}
	else if (ret == '#')
	{
		printf("电脑赢\n");
	}
	else
	{
		printf("平局\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//只能调用一次所以把它放在最外面进行调用
	do
	{
		menu();
		printf("请选择：> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:   
			printf("选择错误，请重新选择！");//这里不要忘记了考虑完   玩和退出后 还有第三种选择方式，我们给他定义为default
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
