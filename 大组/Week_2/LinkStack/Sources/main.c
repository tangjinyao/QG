#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"
#include "LinkStack.c" 

LinkStack* s = NULL;//����һ���ṹ��洢ջ����Ϣ
Status result;//��¼��������ֵ
ElemType elem;//p�ڵ��ֵ
ElemType* e = &elem;//�洢Ԫ��ֵ��ָ��
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
	printf("\t\t1.��ʼ��ջ\n");
	printf("\t\t2.�ж�ջ�Ƿ�Ϊ��\n");
	printf("\t\t3.��ȡջ��Ԫ��\n");
	printf("\t\t4.���ջ\n");
	printf("\t\t5.����ջ\n");
	printf("\t\t6.���ջ����\n");
	printf("\t\t7.��ջ\n");
	printf("\t\t8.��ջ\n");
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
		InitLStack(&s);//��ʼ��ջ(һ��ͷ���)

		//��ջ��ʼ��Ϊ  ջ��-> 0 1 2 3 4 5 6 7 8 9 ջ��|
		for (int i = 9; i >= 0; i--) {
			pushLStack(s, i);
		}

		printf("ջ��ʼ���ɹ�!(��ջ��ʼ��Ϊ  ջ��-> 0 1 2 3 4 5 6 7 8 9 |)\n");
		break;
	case '2':
		system("cls");

		result = isEmptyLStack(s);
		if (result == SUCCESS) {
			printf("ջΪ��\n");
		}
		
		break;
	case '3':
		system("cls");

		result = getTopLStack(s, e);
		if (result == SUCCESS) {
			printf("ջ��Ԫ�ص�ֵΪ: %d\n", *e);
		}

		break;
	case '4':
		system("cls");

		result = clearLStack(s);
		if (result == SUCCESS) {
			printf("���ջ�ɹ�!\n");
		}

		break;
	case '5':
		system("cls");

		result = destroyLStack(&s);//����ջ
		if (result == SUCCESS) {
			printf("���ٳɹ�!\n");
		}

		break;
	case '6':
		system("cls");

		result = LStackLength(s, pl);
		if (result == SUCCESS) {
			printf("ջ�ĳ���Ϊ: %d\n", *pl);
		}

		break;
	case '7':
		system("cls");

		if (s == NULL) {
			printf("ջ������!\n");
			break;
		}

		printf("��������ջp�ڵ��ֵ(-999 - 999 ��Χ�ڵ�����):\n");
		scanf("%d", &elem);

		result = pushLStack(s, elem);
		if (result == SUCCESS) {
			printf("��ջ�ɹ�!\n");
		}

		break;
	case '8':
		system("cls");

		result = popLStack(s, e);
		if (result == SUCCESS) {
			printf("��ջ�ɹ�, ��ջԪ�ص�ֵΪ: %d\n", *e);
		}

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



