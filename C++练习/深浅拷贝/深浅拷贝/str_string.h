#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <string.h>
#include <iostream>
using namespace std;

//1����ͳд��		̤ʵ		
#if 0
class String
{
public:
	String(const char* str)//��ʼ���б���Զ�������Ӱ�����
		: _str = new char[_size + 1];	//�ռ�  _size + 1
	{
		_str = new char[_size + 1];	//�ռ�  _size + 1
		strcpy(_str, str);	//ǳ����
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);	//���
	}
	String& operator=(const String& s)		//�����дʹ�ñ�����Ĭ�ϸ��ģ����ܻ�����ڴ�й©	��дֻ���ֵ����
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
		return *this;
	}
	~String()
	{
		delete[] _str;
		_str = NULL;
	}
	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
};
#endif

//2���ִ�д��
class String
{
public:
	String(const char* str)//��ʼ���б���Զ�������Ӱ�����
		: _size(strlen(str))	//������Ч�ַ�����
		, _capacity(_size)	//����  _capacity �� _size �������� \0
	{
		_str = new char[_size + 1];	//�ռ�  _size + 1
		strcpy(_str, str);	//ǳ����
	}
	//s1.Swap(s2)
	void Swap(String&s)
	{
		swap(_str, s._str);
		swap(_size, s._size);
		swap(_capacity, s._capacity);
	}
	String(const String& s)
		: _str(NULL)
	{
		String tmp(s._str);
		this->Swap(tmp);
	}
	String& operator=(String s)		//�����дʹ�ñ�����Ĭ�ϸ��ģ����ܻ�����ڴ�й©	��дֻ���ֵ����
	{
		this->Swap(s);
		return *this;
	}
	~String()
	{
		if (_str)
		{
			delete[] _str;
			_str = NULL;
		}
	}

	void PushBack(char ch);

	void Append(const char* str);
	void Insert(size_t pos, char ch);
	void Insert(size_t pos, const char* str);

	void PopBack();
	void Erase(size_t pos, size_t len);

	size_t Capacity();
	bool Empty();
	size_t Find(char ch);
	size_t Find(const char* sub);

	char& operator[](size_t pos)
	{
		return _str[pos];
	}

	bool operator<(const String& s);
	bool operator<=(const String& s);
	bool operator>(const String& s);
	bool operator>=(const String& s);
	bool operator==(const String& s);
	bool operator!=(const String& s);

	char* c_str()
	{
		return _str;
	}
private:
	char* _str;
	size_t _size;	
	//�������Ӷ��ٺ���	����һ�����Ӷ���  ���Ƕ����Ϻ�
	//���� 10 �������� 8 ��������
	//���ÿ�ζ����� �����ĸ�Ԫ�� ����ô���Ӱ˱�ʮ�����ʻ��Ƕ�������
	size_t _capacity;
};

void TestString()
{
	String s1("hello");
	String s2(s1);
	cout << "c_str:" << s2.c_str() << endl;
	cout << "c_str:" << s1.c_str() << endl;
	String s3("worldsubstr!!!");
	s1 = s3;	
	//1���ȿ���һ���ռ�� s3 ��Сһ���Ŀռ�
	//2���ڿ�����ȥ
	//3���ͷ�ԭ�ȵ�С�ڴ�
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s3.c_str() << endl;
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s2.c_str() << endl;
	s1.Swap(s2);
	cout << "c_str:" << s1.c_str() << endl;
	cout << "c_str:" << s2.c_str() << endl;
}

//void PushBack(char ch);
//
//void Append(const char* str);
//void Insert(size_t pos, char ch);
//void Insert(size_t pos, const char* str);
//
//void PopBack();
//void Erase(size_t pos, size_t len);
//
//size_t Capacity();
//bool Empty();
//size_t Find(char ch);
//size_t Find(const char* sub);
//
//char& operator[](size_t pos)
//{
//	return _str[pos];
//}
//
//bool operator<(const String& s);
//bool operator<=(const String& s);
//bool operator>(const String& s);
//bool operator>=(const String& s);
//bool operator==(const String& s);
//bool operator!=(const String& s);


class Stringstr
{
public:
	Stringstr(char* str)				//String s1("hello world");  ����һ������������Ҵ� hello world �ַ��������Ժ����ɾ�Ĳ��޷�����
		: _str(str)							//����ͨ���ȿ���ͬ����С�ռ��ٽ��п�������
												//strcpy �����Ὣ "\0" ����		while(*dst++ = *src++){}	�ȿ����� ++ 
	{}
	~Stringstr()
	{}
private:
	char* _str;
};
void TestStringstr()
{
	Stringstr s1("hello world");
}