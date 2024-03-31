#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort.h"
#include "LinkStackTool.h"
#include "file.h"

#include "sort.c"
//#include "LinkStackTool.c"
#include "file.c"

int max = 10000;//��������������ֵ

int arr10[10] = { 2,0,1,1,2,0,0,1,0,2 };//������ɫ�������ʾ

//���ڴ洢��������
int arr1[10000]; int size1 = 10000;
int arr2[50000]; int size2 = 50000;
int arr3[200000]; int size3 = 200000;
int arr4[100 * 100000]; int size4 = 100 * 100000;

int arr[100]; //arr4��С����

//���ڼ���ʱ��
clock_t start_time;
clock_t end_time;
double time_spent1;
double time_spent2;
double time_spent3;
double time_spent4;
double sum_time;

void makeMainMenu();//����������
void keyMainDown();//�����潻��

int main() {
	while (1) {
		makeMainMenu();
		keyMainDown();
		system("pause");
		system("cls");
	}
}

void makeMainMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.�۰��������\n");
	printf("\t\t2.�鲢����\n");
	printf("\t\t3.��������\n");
	printf("\t\t4.��������\n");
	printf("\t\t5.������������\n");
	printf("\t\t6.��ɫ����\n");
	printf("\t\t7.���ɲ�������(����ԭ����)\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

void keyMainDown() {
	char userMainKey = 0;

	//�����ж�
	while (1) {
		while (1) {
			userMainKey = getchar();
			if (userMainKey != ' ' && userMainKey != '\n') {
				break;
			}
		}

		//��ջ�����
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

		if ((userMainKey >= '0' && userMainKey <= '9') || (userMainKey == '#')) {
			break;
		}
		else {
			puts("������������ԣ�");
		}

	}

	switch (userMainKey) {//�����潻��
	case '1':
		system("cls");
		printf("������......\n");

		start_time = clock();
		BInsertSort(arr1, size1);
		end_time = clock();
		time_spent1 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		BInsertSort(arr2, size2);
		end_time = clock();
		time_spent2 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;
		
		start_time = clock();
		BInsertSort(arr3, size3);
		end_time = clock();
		time_spent3 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		sum_time = 0;
		for (int i = 0; i < 100000; i++) {
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr[k] = arr4[j];
			}
			start_time = clock();
			BInsertSort(arr, 100);
			end_time = clock();
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr4[j] = arr[k];
			}
			sum_time = sum_time + (end_time - start_time);
		}
		time_spent4 = (double)(sum_time) / CLOCKS_PER_SEC * 1000;

		printf("\n");
		printf("BInsertSortd��10000����������ִ��ʱ��Ϊ: %f ����\n", time_spent1);
		printf("BInsertSort��50000����������ִ��ʱ��Ϊ: %f ����\n", time_spent2);
		printf("BInsertSort��200000����������ִ��ʱ��Ϊ: %f ����\n", time_spent3);
		printf("BInsertSort��100�����ݽ���100000��������ִ��ʱ��Ϊ: %f ����\n", time_spent4);

		writeText(arr1, size1, "text1.txt");
		writeText(arr2, size2, "text2.txt");
		writeText(arr3, size3, "text3.txt");
		writeText(arr4, size4, "text4.txt");

		break;
	case '2':
		system("cls");
		printf("������......\n");

		start_time = clock();
		MergeSort(arr1, 0, size1 - 1);
		end_time = clock();
		time_spent1 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		MergeSort(arr2, 0, size2 - 1);
		end_time = clock();
		time_spent2 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		MergeSort(arr3, 0, size3 - 1);
		end_time = clock();
		time_spent3 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		printf("\n");
		printf("MergeSort��10000����������ִ��ʱ��Ϊ: %f ����\n", time_spent1);
		printf("MergeSort��50000����������ִ��ʱ��Ϊ: %f ����\n", time_spent2);
		printf("MergeSort��200000����������ִ��ʱ��Ϊ: %f ����\n", time_spent3);
		printf("MergeSort��100�����ݽ���100000��������ִ��ʱ��Ԥ��Ҫ�ر��......\n");

		start_time = clock();
		for (int i = 0, j = 0; i < 100000; i++, j = j + 100) {
			MergeSort(arr4, j, j + 99);
			if (i % 1000 == 0) {
				printf("���ڽ��е�%d������\n", i);
			}
		}
		end_time = clock();
		time_spent4 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;


		printf("MergeSort��100�����ݽ���100000��������ִ��ʱ��Ϊ: %f ����\n", time_spent4);

		writeText(arr1, size1, "text1.txt");
		writeText(arr2, size2, "text2.txt");
		writeText(arr3, size3, "text3.txt");
		writeText(arr4, size4, "text4.txt");

		break;
	case '3':
		system("cls");
		printf("������......\n");


		start_time = clock();
		QuickSort_Recursion(arr1, 0, size1 - 1);
		end_time = clock();
		time_spent1 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		QuickSort_Recursion(arr2, 0, size2 - 1);
		end_time = clock();
		time_spent2 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		QuickSort_Recursion(arr3, 0, size3 - 1);
		end_time = clock();
		time_spent3 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		for (int i = 0, j = 0; i < 100000; i++, j = j + 100) {
			QuickSort_Recursion(arr4, j, j + 99);
		}
		end_time = clock();
		time_spent4 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		printf("\n");
		printf("QuickSort_Recursion��10000����������ִ��ʱ��Ϊ: %f ����\n", time_spent1);
		printf("QuickSort_Recursion��50000����������ִ��ʱ��Ϊ: %f ����\n", time_spent2);
		printf("QuickSort_Recursion��200000����������ִ��ʱ��Ϊ: %f ����\n", time_spent3);
		printf("QuickSort_Recursion��100�����ݽ���100000��������ִ��ʱ��Ϊ: %f ����\n", time_spent4);

		writeText(arr1, size1, "text1.txt");
		writeText(arr2, size2, "text2.txt");
		writeText(arr3, size3, "text3.txt");
		writeText(arr4, size4, "text4.txt");

		//�ǵݹ�汾��bug
		//QuickSort(arr1, 10);
		//for (int i = 0; i < size1; i++) {
		//	printf("%d ", arr1[i]);
		//}

		break;
	case '4':
		system("cls");
		printf("������......\n");

		start_time = clock();
		CountSort(arr1, size1, max);
		end_time = clock();
		time_spent1 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;


		start_time = clock();
		CountSort(arr2, size2, max);
		end_time = clock();
		time_spent2 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		CountSort(arr3, size3, max);
		end_time = clock();
		time_spent3 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		sum_time = 0;
		for (int i = 0; i < 100000; i++) {
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr[k] = arr4[j];
			}
			start_time = clock();
			CountSort(arr, 100, max);
			end_time = clock();
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr4[j] = arr[k];
			}
			sum_time = sum_time + (end_time - start_time);
		}
		time_spent4 = (double)(sum_time) / CLOCKS_PER_SEC * 1000;

		printf("\n");
		printf("CountSort��10000����������ִ��ʱ��Ϊ: %f ����\n", time_spent1);
		printf("CountSort��50000����������ִ��ʱ��Ϊ: %f ����\n", time_spent2);
		printf("CountSort��200000����������ִ��ʱ��Ϊ: %f ����\n", time_spent3);
		printf("CountSort��100�����ݽ���100000��������ִ��ʱ��Ϊ: %f ����\n", time_spent4);

		writeText(arr1, size1, "text1.txt");
		writeText(arr2, size2, "text2.txt");
		writeText(arr3, size3, "text3.txt");
		writeText(arr4, size4, "text4.txt");

		break;
	case '5':
		system("cls");
		printf("������......\n");

		start_time = clock();
		RadixCountSort(arr1, size1);
		end_time = clock();
		time_spent1 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		RadixCountSort(arr2, size2);
		end_time = clock();
		time_spent2 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		start_time = clock();
		RadixCountSort(arr3, size3);
		end_time = clock();
		time_spent3 = (double)(end_time - start_time) / CLOCKS_PER_SEC * 1000;

		sum_time = 0;
		for (int i = 0; i < 100000; i++) {
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr[k] = arr4[j];
			}
			start_time = clock();
			RadixCountSort(arr, 100);
			end_time = clock();
			for (int j = i * 100, k = 0; j < i * 100 + 100; j++, k++) {
				arr4[j] = arr[k];
			}
			sum_time = sum_time + (end_time - start_time);
		}
		time_spent4 = (double)(sum_time) / CLOCKS_PER_SEC * 1000;

		printf("\n");
		printf("RadixCountSort��10000����������ִ��ʱ��Ϊ: %f ����\n", time_spent1);
		printf("RadixCountSort��50000����������ִ��ʱ��Ϊ: %f ����\n", time_spent2);
		printf("RadixCountSort��200000����������ִ��ʱ��Ϊ: % f ����\n", time_spent3);
		printf("RadixCountSort��100�����ݽ���100000��������ִ��ʱ��Ϊ: %f ����\n", time_spent4);

		writeText(arr1, size1, "text1.txt");
		writeText(arr2, size2, "text2.txt");
		writeText(arr3, size3, "text3.txt");
		writeText(arr4, size4, "text4.txt");

		break;
	case '6':
		system("cls");
		printf("������......\n");

		printf("ԭ����: ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr10[i]);
		}
		printf("\n");

		ColorSort(arr10, 10);
		printf("����������: ");
		for (int i = 0; i < 10; i++) {
			printf("%d ", arr10[i]);
		}
		printf("\n");

		break;
	case '7':
		system("cls");

		generateText(10000, 10000, "text1.txt");
		generateText(50000, 10000, "text2.txt");
		generateText(200000, 10000, "text3.txt");
		generateText(100*100000, 10000, "text4.txt");

		readText(arr1, 10000, "text1.txt");
		readText(arr2, 50000, "text2.txt");
		readText(arr3, 200000, "text3.txt");
		readText(arr4, 100*100000, "text4.txt");

		break;
	case '0':
		printf("�˳��ɹ���");
		system("pause");
		exit(0);
		break;
	default:
		printf("��ҳ��������������ԣ�");
		system("pause");
		system("cls");
	}
}
