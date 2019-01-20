#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int N = 15;	//���̴�С 15 * 15
const char ChessBoardFlag = ' ';
const char flag1 = 'o';	//���1
const char flag2 = 'x';	//���2

typedef struct Coordinate	//������
{
	int x;	//��
	int y;	//��
}Coordinate;

class GoBang	//��������
{
public:
	GoBang()	//���캯�������̽��г�ʼ��
	{
		InitChessBoard();
	}
	void Play()	//����
	{
		Coordinate pos1;	//���1
		Coordinate pos2;	//���2
		int n = 0; 
		while (1)
		{
			int mode = ChoiceMode();
			while (1)
			{
				if (mode == 1)	//���� vs ���
				{
					ComputerChess(pos1, flag1);
					if (GetVictory(pos1, 0, flag1) == 1)
						break;
					PlayChess(pos2, 2, flag2);
					if (GetVictory(pos2, 2, flag2))
						break;
				}
				else    //���1vs���2
				{
					PlayChess(pos1, 1, flag1);
					if (GetVictory(pos1, 1, flag1))
						break;

					PlayChess(pos2, 2, flag2);
					if (GetVictory(pos2, 2, flag2))
						break;
				}
			}
			cout << "***����һ��***" << endl;
			cout << "y or n :";
			char c = 'y';
			cin >> c;
			if (c == 'n')
				break;
		}
	}
protected:
	int ChoiceMode()	//ѡ��ģʽ
	{
		int i = 0;
		system("cls");
		InitChessBoard();
		cout << "***0���˳�  1������vs���  2�����vs���***" << endl;
		while (1)
		{
			cout << "��ѡ��";
			cin >> i;
			if (i == 0)
				exit(1);
			if (i == 1 || i == 2)
				return i;
			cout << "���벻�Ϸ�" << endl;
		}
	}
	void InitChessBoard()	//��ʼ������
	{
		int i, j;
		for (i = 0; i < N + 1; ++i)
		{
			for (j = 0; j < N + 1; ++j)
			{
				_ChessBoard[i][j] = ChessBoardFlag;
			}
		}
	}
	void PrintChessBoard()	//��ӡ����
	{
		system("cls");
		for (int i = 0; i < N + 1; ++i)
		{
			for (int j = 0; j < N + 1; ++j)
			{
				if (i == 0)
				{
					if (j != 0)
						printf("%d  ", j);
					else
						printf("   ");
				}
				else if (j == 0)
					printf("%2d ", i);
				else
				{
					if (i < N + 1)
					{
						printf("%c |", _ChessBoard[i][j]);
					}
				}
			}
			cout << endl;
			cout << "   ";
			for (int m = 0; m < N; m++)
			{
				printf("--|");
			}
			cout << endl;
		}
	}
	void PlayChess(Coordinate& pos, int player, int flag)//�����
	{
		PrintChessBoard();
		while (1)
		{
			printf("���%d�������꣺", player);
			cin >> pos.x >> pos.y;
			if (JudgeValue(pos) == 1)
				break;
			cout << "���겻�Ϸ�����������" << endl;
		}
		_ChessBoard[pos.x][pos.y] = flag;
	}
	void ComputerChess(Coordinate& pos, char flag)	//������
	{
		PrintChessBoard();
		int x = 0;
		int y = 0;
		while (1)
		{
			x = (rand() % N) + 1;
			srand((unsigned int)time(NULL));
			y = (rand() % N) + 1;
			srand((unsigned int)time(NULL));
			if (_ChessBoard[x][y] == ChessBoardFlag)
				break;
		}
		pos.x = x;
		pos.y = y;
		_ChessBoard[pos.x][pos.y] = flag;
	}
	int JudgeValue(const Coordinate& pos)	//�ж������Ƿ�Ϸ�
	{
		if (pos.x > 0 && pos.x <= N&&pos.y > 0 && pos.y <= N)
		{
			if (_ChessBoard[pos.x][pos.y] == ChessBoardFlag)
			{
				return 1;
			}
		}
		return 0;
	}
	int JudgeVictory(Coordinate& pos, char flag)	//�ж�ʤ��(�ײ��жϣ�
	{
		int begin = 0;
		int end = 0;

		int begin1 = 0;
		int end1 = 0;

		//�ж����Ƿ���������
		(pos.y - 4) > 0 ? begin = (pos.y - 4) : begin = 1;
		(pos.y + 4) >N ? end = N : end = (pos.y + 4);

		for (int i = pos.x, j = begin; j + 4 <= end; j++)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i][j + 1] == flag&&
				_ChessBoard[i][j + 2] == flag&&_ChessBoard[i][j + 3] == flag&&
				_ChessBoard[i][j + 4] == flag)
				return 1;
		}

		//�ж����Ƿ���������
		(pos.x - 4) > 0 ? begin = (pos.x - 4) : begin = 1;
		(pos.x + 4) > N ? end = N : end = (pos.x + 4);

		for (int j = pos.y, i = begin; i + 4 <= end; i++)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j] == flag&&
				_ChessBoard[i + 2][j] == flag&&_ChessBoard[i + 3][j] == flag&&
				_ChessBoard[i + 4][j] == flag)
				return 1;
		}

		int len = 0;

		//�ж����Խ����Ƿ���������
		pos.x > pos.y ? len = pos.y - 1 : len = pos.x - 1;
		if (len > 4)
			len = 4;
		begin = pos.x - len;       //���������ʼλ��
		begin1 = pos.y - len;      //���������ʼλ��

		pos.x > pos.y ? len = (N - pos.x) : len = (N - pos.y);
		if (len>4)
			len = 4;
		end = pos.x + len;       //������Ľ���λ��
		end1 = pos.y + len;      //������Ľ���λ��

		for (int i = begin, j = begin1; (i + 4 <= end) && (j + 4 <= end1); ++i, ++j)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j + 1] == flag&&
				_ChessBoard[i + 2][j + 2] == flag&&_ChessBoard[i + 3][j + 3] == flag&&
				_ChessBoard[i + 4][j + 4] == flag)
				return 1;
		}


		//�жϸ��Խ����Ƿ���������
		(pos.x - 1) >(N - pos.y) ? len = (N - pos.y) : len = pos.x - 1;
		if (len > 4)
			len = 4;
		begin = pos.x - len;//���������ʼλ��
		begin1 = pos.y + len;//���������ʼλ��

		(N - pos.x) > (pos.y - 1) ? len = (pos.y - 1) : len = (N - pos.x);
		if (len>4)
			len = 4;
		end = pos.x + len;//������Ľ���λ��
		end1 = pos.y - len;//������Ľ���λ��

		for (int i = begin, j = begin1; (i + 4 <= end) && (j - 4 >= end1); ++i, --j)
		{
			if (_ChessBoard[i][j] == flag&&_ChessBoard[i + 1][j - 1] == flag&&
				_ChessBoard[i + 2][j - 2] == flag&&_ChessBoard[i + 3][j - 3] == flag&&
				_ChessBoard[i + 4][j - 4] == flag)
				return 1;
		}


		for (int i = 1; i < N + 1; ++i)//������û������
		{
			for (int j = 1; j < N + 1; ++j)
			{
				if (_ChessBoard[i][j] == ChessBoardFlag)
					return 0;//0��ʾ����û��
			}
		}

		return -1;      //����
	}
	bool GetVictory(Coordinate& pos, int player, int flag)	//�ж�ʤ���������ĸ����Ӯ
	{
		int n = JudgeVictory(pos, flag);//�ж���û���˻�ʤ
		if (n != 0)//���˻�ʤ��0��ʾû���˻�ʤ
		{
			PrintChessBoard();
			if (n == 1)//�����Ӯ��
			{
				if (player == 0)//0��ʾ���Ի�ʤ��1��ʾ���1,2��ʾ���2
					printf("***���Ի�ʤ***\n");
				else
					printf("***��ϲ���%d��ʤ***\n", player);
			}
			else
				printf("***˫������***\n");

			return true;//�Ѿ����˻�ʤ
		}
		return false;//û���˻�ʤ
	}
private:
	char _ChessBoard[N + 1][N + 1];
};