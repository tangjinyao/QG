#include <stdio.h>
#include <stdlib.h>

#include "DbLinkedList.h"
#include "func.c"

//#include "func.c" 

LNode* list;//����һ������
Status result;//��¼��������ֵ
ElemType elem;//p�ڵ��ֵ

void makeMainMenu();//����������
void keyMainDown();//�����潻��

void Visit(ElemType e) {
	printf("%d  ", e);
}
void (*visit)(ElemType e) = Visit;

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
	printf("\t\t2.������������\n");
	printf("\t\t3.��p�ڵ�ǰ�����һ��q�ڵ�\n");
	printf("\t\t4.��p�ڵ�������һ��q�ڵ�\n");
	printf("\t\t5.ɾ��Ԫ�ز����ɾ���Ľڵ�ֵ\n");
	printf("\t\t6.��������\n");
	printf("\t\t7.��ѯԪ��\n");
	printf("\t\t#.�˳�ϵͳ\n");
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
		getchar();
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
		InitList(&list);//��ʼ������(һ��ͷ���)
		LNode* p1 = list;

		//�������ʼ��Ϊ  0<->1<->2<->3<->4<->5<->6<->7<->8<->9
		for (int i = 0; i < 10; i++) {
			LNode* p2 = (LNode*)malloc(sizeof(LNode));
			p2->data = i;
			p2->pre = NULL;
			p2->next = NULL;
			p1->next = p2;
			p2->pre = p1;
			p1 = p2;
		}

		printf("�����ʼ���ɹ�! (�������ʼ��Ϊ  0<->1<->2<->3<->4<->5<->6<->7<->8<->9)\n");
		break;
	case '2':
		system("cls");
		DestroyList(&list);//��������
		printf("���ٳɹ�!\n");
		break;
	case '3':
		system("cls");

		LNode* q;//Ҫ�����q�ڵ�
		q = (LNode*)malloc(sizeof(LNode));

		printf("��p�ڵ�ǰ�����һ��q�ڵ�\n");
		printf("������p�ڵ��ֵ:\n");
		scanf("%d", &elem);
		printf("������q�ڵ��ֵ:\n");
		scanf("%d", &q->data);
		result = insertBeforeNode(list, elem, q);
		if (result == SUCCESS) {
			printf("����ɹ�!\n");
		}
		else {
			printf("�Ҳ�������������p�ڵ�!\n");
		}
		break;
	case '4':
		system("cls");

		//LNode* q;//Ҫ�����q�ڵ�
		q = (LNode*)malloc(sizeof(LNode));

		printf("��p�ڵ�������һ��q�ڵ�\n");
		printf("������p�ڵ��ֵ:\n");
		scanf("%d", &elem);
		printf("������q�ڵ��ֵ:\n");
		scanf("%d", &q->data);
		result = insertAfterNode(list, elem, q);
		if (result == SUCCESS) {
			printf("����ɹ�!\n");
		}
		else {
			printf("�Ҳ�������������p�ڵ�!\n");
		}
		break;
	case '5':
		system("cls");

		printf("������Ҫɾ���Ľڵ��ֵ:\n");
		scanf("%d", &elem);
		result = DeleteList(list, elem);
		if (result == SUCCESS) {
			printf("ɾ���ɹ�!\n");
		}
		else {
			printf("ɾ��ʧ��\n");
		}
		break;
	case '6':
		system("cls");
		TraverseList(list, visit);
		break;
	case '7':
		system("cls");
		ElemType e1;
		printf("������Ҫ���ҵ�Ԫ��:\n");
		scanf("%d", &e1);

		result = SearchList(list, e1);
		if (result == SUCCESS) {
			printf("��������\n");
		}
		else {
			printf("����������\n");
		}
		break;
	case '#':
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


