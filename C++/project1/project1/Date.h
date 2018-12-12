#pragma once
#include<iostream>
using namespace std;

//		�Զ��������������

class Date
{
	/*
	��Ԫ������
		1��������ĳ�Ա����
		2�����Է������˽�г�Ա����
		3����Ԫ���������� const ����
		4���ƻ�����ķ�װ��
		5����Ԫ��������������κεط����������ܷ����޶�������
		6����Ԫ����û�����ص� this 
		��Ԫ��������Ҫͨ������������
	*/
	friend ostream& operator<<(ostream& _cout, const Date& d);		//��Ԫ����
public:
	/*
	���캯������һ�����Ŷ��󴴽����Զ������õĹ��г�Ա���������ҽ��ڶ������ʱ�Զ�ִ��һ�Σ��Զ�����г�ʼ��
	������
		1����������������ͬ
		2���޷���ֵ
		3�������죨����ʵ������ʱϵͳ�Զ����ö�Ӧ�Ĺ��캯��
		4�����캯����������
		5�����캯���������ڶ���Ҳ�������ⶨ����������
		6������ඨ��û�и������캯������ C++ �������Զ�����һ��Ĭ�ϵĹ���ĺ�������ֻҪ���Ƕ�����һ�����캯����ϵͳ�Ͳ����Զ�����Ĭ�ϵĹ��캯��
		7���޲εĹ��캯����ȫĬ��ֵ�Ĺ��캯������ΪʱĬ�Ϲ��캯����������ΪĬ�Ϲ��캯��ֻ����һ��
	*/
	Date(int year = 1900, int month = 1, int day = 1)		//���캯��
		: _year(year)
		, _month(month)
		, _day(day)
	{}
	void Display()		//��ӡ����
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

	/*
	�������캯������������ʱ��ʹͬ����������г�ʼ�������������캯��
	������
		1����ʵ���ǹ��캯����һ������
		2���������캯������ֻ��һ������ֻ��ʹ�����ô��Σ�ʹ�ô�ֵ���λ���������ݹ�

	����ݹ�Ĳ�����
		1������ĳ�Ա�����п���ֱ�ӷ���ͬ������˽�г�Ա
		2��C++ �ķ����޶�����������Ϊ��λ��Ҳ����˵�������λ�ڵĳ�Ա���Ի������

	*/
	Date(const Date& d)		//�������캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	/*
	��ĸ�ֵ����������
		1����һ���Ѿ����ڵĶ�����п�����ֵ
	*/
	Date& operator=(const Date& d)		//��ֵ��������������أ�
	{
		if (this != &d)
		{
			this->_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
		}
		return *this;
	}
	Date operator+(int days)
	{
		_day += days;
		while (_day > 30)
		{
			_day -= 30;
			_month += 1;
		}
		while (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		return *this;
	}
	Date operator+=(int days);
	Date operator-(int days);
	Date operator-=(int days);
	int operator-(const Date& d);
	Date& operator++()		//�����������
	{
		_day++;
		while (_day > 30)
		{
			_day -= 30;
			_month += 1;
		}
		while (_month > 12)
		{
			_month -= 12;
			_year += 1;
		}
		return *this;
	}
	Date operator++(int);
	Date& operator--()		//����Լ�����
	{
		_day --;
		while (_day < 1)
		{
			_day = 30;
			_month -= 1;
		}
		while (_month < 1)
		{
			_month = 12;
			_year -= 1;
		}
		return *this;
	}
	Date operator--(int);
	bool operator>(const Date& d)		//2018-1-1 > 1990-1-1
	{
		return _year > d._year
			|| (_year == d._year && _month > d._month)
			|| (_year == d._year && _month == d._month && _day > d._day);
	}
	bool operator>=(const Date& d)		//2018-10-10 >= 2018-9-10
	{
		if (_year >= d._year
			|| (_year == d._year && _month >= d._month)
			|| (_year == d._year && _month == d._month && _day >= d._day))
		{
			cout << "true" << endl;		//����������ӡ true 
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
	}
	bool operator<(const Date& d)
	{
		if (_year < d._year
			|| (_year == d._year && _month < d._month)
			|| (_year == d._year && _month == d._month && _day < d._day))
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
	}
	bool operator<=(const Date& d)
	{
		if (_year <= d._year
			|| (_year == d._year && _month <= d._month)
			|| (_year == d._year && _month == d._month && _day <= d._day))
		{
			cout << "true" << endl;
			return true;
		}
		else
		{
			cout << "false" << endl;
			return false;
		}
		
	}
	bool operator==(const Date& d)
	{
		return _year == d._year
			&& _month == d._month
			&& _day == d._day;
	}
	bool operator!=(const Date & d)
	{
		return _year != d._year
			|| _month != d._month
			|| _day != d._day;
	}
	/*
	������������һ��������������ڽ���ʱ��C++ ���������Զ�����һ����Ա����������������
	������
		1��������������		~����
		2���޲����޷���ֵ
		3��һ��������ֻ��һ����������
		4�������������ڽ���ʱ���Զ�������������
		������������ɾ�����󣬶��ǶԶ���ɾ��ǰ��һЩɾ������
	*/
	~Date()
	{}
private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day << endl;
}
void TestDate()
{
	Date date1;
	cout << date1 << endl;
	Date date2(2000, 1, 1);
	Date date3;
	Date date4 = date2;
	Date date5(1997, 1, 10);
	Date date6(1999, 1, 1);
	date4.Display();
	date5.Display();
	date5.operator++();
	date5.Display();
	date5.operator--();
	date5.Display();
	date5.operator<(date6);
	date2.operator>=(date1);
	date6.Display();
	date1.operator<(date2);
	date1.operator==(date2);
	date1.operator>=(date2);
	date5.operator<=(date6);
	date5.operator>=(date6);
	date1.Display();
	date2.Display();
	date2.operator+(80);
	date2.Display();
	date3.Display();
	date3.operator--();
	date3.Display();
	date3.operator<(date1);
	date5.operator<(date1);
	date4.Display();
	date4.operator++();
	date4.Display();
}
