//����һ��¥������BuildingΪ���࣬���ڴ洢��ַ��¥��
//����סլ��House�̳�Building�������洢���ź����
//���⽨���칫����Office�̳�Building���洢�칫�����ƺ͵绰���롣
//����Ҫ��:����Ӧ�ó��򣬽���סլ�Ͱ칫�Ҷ������֮������й������ύ����

#include <iostream>
#include <String>
using namespace std;

class Building
{
private:
	string address;//��ַ
	string buildnum;//¥��
public:
	void setAdd(string);//���õ�ַ
	void setBui(string);//����¥��
	string getAdd();
	string getBui();
};

void Building::setAdd(string address)
{
	this->address = address;
}
void Building::setBui(string buildnum)
{
	this->buildnum = buildnum;
}
string Building::getAdd()
{
	return address;
}
string Building::getBui()
{
	return buildnum;
}

class House :public Building
{
private:
	string housenum;//����
	int area;//���
public:
	void setHou(string);//���÷���
	void setAre(int);//�������
	string getHou();
	int getAre();
};

void House::setHou(string housenum)
{
	this->housenum = housenum;
}
void House::setAre(int area)
{
	this->area = area;
}
string House::getHou()
{
	return housenum;
}
int House::getAre()
{
	return area;
}


class Office :public Building//�洢�칫�����ƺ͵绰����
{
private:
	string name;
	string number;
public:
	void setNam(string);//��������
	void setNum(string);//���õ绰
	string getNam();
	string getNum();
};

void Office::setNam(string name)
{
	this->name = name;
}
void Office::setNum(string number)
{
	this->number = number;
}
string Office::getNam()
{
	return name;
}
string Office::getNum()
{
	return number;
}

int main()
{
	House hou;
	hou.setAdd("������");
	hou.setAre(230);
	hou.setBui("3��¥");
	hou.setHou("504");
	cout << hou.getAdd() << hou.getAre() << hou.getHou() << hou.getBui() << endl;
	return 0;
}