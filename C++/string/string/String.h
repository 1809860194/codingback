#pragma once
#include <iostream>
#include <assert.h>
#include <string>
using namespace std;

//	string ��ĳ�������Ĺ���
/*
	string();	//	����յ� string �����
	string(const char* s);	// ʹ�� c ���ĵ��ַ��������� string �����
	string(size_t n, char c);	//	string ������а��� n ���ַ� c
	string(const string& s);	//	�������캯��
	string(const string& s, size_t n);	//	�� s �е�ǰ n ���ַ����� string ��Ķ���
*/

void TestString1()
{
	cout << "string ��ĳ�������Ĺ���" << endl;
	string s1;	//	����յ� string ����� s1
	string s2("hello world!!!");	//	ʹ�� c ��ʽ���� string ��Ķ��� s2
	string s3(10, 'h');	//	�� 10 ���ַ� h ���� string ����� s3
	string s4(s2);	//	�� s2 ���� string ����� s4
	string s5(s3, 5);	//	���ַ��� s3 ��ǰ����ַ����� string ����� s5
}

// string ��Ķ������������
/*
	size_t size() const	�����ַ�������Ч�ַ�����
	size_t length() const	�����ַ�������Ч�ַ�����
	size_t capacity() const		�����������ܿռ��С
	bool empty() const		����ַ����Ƿ�Ϊ�մ�
	void clear()	�����Ч�ַ�
	void resize(size_t n, char c)		����Ч�ַ�������Ϊ n ��������Ŀռ����ַ� c ���
	void resize(size_t n)		����Ч�ַ�������Ϊ n ��������Ŀռ��� 0 ���
	void reserve(size_t res_arg = 0)	Ϊ�ַ���Ԥ���ռ�
*/

void TestString2()
{
	cout << "string ��Ķ������������" << endl;
	//	string �����ֱ��֧�� cin �� cout ���������
	string s("hello world!!!");
	cout << "length:" << s.length() << endl;
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//	�� s �е��ַ�����գ�ע�⣺���ʱֻ�ǽ� size �� 0�����ı�ײ�ռ��С
	s.clear();
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//�� s ����Ч�ַ��������ӵ� 10 �������λ�����ַ� a �������
	s.resize(10, 'a');
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//�� s ����Ч�ַ����������� 15 �������λ���� '\0' �������
	//"aaaaaaaaaa\0\0\0\0\0\0\0\0\0\0"
	s.resize(15);
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;

	//�� s ����Ч�ַ������� 5 ��
	s.resize(5);
	cout << "size:" << s.size() << endl;
	cout << "length:" << s.length() << endl;
	cout << "capacity:" << s.capacity() << endl;
	cout << "s:" << s << endl;
}

void TestString3()
{
	cout << "���� reserve �Ƿ��ı� string ����ЧԪ�ظ���" << endl;
	//���� reserve �Ƿ��ı� string ����ЧԪ�ظ���
	string s;
	s.reserve(100);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;

	//���� reserve ����С�� string �ײ�ռ��Сʱ���Ƿ�Ὣ�ռ���С
	s.reserve(50);
	cout << "size:" << s.size() << endl;
	cout << "capacity:" << s.capacity() << endl;
}
//ע�⣺

/*
		1��size() �� length() �����ײ�ʵ��ԭ����ȫ��ͬ������ size() ��ԭ��
	��Ϊ�������������Ľӿڱ���һ�£�һ������»������� size()
		2��clear() ֻ�ǽ� string �е���Ч�ַ���գ����ı�ײ�ռ��С
		3��resize(size_t n) �� resize(size_t n, char c) ���ǽ��ַ�������Ч�ַ������ı�� n ����
	��ͬ���ǵ��ַ���������ʱ��resize(n) �� 0 �����ʣ��ռ䣬�� resize(size_t n, char c) �����ַ����
	ע�⣺resize() �ڸı�Ԫ�ظ���ʱ�������Ԫ�ظ������࣬���ܻ�ı�ײ�������С capacity ��
	����Ǽ�����ЧԪ�ظ�������ײ�ռ��С����
		4��reserve(size_t res_arg = 0) Ϊ string Ԥ���ռ䣬���ı���ЧԪ�ظ�����
	�� reserve �Ĳ���С�� string �ĵײ�ռ�ʱ��reserve ����ı�������С
*/

//string �����ķ��ʲ���

/*
	char& operator[](size_t pos)		����λ�� pos ���ַ���const string ��������
	const char& operator[](size_t pos)		//���� pos λ�õ��ַ����� const string ��������
*/

void TestString4()
{
	string s1("hello world!!!");
	const string s2("hello world!!!");
	cout << s1 << " " << s2 << endl;
	cout << s1[0] << " " << s2[0] << endl;

	s1[0] = 'H';
	cout << "s1:" << s1 << endl;
	for (size_t i = 0; i < s1.size(); ++i)
	{
		cout << "s1:" << s1[i];
	}
	cout << endl;
	//s2[0] = 'H'	����ͨ������ �� const ���Ͷ��󲻿����޸�
}

// string �������޸Ĳ���

/*
	void push_bask(char c);	���ַ���β�����ַ� c
	string& append(const char* s);	���ַ�������׷��һ���ַ���
	string& operator+=(const string& str);	���ַ�������׷���ַ���
	string& operator+=(const char* c);	���ַ�������׷�� c ����ַ���
	string& operator+=(const char c)	���ַ�������׷���ַ� c
	const char* c_str() const	���� c �����ַ���
	size_t find(char c, size_t pos = 0) const	���ַ��� pos λ������ʼ���ַ� c �����ظ��ַ������ַ�����λ��
	size_t rfind(char* c, size_t pos = npos) const		���ַ��� pos λ�ÿ�ʼ��ǰ���ַ� c �����ظ��ַ�����λ��
	string substr(size_t pos = 0, size_t n = npos) const		�� str �д� pos λ�ÿ�ʼ��ȡ n ���ַ���Ȼ���䷵�� 
*/


void TestString5()
{
	string str;  
	str.push_back(' ');   // ��str�����ո�    
	str.append("hello");  // ��str��׷��һ���ַ�"hello"  
	str += 'b';           // ��str��׷��һ���ַ�'b'
	str += "it";          // ��str��׷��һ���ַ���"it"    
	cout<<str<<endl; 
	cout<<str.c_str()<<endl;   // ��C���Եķ�ʽ��ӡ�ַ���      
	// ��ȡfile�ĺ�׺    
	string file("string.cpp"); 
	size_t pos = file.rfind('.');
	string suffix(file.substr(pos, file.size()-pos));
	cout << suffix << endl;      
	
	// npos��string�����һ����̬��Ա����    
	// static const size_t npos = -1;
	// ȡ��url�е�����    
	string url("http://www.cplusplus.com/reference/string/string/find/");
	cout << url << endl;
	size_t start = url.find("://");
	if (start == string::npos)
	{
		cout << "invalid url" << endl;      
		return;   
	}
	start += 3;    
	size_t finish = url.find('/', start); 
	string address = url.substr(start, finish - start);    
	cout << address << endl;    
	// ɾ��url��Э��ǰ׺    
	pos = url.find("://");
	url.erase(0, pos+3);  
	cout<<url<<endl;
}

void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
void TestPushBack_P()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s += 'c';
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed: " << sz << '\n';
		}
	}
}
/*
ע�⣺
		1. ��stringβ��׷���ַ�ʱ��s.push_back(c) / s.append(1, c) / s += 'c'���ֵ�ʵ�ַ�ʽ��࣬
һ�� �����string��� += �����õıȽ϶࣬ += ���������������ӵ����ַ��������������ַ����� 
		2. ��string����ʱ������ܹ����Ԥ�����Ŷ����ַ���������ͨ��reserve�ѿռ�Ԥ���á�
*/

/*
	string ��ķǳ�Ա����
	operator+();
	operator<<();
	operator>>();
	getline()	��ȡһ���ַ���
	relational operators		�ַ�����С�Ƚ�
*/

#if 0
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//���������ı�����

//��ת�ַ���
string reverseString(string s)
{
	if (s.empty())
		return s;
	size_t start = 0;
	size_t end = s.size() - 1;
	while (start < end)
	{
		swap(s[start], s[end]);
		start++;
		end--;
	}
	return s;
}
//���ַ�����ֻ����һ�ε��ַ�
int firstUniqueChar(string s)
{
	//ͳ��ÿ���ַ����ֵĴ���
	size_t array[256] = { 0 };
	int size = s.size();
	for (size_t i = 0; i < size; ++i)
	{
		array[s[i]] += 1;
	}
	//�����ַ������ǰ������ֻ����һ�ε��ַ�
	for (size_t i = 0; i < size; ++i)
	{
		if (array[s[i]] == 1)
		{
			return i;
		}
	}
	return -1;
}

//�ַ������һ�����ʵĳ���
int _main()
{
	string line;
	while (getline(cin, line))
	{
		size_t pos = line.rfind(' ');
		cout << line.size() - pos - 1 << endl;
	}
	return 0;
}

//�ַ���ת��������
//�ַ����Ŀո��滻
//�ַ������
//��֤�Ƿ�Ϊ����
//�ַ������

#include <assert.h>
//��ͳд�� string ��
class String
{
public:
	String(const char* str = "")
	{
		//���� string �����ʱ��������� nullptr ָ�룬��Ϊ����Ƿ�
		if (str == nullptr)
		{
			assert(false);
			return;
		}
		_str = new char[strlen(str) + 1];
		strcpy(_str, str);
	}
	String(const String& s)
		: _str(new char[strlen(s._str) + 1])
	{
		strcpy(_str, s._str);
	}
	String& operator=(const String& s)
	{
		if (this != &s)
		{
			char* pStr = new char[strlen(s._str) + 1];
			strcpy(pStr, s._str);
			delete[] _str;
			_str = pStr;
		}
		return *this;
	}
	//�������������������캯�����ٳ����Ŀռ�
	~String()
	{
		delete[] _str;
		_str = nullptr;
	}

private:
	char* _str;
};

//�ִ�д�� string ��
namespace mod
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				str = "";
			}
			_str = new char[strlen(str) + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(nullptr)
		{
			String strTmp(s._str);
			swap(_str, strTmp._str);
		}
		String& operator=(String s)
		{
			swap(_str, s._str);
			return *this;
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				String strTmp(s._str);//�ô���������쵱ǰ����Ȼ�󽻻�
				swap(_str, strTmp._str);
			}
		}
		~String()
		{
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}
/*
	��ͳд�����ִ�д��������
	1����ͳд������ɶ��Ը�
	2���ִ�д�������࣬��ά���Ըߣ� new �� delete ����һ��
*/
#endif

//string ��ģ��ʵ��
namespace fun
{
	class String
	{
	public:
		String(const char* str = "")
		{
			if (nullptr == str)
			{
				assert(false);
				return;
			}
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}
		String(const String& s)
			: _str(new char[s._capacity + 1])
			, _size(s._size)
			, _capacity(s._capacity)
		{
			strcpy(_str, s._str);
		}
		String& operator=(const String& s)
		{
			if (this != &s)
			{
				char* pStr = new char[s._capacity + 1];
				strcpy(pStr, s._str);

				delete[] _str;
				_str = pStr;
				_size = s._size;
				_capacity = s._capacity;
			}
			return *this;
		}
		~String()
		{
			if (_str)
			{
				delete[] _str;
				_str = nullptr;
			}
		}
	public:
		void pushback(char c)
		{
			if (_size == _capacity)
				reserve(_capacity * 2);
			_str[_size++] = c;
			_str[_size] = '\0';
		}
		void append(size_t n, char c)
		{
			for (size_t i = 0; i < n; ++i)
			{
				pushback(c);
			}
		}
		void reserve(size_t newcapacity)
		{
			//������������ھ��������򿪱��¿ռ�
			if (newcapacity > _capacity)
			{
				char* str = new char[newcapacity + 1];
				strcpy(str, _str);//�Ѿɿռ����ݿ������¿ռ�
				//�ͷžɿռ䣬Ȼ��ʹ���¿ռ�
				delete[] _str;
				_str = str;
				_capacity = newcapacity;
			}
		}
		String& operator+=(char c)
		{
			pushback(c);
			return *this;
		}
		String& operator+=(const char* str);//׷���ַ���
		void resize(size_t newsize, char c = char())
		{
			if (newsize > _size)
			{
				//��� newsize ���ڵײ�ռ��С������Ҫ���ٿռ�
				if (newsize > _capacity)
				{
					reserve(newsize);
				}
				memset(_str + _size, c, newsize - _size);
			}
			_size = newsize;
			_str[newsize] = '\0';
		}
	private:
		char* _str;
		size_t _capacity;
		size_t _size;
	};
}
