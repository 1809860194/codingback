#include <iostream>

using namespace std;

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int DataType;

//�ڵ�ṹ��
typedef struct ListNode
{
	DataType m_Value;
	struct ListNode* m_pNext;
}ListNode;

void SListInit(ListNode* *p)
{
	assert(p != NULL);
	*p = nullptr;

}
static ListNode* CreatNode(DataType m_Value)
{
	ListNode* pNode = (ListNode *)malloc(sizeof(ListNode));
	pNode->m_Value = m_Value;
	pNode->m_pNext = NULL;
	return pNode;
}

void SListPushBack(ListNode* *p, DataType m_Value)
{
	ListNode* pNode = CreatNode(m_Value);/* ����ڵ㣬��ֵ�Ҳ��� */
	assert(p != NULL);//�����ַ��Ϊ��
	if (*p == NULL)/* ����Ϊ�� */
	{
		*p = pNode;
		return;
	}
	//�������е����һ���ڵ�
	//ListNode* pNode = CreatNode(m_Value);//����ڵ㣬��ֵ�Ҳ���
	ListNode* cur = *p;
	while (cur->m_pNext != NULL)
	{
		cur = cur->m_pNext;
	}
	cur->m_pNext = pNode;
}

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;
	if (pHead->m_pNext == nullptr)
		return pHead;
	ListNode* pCur = pHead->m_pNext;
	ListNode* pPrev = pHead;
	ListNode* pNext = pCur->m_pNext;
	while (pCur->m_pNext != nullptr)
	{
		pNext = pCur->m_pNext;//����������Ҫ�Ͽ���n��һ���ڵ�
		pCur->m_pNext = pPrev;//��ǰָ�����һ��ָ������ǰ��
		pPrev = pCur;//qǰ������ǰ��������ƶ�
		pCur = pNext;
	}
	pCur->m_pNext = pPrev;//���һ���ڵ�ָ������ǰ��
	pHead->m_pNext = nullptr;//���һ���ڵ����һ������� nullptrptr
	return pCur;
}

void SListPrint(ListNode* p)
{
	ListNode* cur = p;
	while (cur != NULL)
	{
		printf("%d ", cur->m_Value);
		cur = cur->m_pNext;
	}
	printf("\n");
}
void ReverseListTest()
{
	cout << ">>��ת����" << endl;
	ListNode* pHead;
	SListInit(&pHead);
	SListPushBack(&pHead, 1);
	SListPushBack(&pHead, 2);
	SListPushBack(&pHead, 3);
	SListPushBack(&pHead, 4);
	SListPushBack(&pHead, 5);
	SListPushBack(&pHead, 6);
	SListPushBack(&pHead, 7);
	SListPushBack(&pHead, 8);
	SListPushBack(&pHead, 9);
	//cout << "��תǰ������" << endl;
	SListPrint(pHead);
	//ReverseList(pHead);
	//cout << "��ת�������" << endl;
	SListPrint(ReverseList(pHead));

	//ReverseList(pHead);
	//SListPrint(pHead);
}
int main()
{
	ReverseListTest();
	//std::cout << "Hello world" << std::endl;
	return 0;
}
