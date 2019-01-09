#include <iostream>
#include <string>
using namespace std;



//�̳У����븴�ã��ڱ���ԭ�����͵Ļ����Ͻ�����չ�������¹���
//�̳г�����������������Ʋ�νṹ���������ɼ򵥵����ӵ���֪���̣��̳�������Ʋ�εĸ���
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

#if 0
//�̳к����Person�ĳ�Ա�����������һ����
//�������ֳ���Student�� Teacher������Person�ĳ�Ա
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

#endif

//�̳ж���
//class Empno : public Person
//���� Person �Ǹ���Ҳ�ƻ��࣬Empno ������Ҳ��������
//�̳з�ʽ��public��private��protected ����


class Empno : public Person
{
public:
	Empno(int no)
		:_no(no)
	{}
	~Empno()
	{}
private:
	int _no;
};

/*
+----------------------+--------------------------+--------------------------+-----------------------+
| ���Ա/�̳з�ʽ	   |		public �̳�		  |		protected �̳�		 |		private �̳�     |
+----------------------+--------------------------+--------------------------+-----------------------+
|����� public ��Ա	   |   ������� public ��Ա	  |  ������� protected ��Ա |	������� private ��Ա|
+----------------------+--------------------------+--------------------------+-----------------------+
|����� protected ��Ա |   ������� protected ��Ա|	 ������� protected ��Ա |	������� private ��Ա|
+----------------------+--------------------------+--------------------------+-----------------------+
|���۵� private ��Ա   |      �������в��ɼ�	  |		  �������в��ɼ�     |        �������в��ɼ�  |
+----------------------+--------------------------+--------------------------+-----------------------+
*/

//�ܶ���֮������� private ��Ա����������������ʲô��ʽ�̳ж��ǲ��ɼ���
class Student : public Person
{
protected: 
	int _stunum; // ѧ�� 
};
//Student �̳��� Person �Ϳ�����Ϊ��Student �������� Person �ĳ�Ա����Ա����
//�̳���������ݻ������ʵ���������������ʵ�֡�
//�ڼ̳з�ʽ�У�������ڲ�ϸ�ڶ�����ɼ� ��
//�̳�һ���̶��ƻ��˻���ķ�װ������ĸı䣬�����������кܴ��Ӱ�졣������ͻ�����������ϵ��ǿ����϶ȸ�

//��������������ֵת��
//�����������Ը�ֵ������Ķ���/�����ָ��/���������
//�����и������˵������Ƭ������ �Ԣ����������и����ǲ���������ֵ��ȥ
//��������ܸ�ֵ����������� �����ָ�����ͨ��ǿ������ת����ֵ���������ָ��
//���Ǳ����ǻ����ָ����ָ�����������ʱ�� �ǰ�ȫ�ġ������������Ƕ�̬����

class Person
{
protected:
	string _name; // ���� 
	string _sex;  // �Ա� 
	int _age;    // ����
};
class Student : public Person
{
public:
	int _No; // ѧ�� 
};
void Test ()
{
	Student sobj ;
	// 1.���������Ը�ֵ���������/ָ��/����    
	Person pobj = sobj ; 
	Person* pp = &sobj;
	Person& rp = sobj;    
	//2.��������ܸ�ֵ�����������    
	//sobj = pobj;				-------------����
	// 3.�����ָ�����ͨ��ǿ������ת����ֵ���������ָ��    
	pp = &sobj;
	Student* ps1 = (Student*)pp; // �������ת��ʱ���Եġ�  
	ps1->_No = 10;    
	pp = &pobj; 
	Student* ps2 = (Student*)pp; // �������ת��ʱ��Ȼ���ԣ����ǻ����Խ����ʵ�����   
	ps2->_No = 10;
}

//�̳��е�������