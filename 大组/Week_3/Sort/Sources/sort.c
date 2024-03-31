#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "LinkStackTool.h"
#include "sort.h"

#include "LinkStackTool.c"


//折半插入排序
void BInsertSort(int* a, int n) {
	int low, high, mid, i, j;

	//从第二个数据开始排序
	for (i = 1; i < n; i++) {

		//如果当前待排序的数据比先前排好的从小到大的最后一个数据还大,则不用插入
		if (a[i] > a[i - 1]) {
			continue;
		}

		//准备插入
		else {
			int x = a[i];//提前存好待插入的数据

			//声明二分查找的上下界
			low = 0;//下界
			high = i - 1;//上界

			while (low <= high) {//这里包含了 = , 下面就要 +1 -1
				mid = (low + high) / 2;
				if (a[mid] > x) {
					high = mid - 1;//就是这里
				}
				else{
					low = mid + 1;//就是这里
				}
			}
			//二分查找结束, 此时 mid 的值就是待插入的位置

			for (j = i - 1; j >= low; j--) {//每一次循环 j 都指向待移动的元素
				a[j + 1] = a[j];
			}
			a[low] = x;//将待插入元素放在 mid 位置
		}
	}
}

//归并排序（合并数组）
void MergeArray(int* a, int begin, int mid, int end) {
	int leftArr[100005] = { 0 };
	int rightArr[100005] = { 0 };
	long long leftSize = mid - begin + 1;
	long long rightSize = end - mid;
	long long i, j, k;

	//将[begin, mid]复制到左数组中
	for (i = 0; i < leftSize; i++) {
		leftArr[i] = a[begin + i];
	}
	//设置哨兵值(当左已空但右未空时, 左 不会被放入主数组中)
	leftArr[i] = 2147483647;

	//将[mid + 1, end]复制到右数组中
	for (j = 0; j < rightSize; j++) {
		rightArr[j] = a[mid + 1 + j];
	}
	//设置哨兵值(当左未空但右已空时, 右 不会被放入主数组中)
	rightArr[j] = 2147483647;

	i = j = 0;
	k = begin;
	while (i != leftSize || j != rightSize) {//当左右都到达哨兵位置时结束循环
		if (leftArr[i] <= rightArr[j]) {
			a[k++] = leftArr[i++];
		}
		else {
			a[k++] = rightArr[j++];
		}
	}
}

//归并排序
void MergeSort(int* a, int begin, int end) {//最终处理的函数, 整理思路时应首先看此函数
	if (a == NULL || begin >= end) {//递归的终止条件
		return;
	}
	long long mid = (begin + end) / 2;//切分点

	//切分(尤其注意切点不要重复使用)
	MergeSort(a, begin, mid);//[begin, mid]
	MergeSort(a, mid + 1, end);//[mid + 1, end]

	//归并, 非常关键的函数
	MergeArray(a, begin, mid, end);
}

//用于分组
int Partition(int* a, int begin, int end) {
	int lo = begin;
	int hi = end - 1;
	int pivot = a[end];
	int temp;
	while (1) {
		while (a[lo] < pivot) {
			lo++;
		}
		while (a[hi] > pivot && hi >= begin) {//在Lomuto分区方案中，hi不应该小于begin
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

//快速排序(递归版)
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin >= end) {//递归的终止条件
		return;
	}
	int par = Partition(a, begin, end);//分组
	QuickSort_Recursion(a, begin, par - 1);//对左侧进行排序
	QuickSort_Recursion(a, par + 1, end);//对右侧进行排序
}

//快速排序(非递归版)
void QuickSort(int* a, int size) {
	int begin = 0;
	int end = size - 1;

	//初始化链栈
	LinkStack* s = NULL;
	InitLStack(&s);

	//初始的整体数组先入栈
	pushLStack(s, begin, end);

	while (s->count != 0) {//当栈为空时退出循环
		popLStack(s, &begin, &end);//从栈顶取出一组子数组的开始和结束标识
		if (begin >= end) {//如果子数组只有一个元素或不存在, 则跳过
			continue;
		}
		else {
			int par = Partition(a, begin, end);//对数组进行分组

			pushLStack(s, begin, par - 1);//这里的入栈顺序是否有影响?
			pushLStack(s, par + 1, end);//?
		}
	}
}

//计数排序
void CountSort(int* a, int size, int max) {
	int i;

	int* count = (int*)malloc(sizeof(int) * (max + 1));//注意这里要 max + 1
	
	//将计数数组初始化为0
	for (i = 0; i <= max; i++) {//注意这里要包含等于max
		count[i] = 0;
	}

	//对原数组进行遍历, 在count数组中计数
	for (i = 0; i < size; i++) {
		count[a[i]]++;
	}

	//对count数组进行累加
	for (i = 1; i <= max; i++) { //注意这里要max + 1
		count[i] += count[i - 1];
	}

	//从后往前遍历原数组, 根据count数组将原数组中的每一个数据放在正确的位置上
	int* temp = (int*)malloc(sizeof(int) * size);
	for (i = size - 1; i >= 0; i--) {
		temp[count[a[i]] - 1] = a[i];
		count[a[i]]--;
	}

	//将排序后的数组复制到原数组中
	for (i = 0; i < size; i++) {
		a[i] = temp[i];
	}

	free(count);
	free(temp);
}

//获取x的第d位数字 (从右往左数, 从0开始)
int getDigit(int x, int d) {
	return (x / (int)pow(10, d)) % 10;
}

//计数排序(依据某一位)
int CountSort2(int* a, int size, int digit) {
	int count[10] = { 0 };//计数数组
	int* temp = (int*)malloc(sizeof(int) * size);//结果数组
	int i;//循环变量

	//计数
	for (i = 0; i < size; i++) {
		int digitValue = getDigit(a[i], digit);
		count[digitValue]++;
	}

	//累加
	for (i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	//构建输出数组
	for (i = size - 1; i >= 0; i--) {
		int digitValue = getDigit(a[i], digit);
		temp[count[digitValue] - 1] = a[i];
		count[digitValue]--;
	}

	//将排序结果复制回原数组
	for (i = 0; i < size; i++) {
		a[i] = temp[i];
	}

	//释放内存
	free(temp);
}

//基数计数排序
void RadixCountSort(int* a, int size) {

	//获取数组中最大值的位数

	int max = a[0];
	int i;// 循环变量

	for (i = 0; i < size; i++) {
		if (max < a[i]) max = a[i];
	}

	int maxDigit = 0;
	while (max != 0) {
		max /= 10;
		maxDigit++;
	}

	//从最低位开始排序
	for (int digit = 0; digit < maxDigit; digit++) {
		CountSort2(a, size, digit);
	}
}

//颜色排序
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
			//注意这里i指针不用向后移动
		}
		else {
			i++;
		}
	}
}
