#include <iostream>
using namespace std;

/*
��̬�ĸ���:ͬһ���������ڲ�ͬ�����������ͬ��Ч����ͨ����˵�������ĳ����Ϊ����ͬ��������ʱ�������ͬ״̬
���磬��Ʊ�����Ϊ��ѧ����ľ���ѧ��Ʊ����������ľ��ǳ���Ʊ


��̬�Ķ��弰ʵ��
��̬���ڲ�ͬ�̳й�ϵ�е������ȥ����ͬһ�����������˲�ͬ��Ϊ
�ڼ̳���ϵ�й��ɶ�̬�ı�Ҫ������
	1�����ú����Ķ��������ָ���������
	2�������õĺ������뻹���麯������������麯������д

	������ʲô���麯������ virtual �ؼ������ε���ĳ�Ա�������麯��
ʲô���麯����д��
	����������һ����������ȫ��ͬ���麯�������Ǿͳ�������麯����д�˻�����麯������ȫ��ͬ��ָ�������������б���������ֵ����

�麯����д�����⣺Э���麯����д�����⣺Э�� 
	�麯����д��һ�����⣺��д���麯���ķ���ֵ���Բ�ͬ�����Ǳ���ֱ��ǻ���ָ���������ָ����߻��� ���ú����������á�

����������д���麯������ virtual �ؼ���Ҳ���Թ�����д���������ǲ��淶��
������������д��
	�����е���������������麯������ô�������������������д�˻���������������������ǵĺ��������� ͬ��
	������Υ������д�Ĺ�����ʵ��Ȼ������������Ϊ�����������������������������⴦��
	����� ��������������ͳһ�����destructor����Ҳ˵���Ļ���������������д���麯��
C++ ���� override ���������ຯ��ǿ�������д�����û����д����뱨��
final ���λ�����麯�����ܱ���������д

��̬��ԭ��-�麯����
������������ɣ�
	1���Ƚ������е�������ݿ���һ�ݵ��������е������
	2�������������д��ĳ�������е��麯�������������Լ����麯�����ǻ����е��麯����
	3���������Լ������ӵ��麯�����������������е�����˳��һ�����ӵ��������������
	4���麯����ı��ʣ�����麯��ָ���ָ�����飬������������ŵ��� nullptr
	5��ֻ���麯���Ż�Ž����
	6���麯��ָ����������У��麯�������ڴ���Σ���������д�ŵ������ָ��
��̬����������

*/

class Person
{
public:
	virtual ~Person()
	{
		cout << "~Person" << endl;
	}
	virtual void BuyTicket()
	{
		cout << "��Ʊ-ȫ��" << endl;
	}
};

class Student : public Person
{
public:
	Student()
	{}
	virtual void BuyTicket()
	{
		cout << "��Ʊ-���" << endl;
	}
	virtual ~Student()
	{
		cout << "~Student" << endl;
	}
private:
};

void Func(Person& p)
{
	p.BuyTicket();
}

class A{};
class B : public A{};
class person
{
	virtual A* f()
	{
		return new A;
	}
};
class student : public person
{
public:
	virtual B* f()
	{
		return new B;
	}
};

class Car
{
public:
	virtual void Drive()
	{}
};

class Benz : public Car
{
public:
	//ocerride �����������麯��ǿ�������д�����û����д����뱨��
	virtual void Drive() override
	{
		cout << "Benz - ����" << endl;
	}
};

#if 0
class Carn
{
public:
	//final ���εĻ����麯�����ܱ���������д
	virtual void Driven() final
	{}
};

class Benzn : public Carn
{
public:
	//ocerride �����������麯��ǿ�������д�����û����д����뱨��
	virtual void Driven() 
	{
		cout << "Benzn - ����" << endl;
	}
};

#endif
class Base
{
public:
	//һ�������麯�����������ٺ���һ���麯����ָ�룬��Ϊ�麯���ĵ�ַҪ������������
	//�����г��� _b ��Ա������һ�� _vfptr ָ����ڶ����ǰ����ߺ��棨����ƽ̨�йأ�
	virtual void Func()
	{
		cout << "Func()" << endl;
	}
private:
	int _b = 1;
};

namespace Bit
{
	class Base
	{
	public:
		virtual void Func1()
		{
			cout << "Base::Func1" << endl;
		}
		virtual void Func2()
		{
			cout << "Base::Func2" << endl;
		}
		void Func3()
		{
			cout << "Base::Func3" << endl;
		}
	private:
		int _b = 1;
	};
	class Derive : public Base
	{
	public:
		virtual void Func1()
		{
			cout << "Derive::Func1()" << endl;
		}
		/*
		virtual void Func()
		{
			cout << "Derive::Func" << endl;
		}
		*/
	private:
		int _d = 2;//�����������Ҳ��һ�����ָ�룬_d �Ķ����������ֹ��ɣ�һ�����Ǹ���̳��µĳ�Ա
	};
}


namespace bit
{
	class Person
	{
	public:
		virtual void BuyTicket()
		{
			cout << "��Ʊ-ȫ��" << endl;
		}
	};


	class Student : public Person
	{
	public:
		virtual void BuyTicket()
		{
			cout << "��Ʊ-���" << endl;
		}
	};
	void Func(Person& p)
	{
		p.BuyTicket();
	}
}

int _main();
int __main();
int __main()
{
	bit::Person Mike;
	bit::Func(Mike);
	bit::Student Johson;
	bit::Func(Johson);
	return 0;
}
//��̬��̬�붯̬��̬
//1. ��̬���ֳ�Ϊǰ�ڰ�(���)���ڳ�������ڼ�ȷ���˳������Ϊ��Ҳ��Ϊ��̬��̬�����磺���� ���� 
//2. ��̬���ֳƺ��ڰ�(���)�����ڳ��������ڼ䣬���ݾ����õ�������ȷ������ľ�����Ϊ������ ����ĺ�����Ҳ��Ϊ��̬��
int _main()
{
	Person p;
	Student s;
	Func(p);
	Func(s);
	// ֻ��������Student������������д��Person������������
	//�����delete��������������������ܹ��ɶ� ̬�����ܱ�֤p1��p2ָ��Ķ�����ȷ�ĵ������������� 
	Person* p1 = new Person;
	Person* p2 = new Student;
	delete p1;
	delete p2;
	cout << sizeof(Base) << endl;
	Bit::Base b;
	Bit::Derive d;
	b.Func1();
	b.Func2();
	b.Func3();
	d.Func1();
	d.Func2();
	d.Func3();
	cout << "Bit::Base" << "->" << sizeof(Bit::Base) << endl;
	cout << "Bit::Derive" << "->" << sizeof(Bit::Derive) << endl;
	return 0;
}

/*
���̳��е��麯����

*/

namespace base
{
	class Base
	{
	public:
		virtual void func1()
		{
			cout << "Base::func1()" << endl;
		}
		virtual void func2()
		{
			cout << "Base::func2()" << endl;
		}
	private:
		int _a;
	};
	class Derive : public Base
	{
	public:
		virtual void func1()
		{
			cout << "Derive::func1()" << endl;
			//cout << "Derive::func2()" << endl;
			//cout << "Derive::func3()" << endl;
		}
		virtual void func2()
		{
			cout << "Derive::func2()" << endl;
		}
		virtual void func3()
		{
			cout << "Derive::func3()" << endl;
		}
	private:
		int _b;
	};
	typedef void(*VFPTR)();
	void PrintVTable(VFPTR vTable[])
	{
		//����ȡ�麯��ָ���ӡ�����á����þͿ��Կ���������ĸ�����

		cout << "����ַ" << vTable << endl;
		for (int i = 0; vTable[i] != nullptr; ++i)
		{
			printf("��%d���麯����ַ ��0x%x,->", i, vTable[i]);
			VFPTR f = vTable[i];
			f();
		}
		cout << endl;
	}

}

int main()
{
	base::Base b;
	base::Derive d;

	/*
	ȡ������ b d ͷ��ǰ�ĸ��ֽڣ���������ָ�룬ǰ������˵�����麯��������һ������麯��ָ���ָ�����飬
	�����������������һ�� nullptr
	1����ȡ�� b �ĵ�ַ����ǿת��һ�� int* ��ָ��
	2��Ȼ�������ȡֵ����ȡ���� b �����ͷ�ĸ��ֽڣ����ֵ����ָ������ָ��
	3����ǿת�� VFPTR*����Ϊ������һ����� VFPTR* ���͵�����
	4�����ָ�봫�ݸ� PrintVTable ���д�ӡ���
	*/
	base::VFPTR* vTableb = (base::VFPTR*)(*(int*)&b);   
	base::PrintVTable(vTableb);

	base::VFPTR* vTabled = (base::VFPTR*)(*(int*)&d); 
	base::PrintVTable(vTabled);

	return 0;
}