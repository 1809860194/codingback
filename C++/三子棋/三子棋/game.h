#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int g_N = 3;
const char g_ChessFlag = ' ';

typedef struct Coordinate	//������
{
	int x;
	int y;
}Coordinate;

class TicTocTae
{
public:
	TicTocTae()	//���̳�ʼ��
	{
		InitChessBoard();
	}
	//�˵���ʾ
	void menu()
	{
		printf("*********1.play     0.exit*********\n");
	}
	void game()
	{
		//����һ������
		char ChessBoard[g_N][g_N];
		char ret = 0;
		//��ʼ������
		InitChessBoard();
		//չʾ����
		show_board(ChessBoard, g_N, g_N);
		//����һ�����������
		srand((unsigned int)time(NULL));
		while (1)
		{
			//�����
			player_move(ChessBoard, g_N, g_N);
			//�ж�����Ƿ�Ӯ��
			if ((ret = ISwin(ChessBoard, g_N, g_N)) != ' ')
				break;
			//û��Ӯ���ٴ�չʾ����
			show_board(ChessBoard, g_N, g_N);
			//������
			computer_move(ChessBoard, g_N, g_N);
			//�жϵ����Ƿ�Ӯ��
			if ((ret = ISwin(ChessBoard, g_N, g_N)) != ' ')
				break;
			//û��Ӯ���ٴ�չʾ����
			show_board(ChessBoard, g_N, g_N);
		}
		//�ߵ���һ��˵������Ӯ�˻���ƽ����
		//�Ǿ���Ҫ�ж�˭��˭Ӯ
		if (ret == 'X')
		{
			//���Ӯ
			printf("��Ӯ��\n");
		}
		else if (ret == '0')
		{
			//����Ӯ
			printf("������\n");
		}
		else if (ret == 'q')
		{
			printf("ƽ�֣���\n");
		}
		//���չʾ����
		show_board(ChessBoard, g_N, g_N);
	}
	//������ʾ
	void show_board(char board[g_N][g_N], int row, int col)
	{
		int i = 0;
		for (i = 0; i<row; i++)
		{
			printf(" %c | %c | %c \n",
				board[i][0], board[i][1], board[i][2]);
			if (i != 2)
				printf("---|---|---\n");
		}
	}
	void test()
	{
		int input = 0;
		do
		{
			//��ӡ�˵�
			menu();
			//���ѡ��
			printf("��ѡ��");
			scanf("%d", &input);
			//�ж����ѡ��������Ӧ�Ļ�Ӧ
			//��ʼ��Ϸ�����˳���Ϸ
			switch (input)
			{
			case 1:
				//��ʼ��Ϸ
				game();
				break;
			case 0:
				//�˳���Ϸ
				break;
			default:
				printf("ѡ�����\n");
				break;
			}
		} while (input);
	}
protected:
	void InitChessBoard()
	{
		int i, j;
		for (i = 0; i < g_N + 1; ++i)
		{
			for (j = 0; j < g_N + 1; ++j)
			{
				_ChessBoard[i][j] = g_ChessFlag;
			}
		}
	}
	//�ж���Ӯ
	char ISwin(char ChessBoard[g_N][g_N], int row, int col)
	{
		int i = 0;
		//ĳ������һ��
		for (i = 0; i<row; i++)
		{
			//һ�е�3��λ�õı��һ���Ҳ���Ϊ��ʼ�����õĿ�
			if ((ChessBoard[i][0] == ChessBoard[i][1])
				&& (ChessBoard[i][1] == ChessBoard[i][2])
				&& (ChessBoard[i][1] != ' '))
				//���ر���ǵ�ֵ��X����0��
				return ChessBoard[i][1];
		}
		//ĳ������һ��
		for (i = 0; i<col; i++)
		{
			//һ�е�3��λ�õı��һ���Ҳ���Ϊ��ʼ�����õĿ�
			if ((ChessBoard[0][i] == ChessBoard[1][i])
				&& (ChessBoard[1][i] == ChessBoard[2][i])
				&& (ChessBoard[1][i] != ' '))
				//���ر���ǵ�ֵ��X����0��
				return ChessBoard[1][i];
		}
		//�Խ�������һ��(�������Խ���)
		if ((ChessBoard[0][0] == ChessBoard[1][1])
			&& (ChessBoard[1][1] == ChessBoard[2][2])
			&& (ChessBoard[1][1] != ' '))
			//���ر���ǵ�ֵ��X����0��
			return ChessBoard[1][1];
		if ((ChessBoard[0][2] == ChessBoard[1][1])
			&& (ChessBoard[1][1] == ChessBoard[2][0])
			&& (ChessBoard[1][1] != ' '))
			//���ر���ǵ�ֵ��X����0��
			return ChessBoard[1][1];
		//�ߵ�����˵��û����Ӯ�����п��ܴ����ƽ��
		//��ʱ����Ҫ�ж�һ�������Ƿ�����
		//������˶���û����Ӯ��˵�������ƽ��
		if (ISfull(ChessBoard, row, col))
		{
			//�������ˣ�����q��ʾƽ��
			return 'q';
		}
		//�ߵ�����˵��û����ӮҲû��ƽ���򷵻�һ����ʼ�����õĿ�
		//�����������������Ϸ�������½���
		return ' ';
	}
	//�ж������Ƿ�������δ������0 ���˷���1
	static int ISfull(char ChessBoard[g_N][g_N], int row, int col)
	{
		int i = 0;
		int j = 0;
		for (i = 0; i<row; i++)
		{
			for (j = 0; j<col; j++)
			{
				if (ChessBoard[i][j] == ' ')
					return 0;
			}
		}
		return 1;
	}
	//�������
	void player_move(char ChessBoard[g_N][g_N], int row, int col)
	{
		int x = 0;
		int y = 0;
		while (1)
		{
			printf("�����\n");
			printf("����������:��1 2\n");
			scanf("%d%d", &x, &y);
			//�����±���㿪ʼ�����˵�ϰ���Ǵ�1��ʼ����˶��������Ժ��һ
			x--;
			y--;
			//�ж��±��Ƿ���Ч
			if (((x >= 0) && (x <= 2)) && ((y >= 0) && (y <= 2)))
			{
				//�����λ��û�б��߹�
				if (ChessBoard[x][y] == ' ')
				{
					//��������ӣ�������ΪX��������߹�
					ChessBoard[x][y] = 'X';
					break;
				}
				else
				{
					//����������
					printf("�±�����, �������룡");
				}
			}
			else
			{
				//�±겻�Ϸ�
				printf("�±�����, �������룡");
			}
		}
	}
	//��������
	void computer_move(char ChessBoard[g_N][g_N], int row, int col)
	{
		printf("������\n");
		while (1)
		{
			//�������������ߵ�ֵ
			int x = rand() % 3;
			int y = rand() % 3;
			//�����λ��û�б��߹�
			if (ChessBoard[x][y] == ' ')
			{
				//������Ϊ0��������߹�
				ChessBoard[x][y] = '0';
				break;
			}
		}
	}
private:
	char _ChessBoard[g_N + 1][g_N + 1];
};