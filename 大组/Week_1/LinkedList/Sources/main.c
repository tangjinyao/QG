#include <stdio.h>
#include <stdlib.h>

#include "linkedList.h"

#include "func.c" 

LNode* list;//����һ������
Status result;//��¼��������ֵ
ElemType elem;//p�ڵ��ֵ

void makeMainMenu();//����������
void keyMainDown();//�����潻��

void Visit(ElemType e) {
	printf("%d -> ", e);
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
	printf("\t\t3.����Ԫ��\n");
	printf("\t\t4.ɾ��Ԫ�ز����ɾ���Ľڵ�ֵ\n");
	printf("\t\t5.��������\n");
	printf("\t\t6.��ѯԪ��\n");
	printf("\t\t7.��ת����\n");
	printf("\t\t8.�ж������Ƿ�ɻ�\n");
	printf("\t\t9.�������������е�Ԫ��\n");
	printf("\t\t0.Ѱ���м�ڵ�\n");
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
		if ((userMainKey >= '0' && userMainKey <= '9')||(userMainKey == '#')) {
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

		//�������ʼ��Ϊ  0->1->2->3->4->5->6->7->8->9
		for (int i = 0; i < 10; i++) {
			LNode* p2 = (LNode*)malloc(sizeof(LNode));
			p2->data = i;
			p2->next = NULL;
			p1->next = p2;
			p1 = p2;
		}

		printf("�����ʼ���ɹ�! (�������ʼ��Ϊ  0->1->2->3->4->5->6->7->8->9)\n");
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

		printf("��p�ڵ�������һ��q�ڵ�\n");
		printf("������p�ڵ��ֵ:\n");
		scanf("%d", &elem);
		printf("������q�ڵ��ֵ:\n");
		scanf("%d", &q->data);
		result = InsertList(list, elem, q);
		if (result == SUCCESS) {
			printf("����ɹ�!\n");
		}
		else {
			printf("�Ҳ�������������p�ڵ�!\n");
		}
		break;
	case '4':
		system("cls");

		ElemType* e;//�洢ɾ���Ľڵ��ֵ

		printf("ɾ��p�ڵ�ĺ�һ���ڵ�,������ֵ����e\n");
		printf("������p�ڵ��ֵ:\n");
		scanf("%d", &elem);
		DeleteList(list, elem, e);
		printf("ɾ���ɹ�! ɾ����ֵΪ:%d", *e);
		break;
	case '5':
		system("cls");
		TraverseList(list, visit);
		break;
	case '6':
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
	case '7':
		system("cls");
		ReverseList(&list);
		break;
	case '8':
		system("cls");
		result = IsLoopList(list);
		if (result == SUCCESS) {
			printf("������ɻ�\n");
		}
		else {
			printf("�������ɻ�\n");
		}
		break;
	case '9':
		system("cls");
		ReverseEvenList(&list);
		break;
	case '0':
		system("cls");
		LNode* p;
		p = FindMidNode(&list);
		if (p == NULL) {
			printf("���������ڻ�Ϊ��\n");
		}
		else {
			printf("��������м�ڵ�Ϊ:%d\n", p->data);
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



