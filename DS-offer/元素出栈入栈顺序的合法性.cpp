#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>  
#include <assert.h>  
#include <stack>  
using namespace std;

class
{
public:
	bool Check(int *stack_in, int *stack_out, int len_in, int len_out)
	{
		assert(stack_in && stack_out);
		if (len_in != len_out)         //�������г��Ȳ���ȣ����Ϸ�  
			return false;
		stack<int> s;
		int j = 0;
		int i = 0;
		for (; i < len_in; i++)
		{
			s.push(stack_in[i]);
			while (s.size() > 0 && s.top() == stack_out[j])//��ջ����ջ��Ԫ���뵱ǰ��ջ����Ԫ�ز���ȣ����Ϸ�  
			{
				s.pop();
				j++;
			}
		}
		return (s.size()>0) ? false : true;                //�����г�ջ����Ԫ�ض�ƥ����֮��ջ��Ϊ�գ����Ϸ�  
	}

};
int main()
{
	return 0;
}