#include <iostream>
#include <string>
using namespace std;



class Person {
public:  
	void Print()
	{ 
		cout << "name:" << _name << endl;
		cout << "age:" << _age << endl;
	} 
protected:    
	string _name = "peter"; // ����   
	int _age = 18;  // ���� 
};
class Student : public Person
{
protected:    
	int _stuid; // ѧ�� 
}; 
class Teacher : public Person 
{
protected:  
	int _jobid; // ���� 
};

class Post
{
public:
	void Print()
	{
		cout << "_deptno:" << _deptno << endl;
		cout << _sex << _sex << endl;
	}
private:
	int _deptno = 110;
	string _sex = "��";
};
class Worker : public Post
{
public:
	Worker(string name)
		: _name(name)
	{}
	Worker()
	{}
	~Worker()
	{}
private:
	string _name;
};

class Emp : public Post
{
public:
	Emp(string name, int deptno)
		: _name(name)
		, _deptno(deptno)
	{}
	Emp()
	{}
	~Emp()
	{}
private:
	string _name;
	int _deptno;
};
int main()
{
	Student s;  
	Teacher t;
	s.Print();    
	t.Print();
	Emp e;
	Worker w;
	e.Print();
	w.Print();
	return 0;
}

