#pragma once
#include <iostream>
using namespace std;

//������ָ���ֵ�����������ʵ��ζ��ʹ�����õĴ���Ч�ʱ�ʹ��ָ���Ҫ�ߡ�
//��Ϊ��ʹ��֮ǰ����Ҫ�������ĺϷ��ԡ�
void printInt(const int& ri)
{
	cout << ri << endl;//����Ҫ����ri�����϶�ָ��һ��intֵ
}
//vs
void printInt(const int *pi)
{
	if (pi)
	{
		//���pi�Ƿ�ΪNULL
		cout << *pi<< endl;
	}
}