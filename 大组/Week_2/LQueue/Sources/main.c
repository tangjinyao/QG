#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"
#include "LQueue.c" 

LQueue* Q = NULL;//����һ���ṹ��洢���е���Ϣ
Status result;//��¼��������ֵ
void* elem;//p�ڵ��ֵ
int length;
int* pl = &length;

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
	printf("\t\t1.��ʼ������\n");
	printf("\t\t2.�ж϶����Ƿ�Ϊ��\n");
	printf("\t\t3.�鿴��ͷԪ��\n");
	printf("\t\t4.��ն���\n");
	printf("\t\t5.���ٶ���\n");
	printf("\t\t6.�����г���\n");
	printf("\t\t7.���\n");
	printf("\t\t8.����\n");
	printf("\t\t9.��������\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

void keyMainDown() {
	char userMainKey = 0;
	char userKey2 = 0;

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
		InitLQueue(&Q);//��ʼ��ջ(һ��ͷ���)

		//�����г�ʼ��Ϊ  <-��ͷ 0 1 2 3 4 5 6 7 8 9 ��β<-
		for (int i = 0; i <10; i++) {
			EnLQueue(Q, i);
		}

		printf("���г�ʼ���ɹ�!(�����г�ʼ��Ϊ  <-��ͷ 0 1 2 3 4 5 6 7 8 9 ��β<-)\n");
		break;
	case '2':
		system("cls");

		result = IsEmptyLQueue(Q);
		if (result == TRUE) {
			printf("����Ϊ��\n");
		}

		break;
	case '3':
		system("cls");

		result = GetHeadLQueue(Q, &elem);
		if (result == TRUE) {
			printf("��ͷԪ�ص�ֵΪ: %d\n", elem);
		}

		break;
	case '4':
		system("cls");

		result = ClearLQueue(Q);
		if (result == TRUE) {
			printf("��ն��гɹ�!\n");
		}

		break;
	case '5':
		system("cls");

		result = DestoryLQueue(&Q);//����ջ
		if (result == TRUE) {
			printf("���ٳɹ�!\n");
		}

		break;
	case '6':
		system("cls");

		length = LengthLQueue(Q);
		if (length != -1) {
			printf("���еĳ���Ϊ: %d\n", length);
		}

		break;
	case '7':
		system("cls");

		if (Q == NULL) {
			printf("���в�����!\n");
			break;
		}

		printf("������ ��ӽڵ� ��ֵ(-999 - 999 ��Χ�ڵ�����):\n");
		scanf("%d", &elem);

		result = EnLQueue(Q, elem);
		if (result == TRUE) {
			printf("��ӳɹ�!\n");
		}

		break;
	case '8':
		system("cls");

		result = DeLQueue(Q, &elem);
		if (result == TRUE) {
			printf("���ӳɹ�, ����Ԫ�ص�ֵΪ: %d\n", elem);
		}

		break;
	case '9':
		system("cls");

		TraverseLQueue(Q, LPrint);


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



