#include<iostream>
using namespace std;
template<class T>	//����ģ�岻�������ĺ���,�Ǳ��������ɾ������ʹ���Ĺ���
T Add(T left, T right)
{
	return left + right;
}
//ģ�����
//���ͱ��
void Swap(int& left, int& right)
{
	int temp = left;
	left = right;
	right = temp;
}
void Swap(double& left, double& right)
{
	double temp = left;
	left = right;
	right = temp;
}
void Swap(float& left, float& right)
{
	float temp = left;
	left = right;
	right = temp;
}
template<class T>
void Swap(T& left, T& right)
{
	T temp = left;
	left = right;
	right = temp;
}
void TestAdd()
{
	int a = 10;
	int b = 20;
	double c = 30.0;
	cout << Add(a, b) << endl;
	//Add(a, c);	//����䲻��ͨ�����룬��Ϊ�ڱ����ڼ䣬��������������ʵ����ʱ����Ҫ����ʵ������
	//ͨ��ʵ�� a �� T ����Ϊ int ��ͨ��ʵ�� c �� T ����Ϊ double ����ģ������б�ֻ��һ�� T ��
	//�������޷�ȷ���˴����׽� T ȷ��Ϊʲô���Ͷ�����
	//ע�⣺��ģ���б�����һ�㲻���������ת������
	//�˴������ַ�ʽ 1���û��Լ�ת�� 2��ʹ����ʽʵ����
	Add(a, (int)c);
	Add<int>(a, c);	//��ʽʵ����

	//������Ͳ�ƥ�䣬�������᳢����ʽ����ת��������޷�����ת���ͻᱨ��
}
void TestSwap()
{
	int a = 10;
	int b = 20;
	cout <<  a << " " << b << endl;
	Swap(a, b);
	cout << a << " " << b << endl;
}
//ģ�����ƥ��ԭ��
//һ����ģ�庯�����Ժ�һ���Ѿ����ڵ�ͬ������ģ��ͬʱ���ڶ��Ҹú���ģ�廹���Ա�ʵ����Ϊ�����
//ģ�庯��