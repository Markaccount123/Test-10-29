#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"   
//game1 ʵ��������  ����һ���Ź������Ϸ
void menu()
{
	printf("***********************\n");
	printf("***1.play     0.exit***\n");
	printf("***********************\n");
}
void game()
{
	char ret = 0;
	//��������������ߵ����ӵ���Ϣ
	//���ﶨ��һ�������к��е�ͷ�ļ��Ϳ��Ժܺõ� ���պ���Ҫ�޸ĵ�ʱ�����ɵ�ֻ�ı�ͷ�ļ������ݾͿ�����  �����˴���Ŀ���ֲ��
	char board[ROW][COL] = { 0 }; //����������Ϊһ��ʼ������9�����ڷŵ����ݶ���   ------------�ո�    0Ҳ�ǲ��ɴ�ӡ���ַ�  �������Ͼ����ǿո�
	Initboard(board,ROW,COL);  //��ʼ�����̣�Ҳ�ǳ�ʼ�����飩
	//��ӡ����
	DisplayBoard(board,ROW,COL);
	while (1)
	{
		//�������
		//��������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')
		{
			break;
		}
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board,ROW,COL);
		if (ret != 'C')                    //������һ�δ��� �һ��ǲ��ܹ��ܺõ�������
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("���Ӯ\n");
	}
	else if (ret == '#')
	{
		printf("����Ӯ\n");
	}
	else
	{
		printf("ƽ��\n");
	}
}
void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));//ֻ�ܵ���һ�����԰���������������е���
	do
	{
		menu();
		printf("��ѡ��> ");
		scanf("%d", &input);
		switch (input)
		{
		case 1: 
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:   
			printf("ѡ�����������ѡ��");//���ﲻҪ�����˿�����   ����˳��� ���е�����ѡ��ʽ�����Ǹ�������Ϊdefault
			break;
		}
	} while (input);
}
int main()
{
	test();
	return 0;
}
