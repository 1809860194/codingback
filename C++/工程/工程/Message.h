#pragma once

/**
* ��Ϣ�б�
* type = 1 // ��������,  msg = ����������
* type = 2 // ������
* type = 3 // �������������Ϸ
* type = 4 // �ܾ���Ϸ����
* type = 5 // ͬ������
* type = 6 // ����ʤ����Ϣ
* type = 7 // �Ͽ���������
* type = 8 // ������Ϸ�����ǲ����ڴ����ϣ�����һ�ֿ�ʼʱ���ᶪʧ
* type = 9 // ����µ���ҵ����пͻ��˵�����б�
* type = 10// ��Ӧ��Ϣ type ==1
* type = 11// �������Ϸ,msg ������ҵ����� ,������Ϸ�����������Ϸ
* type = 12//��Ϣ����
* type = 13// ���������ɫ
* type = 14// msg�� ���������һ������
* type = 15// ����˸�����Ϣ
* type = 16// ���Ϳ��ƻ������Ϣ
* type = 17// ��Ϸʧ��
* type = 18// ������׽��ֹر�
* type = 19// ��ҽ�����Ϸ������
* type = 20// ���Ի�ʤ/ ��һ�ʤ
*/

class Message  //���������л�����
{
public:
	Message()
	{
		setting = true;
		char* msg = new char[50];
	}
	~Message()
	{
		delete[] msg;
	}
public:
	int type;            //��Ϣ���� ,eg.1=��������
	bool setting;      // �Ƿ����ý���
	int color;           // ������ɫ ,1 = black ,2 = white
	bool forYourTurn;  //�ж��Ƿ��ֵ�����������
	int coordinateX;     // ��¼���꣨X,Y��
	int coordinateY;
	char msg[];           // ��Ϣ����

};
