#include "template.h"
int main()
{
	Add(1, 2);
	Add(1.0, 2.0);//ģ��һ�㲻���������ת��
	cout << Add(1.0, 2.0) << endl;
	TestAdd();
	TestSwap();
	return 0;
}