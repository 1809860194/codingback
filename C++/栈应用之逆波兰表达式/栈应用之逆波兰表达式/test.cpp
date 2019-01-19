#include <iostream>

using namespace std;

#include <stack>
#include <assert.h>

enum Type
{
	OP_NUM,	//������
	OP_SYMBOL,	//������
	ADD,
	SUB,
	MUL,
	DIV,
};
struct Cell
{
	Type _type;
	int _value;
};

int CountRPN(Cell *rpn, size_t n)
{
	stack<int> s;
	for (size_t i = 0; i < n; i++)
	{
		if (rpn[i]._type == OP_NUM)//�ǲ�����  ��ջ
		{
			s.push(rpn[i]._value);
		}
		else//�����˲�����
		{
			int right = s.top(); //�Ҳ��������������֮����ջ
			s.pop();
			int left = s.top();//�������
			s.pop();
			switch (rpn[i]._value)//�������ĸ�����������ִ���ĸ����ѽ���ٷ���ջ��
			{
			case ADD:
				s.push(left + right);
				break;
			case SUB:
				s.push(left - right);
				break;
			case MUL:
				s.push(left * right);
				break;
			case DIV:
				s.push(left / right);
				break;
			}
		}
	}
	assert(s.size() == 1);//������ʱ��ջ��Ӧ��ֻ��һ�����ݣ�Ϊ���ս��
	return s.top();//����ջ�����ݣ����ս����
}
//12*(3+4)-6+8/2+2
int main()
{
	Cell RPN[] =
	{
		{ OP_NUM, 12 },
		{ OP_NUM, 3 },
		{ OP_NUM, 4 },
		{ OP_SYMBOL, ADD },
		{ OP_SYMBOL, MUL },
		{ OP_NUM, 6 },
		{ OP_SYMBOL, SUB },
		{ OP_NUM, 8 },
		{ OP_NUM, 2 },
		{ OP_SYMBOL, DIV },
		{ OP_SYMBOL, ADD },
		{ OP_NUM, 2 },
		{ OP_SYMBOL, ADD },

	};
	cout << sizeof(RPN) << " " << sizeof(Cell) << endl;
	cout << "�����" << CountRPN(RPN, sizeof(RPN) / sizeof(Cell)) << endl;
	return 0;
}