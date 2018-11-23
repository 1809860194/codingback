#pragma once

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

void func2()
{
	static int c = 10;
	int d = 10;

	char* p1 = "hello";
	char p2[] = "hello";
	int* ps = (int*)malloc(4);
	cout << strlen(p1) << endl;;
	cout << strlen(p2) << endl;
	cout << sizeof(p1) << endl;
	cout << sizeof(p2) << endl;
}
void func1()
{
	static int a1 = 10;
	int b = 10;
}
void Test1()
{
	func1();
	func2();
}
void Test2()
{
	int* p1 = new int;
	int* p2 = new int(10);		//���ù��캯��
	int* p3 = new int[10];		//��������
	cout << "p1:addr" << p1 << endl;
	cout << "p2:addr" << p2 << endl;
	cout << "p3:addr" << p3 << endl;
	delete p1;
	delete p2;
	delete[] p3;
	cout << "p1:addr" << p1 << endl;
	cout << "p2:addr" << p2 << endl;
	cout << "p3:addr" << p3 << endl;
}

//1����������	new -- malloc ����û����
//2���Զ�������
//���� malloc Ϊʲô��Ҫ new 
class AA
{
public:
	AA()
	{
		cout << "AA()" << endl;
	}
	~AA()
	{
		cout << "~AA()" << endl;
	}
};
void TestAA3()
{
	AA* p1 = (AA*)malloc(sizeof(AA));
	free(p1);
	//1����̬���ٿռ�
	//2�����ù��캯������ʼ��������������������
	AA* p2 = new AA; 
	delete p2;
	AA* p3 = new AA[10];
	delete[] p3;	//	��ε�֪���ö��ٴ�����
}

class MyVector
{
public:
	MyVector()
	{
		_a = new int[3];
		cout << "_a:addr" << _a << endl;
		cout << "MyVector()" << endl;
	}
	~MyVector()
	{
		delete _a;
		cout << "~MyVector" << endl;
	}
private:
	int* _a;
};
void TestMyVector4()
{
	MyVector* pv = (MyVector*)malloc(sizeof(MyVector));
	cout << "pv:addr" << pv << endl;
	free(pv);

	//char* p1 = (char*)malloc(0x7fffffff);
	//cout << "p1:addr" << p1 << endl;
	MyVector* ptr = new MyVector;
	cout << "ptr:addr" << ptr << endl;
	delete ptr;
}

//���֤�� operator new ��������
void Test5()
{
	int* p5 = (int*)operator new(4);
	cout << "p5:addr" << p5 << endl;
	int* p6 = (int*)malloc(4);
	cout << "p6:addr" << p6 << endl;
	//Ϊʲô����	operator new
	//new ���ռ䲢�ҵ��ù������
	//	new���ռ�->operator new == malloc + ʧ���쳣
	//2�����ù���
	//3����������
	//4���ͷſռ�	operator delete

}
void TestSize6()
{
	cout << sizeof(AA) << endl;
	cout << sizeof(MyVector) << endl;
}
//��λ new ���ʽ
void Test_allocator()
{
	allocator<AA> alloc;
	AA* p1 = alloc.deallocate(1);	//�ڴ��
}