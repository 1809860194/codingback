#include <iostream>
#include "user.h"
#include <cstdlib>
using namespace std;

const char*fileDat = "c:/StudentDates";

int main()
{
	char choice;
	while (1)
	{
		system("cls");
		cout << "**********************************************" << endl;
		cout << "*                 ѧ����Ϣ����ϵͳ           *" << endl;
		cout << "**********************************************" << endl;
		cout << "*               1��¼��ɼ�                  * " << endl;
		cout << "*               2���ɼ����                  * " << endl;
		cout << "*               3����ѯ�ɼ�                  * " << endl;
		cout << "*               4: �޸ĳɼ�                  * " << endl;
		cout << "*               5: �ɼ���¼                  *" << endl;
		cout << "*               6: ɾ������                  *" << endl;
		cout << "*               7: ѧ������                  *" << endl;
		cout << "*               q: �˳�����                  * " << endl;
		cout << "**********************************************" << endl;
		cout << "����������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case'1':Input(fileDat); break;
		case'2':Inquire(fileDat); break;
		case'3':Change(fileDat); break;
		case'4':Modify(fileDat); break;
			//		case'5':Add(fileDat);break;
		case'6':Delete(fileDat); break;
		case'7':Stusort(fileDat); break;
		case'q':
		case'Q':cout << "�˳�ϵͳ\n"; return 0;
			//		default:cout<<"���������������";
		}
	}
}

