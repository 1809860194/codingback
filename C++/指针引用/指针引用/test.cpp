#include "User.h"
#include <string.h>
int main()
{
	char *p = NULL;//����ָ��Ϊ��ֵ
	char &r = *p;//������ָ���ֵ X
	//�������ǳ��к���ִ�н���ǲ�ȷ����
	string a = "1";
	string& rs = a;//��������δ��ʼ�����ñ����ʼ�� X
	string s("simon");
	string &rs = s;//��ȷ��rsָ��s

	string *p = nullptr;//����ʹ��δ��ʼ����ָ�룬��˵�ܱ���ͨ�������Ǵ��ڷ��� 
	return 0;
}