#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

int gQuickSort[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 6, 5, 5, 4, 4 };
/*
��Ŀ����������һ�����ֳ��ִ������������һ�룬���ҳ�������֣���������һ������Ϊ 9 ��
����{1��2��3��2��2��2��4��5��2}���������� 2 ������ 5 �Σ����������һ�룬������Ϊ 2
*/

int MoreThanHalfNum(int array[], int length)
{
	if (array == nullptr || length <= 0)
	{
		return 0;
	}
	int result = array[0];//���ؽ�� result ����ʼֵ�� array[0] ���г�ʼ��
	int i = 0;
	int times = 1;//��ʼֵ����һ�����ֳ��ִ���Ϊ 1
	for (i = 1; i < length; ++i)
	{
		if (times == 0)//ֻ�е����ִ���Ϊ 0 ʱ��result �Żḳ��ֵ
		{
			result = array[i];
			times = 1;
		}
		else if (result == array[i])//�������ֵ��������鵱�е�ֵ���ʱ times �Ż� ++
		{
			times++;
		}
		else
		{
			times--;
		}
	}
	return result;
}
void TestArray()
{
	//���޸����飬��������һ�������¼ÿ�����ָ������ֵĴ�����ǰ��������������Ҫ��
	int array[] = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
	int length = sizeof(array) / sizeof(array[0]);
	cout << MoreThanHalfNum(array, length) << setw(4) << endl;
}
//���ֲ��ң��۰���ң�
int Binary_search(int array[], int length, int key)
{
	int left = 0;
	int right = length - 1;
	int result = -1;
	while (left < right)
	{
		int mid = left + ((right - left) >> 1);
		if (array[mid]==key)
		{	
			result = key;
			break;
		}
		if (array[mid] < key)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return result;
}
void TestBinary_search()
{
	int array[] = { 1, 2, 3, 2, 2, 2, 4, 5, 2 };
	int length = sizeof(array) / sizeof(array[0]);
	cout << Binary_search(array, length, 3) << endl;
	cout << Binary_search(array, length, 7) << endl;
}

//�ж����ݵĺϷ���
bool g_bInputInvalid = false;
bool CheckInvalidArray(int array[], int length)
{
	g_bInputInvalid = false;
	if (array == NULL || length <= 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}
int get_middle(int array[], int start, int end);
//Ѱ�һ�׼���ֱ����ߺ��ұ߽�������
void quick_sort(int array[], int length, int start, int end)
{
	CheckInvalidArray(array, length);
	int middle;
	if (start >= end)
		return;
	middle = get_middle(array, start, end);
	quick_sort(array, length, start, middle - 1);
	quick_sort(array, length, middle + 1, end);
}
//��ȡ�м��׼��
int get_middle(int array[], int start, int end)
{
	int front = 0;
	int tail = end - start;
	int value = array[start];
	int length = end - start + 1;
	int loop = start + 1;

	while (loop <= end){
		if (array[loop] < value){
			gQuickSort[front] = array[loop];
			front++;
		}
		else{
			gQuickSort[tail] = array[loop];
			tail--;
		}

		loop++;
	}
	gQuickSort[front] = value;
	memmove(&array[start], gQuickSort, sizeof(int)* (length));
	return start + front;
}
//���ŵ���������
/*
1�������ж����ݵĺϷ���
2��Ѱ���м������ֱ����ߺ��ұ����ݽ�������
3�������м���
*/

void _quicksort(int array[], int length, int start, int end)
{
	int i, j;

	if (start < end)
	{
		i = start + 1;  // ��array[begin]��Ϊ��׼������˴�array[begin+1]��ʼ���׼���Ƚϣ�
		j = end;        // array[end]����������һλ
		while (i < j)
		{
			if (array[i] > array[start])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
			{
				swap(array[i], array[j]);  // ����������
				j--;
			}
			else
			{
				i++;  // �����������һλ���������׼���Ƚϡ�
			}
		}

		/* ����whileѭ����i = j��
		* ��ʱ���鱻�ָ����������  -->  array[begin+1] ~ array[i-1] < array[begin]
		*                           -->  array[i+1] ~ array[end] > array[begin]
		* ���ʱ������array�ֳ��������֣��ٽ�array[i]��array[begin]���бȽϣ�����array[i]��λ�á�
		* ���array[i]��array[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
		*/

		if (array[i] >= array[start])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
		{
			i--;
		}

		//swap(&array[begin], &array[i]);  // ����array[i]��array[begin]
		swap(array[i], array[start]);
		_quicksort(array, length, start, i);
		_quicksort(array, length, j, end);
	}