#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LinkStackTool.h"
#include "sort.h"

#include "LinkStackTool.c"


//�۰��������
void BInsertSort(int* a, int n) {
	int low, high, mid, i, j;

	//�ӵڶ������ݿ�ʼ����
	for (i = 1; i < n; i++) {

		//�����ǰ����������ݱ���ǰ�źõĴ�С��������һ�����ݻ���,���ò���
		if (a[i] > a[i - 1]) {
			continue;
		}

		//׼������
		else {
			int x = a[i];//��ǰ��ô����������

			//�������ֲ��ҵ����½�
			low = 0;//�½�
			high = i - 1;//�Ͻ�

			while (low <= high) {//��������� = , �����Ҫ +1 -1
				mid = (low + high) / 2;
				if (a[mid] > x) {
					high = mid - 1;//��������
				}
				else{
					low = mid + 1;//��������
				}
			}
			//���ֲ��ҽ���, ��ʱ mid ��ֵ���Ǵ������λ��

			for (j = i - 1; j >= low; j--) {//ÿһ��ѭ�� j ��ָ����ƶ���Ԫ��
				a[j + 1] = a[j];
			}
			a[low] = x;//��������Ԫ�ط��� mid λ��
		}
	}
}

//�鲢���򣨺ϲ����飩
void MergeArray(int* a, int begin, int mid, int end) {
	int leftArr[100005] = { 0 };
	int rightArr[100005] = { 0 };
	long long leftSize = mid - begin + 1;
	long long rightSize = end - mid;
	long long i, j, k;

	//��[begin, mid]���Ƶ���������
	for (i = 0; i < leftSize; i++) {
		leftArr[i] = a[begin + i];
	}
	//�����ڱ�ֵ(�����ѿյ���δ��ʱ, �� ���ᱻ������������)
	leftArr[i] = 2147483647;

	//��[mid + 1, end]���Ƶ���������
	for (j = 0; j < rightSize; j++) {
		rightArr[j] = a[mid + 1 + j];
	}
	//�����ڱ�ֵ(����δ�յ����ѿ�ʱ, �� ���ᱻ������������)
	rightArr[j] = 2147483647;

	i = j = 0;
	k = begin;
	while (i != leftSize || j != rightSize) {//�����Ҷ������ڱ�λ��ʱ����ѭ��
		if (leftArr[i] <= rightArr[j]) {
			a[k++] = leftArr[i++];
		}
		else {
			a[k++] = rightArr[j++];
		}
	}
}

//�鲢����
void MergeSort(int* a, int begin, int end) {//���մ���ĺ���, ����˼·ʱӦ���ȿ��˺���
	if (a == NULL || begin >= end) {//�ݹ����ֹ����
		return;
	}
	long long mid = (begin + end) / 2;//�зֵ�

	//�з�(����ע���е㲻Ҫ�ظ�ʹ��)
	MergeSort(a, begin, mid);//[begin, mid]
	MergeSort(a, mid + 1, end);//[mid + 1, end]

	//�鲢, �ǳ��ؼ��ĺ���
	MergeArray(a, begin, mid, end);
}

//���ڷ���
int Partition(int* a, int begin, int end) {
	int lo = begin;
	int hi = end - 1;
	int pivot = a[end];
	int temp;
	while (1) {
		while (a[lo] < pivot) {
			lo++;
		}
		while (a[hi] > pivot && hi >= begin) {//��Lomuto���������У�hi��Ӧ��С��begin
			hi--;
		}
		if (lo < hi) {
			temp = a[lo];
			a[lo] = a[hi];
			a[hi] = temp;
			lo++;
			hi--;
		}
		else {
			break;
		}
	}
	temp = a[lo];
	a[lo] = a[end];
	a[end] = temp;
	return lo;
}

//��������(�ݹ��)
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin >= end) {//�ݹ����ֹ����
		return;
	}
	int par = Partition(a, begin, end);//����
	QuickSort_Recursion(a, begin, par - 1);//������������
	QuickSort_Recursion(a, par + 1, end);//���Ҳ��������
}

//��������(�ǵݹ��)
void QuickSort(int* a, int size) {
	int begin = 0;
	int end = size - 1;

	//��ʼ����ջ
	LinkStack* s = NULL;
	InitLStack(&s);

	//��ʼ��������������ջ
	pushLStack(s, begin, end);

	while (s->count != 0) {//��ջΪ��ʱ�˳�ѭ��
		popLStack(s, &begin, &end);//��ջ��ȡ��һ��������Ŀ�ʼ�ͽ�����ʶ
		if (begin >= end) {//���������ֻ��һ��Ԫ�ػ򲻴���, ������
			continue;
		}
		else {
			int par = Partition(a, begin, end);//��������з���

			pushLStack(s, begin, par - 1);//�������ջ˳���Ƿ���Ӱ��?
			pushLStack(s, par + 1, end);//?
		}
	}
}

//��������
void CountSort(int* a, int size, int max) {
	int i;

	int* count = (int*)malloc(sizeof(int) * (max + 1));//ע������Ҫ max + 1
	
	//�����������ʼ��Ϊ0
	for (i = 0; i <= max; i++) {//ע������Ҫ��������max
		count[i] = 0;
	}

	//��ԭ������б���, ��count�����м���
	for (i = 0; i < size; i++) {
		count[a[i]]++;
	}

	//��count��������ۼ�
	for (i = 1; i <= max; i++) { //ע������Ҫmax + 1
		count[i] += count[i - 1];
	}

	//�Ӻ���ǰ����ԭ����, ����count���齫ԭ�����е�ÿһ�����ݷ�����ȷ��λ����
	int* temp = (int*)malloc(sizeof(int) * size);
	for (i = size - 1; i >= 0; i--) {
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	//�����������鸴�Ƶ�ԭ������
	for (i = 0; i < size; i++) {
		a[i] = temp[i];
	}

	free(count);
	free(temp);
}

//��ȡx�ĵ�dλ���� (����������, ��0��ʼ)
int getDigit(int x, int d) {
	return (x / (int)pow(10, d)) % 10;
}

//��������(����ĳһλ)
int CountSort2(int* a, int size, int digit) {
	int count[10] = { 0 };//��������
	int* temp = (int*)malloc(sizeof(int) * size);//�������
	int i;//ѭ������

	//����
	for (i = 0; i < size; i++) {
		int digitValue = getDigit(a[i], digit);
		count[digitValue]++;
	}

	//�ۼ�
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	//�����������
	for (i = size - 1; i >= 0; i--) {
		int digitValue = getDigit(a[i], digit);
		temp[count[digitValue] - 1] = a[i];
		count[digitValue]--;
	}

	//�����������ƻ�ԭ����
	for (i = 0; i < size; i++) {
		a[i] = temp[i];
	}

	//�ͷ��ڴ�
	free(temp);
}

//������������
void RadixCountSort(int* a, int size) {

	//��ȡ���������ֵ��λ��

	int max = a[0];
	int i;// ѭ������

	for (i = 0; i < size; i++) {
		if (max < a[i]) max = a[i];
	}

	int maxDigit = 0;
	while (max != 0) {
		max /= 10;
		maxDigit++;
	}

	//�����λ��ʼ����
	for (int digit = 0; digit < maxDigit; digit++) {
		CountSort2(a, size, digit);
	}
}

//��ɫ����
void ColorSort(int* a, int size) {
	int lo = 0;
	int hi = size - 1;
	int i = 0;
	int temp;
	while (i <= hi) {
		if (a[i] == 0) {
			temp = a[i];
			a[i] = a[lo];
			a[lo] = temp;
			lo++;
			i++;
		}
		else if (a[i] == 2) {
			temp = a[i];
			a[i] = a[hi];
			a[hi] = temp;
			hi--;
			//ע������iָ�벻������ƶ�
		}
		else {
			i++;
		}
	}
}
