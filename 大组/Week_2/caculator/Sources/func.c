#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

Status InitLStack(LinkStack** s) {//ע�� LinkStackPtr �������һ��ָ��
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (StackNode*)malloc(sizeof(StackNode));//����ͷ���
	(*s)->top->next = NULL;
	(*s)->count = 0;//���õ�ǰջ��Ԫ������
	return SUCCESS;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		return SUCCESS;
	}
	else {
		return ERROR;
		//printf("ջ��Ϊ��\n");
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		//printf("ջΪ��!\n");
		*e = 0;
		return ERROR;
	}

	(*e) = s->top->data;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType elem) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == MAXSIZE) {
		printf("ջ����, ��ջʧ��\n");
		return ERROR;
	}

	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = elem;
	p->next = s->top;
	s->top = p;
	(s->count)++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		//printf("ջ�ѿ�, ��ջʧ��\n");
		return ERROR;
	}

	*e = s->top->data;
	StackNode* q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;

	return SUCCESS;
}

//��ջ
Status pushLStack2(LinkStack2* s2, double elem) {
	if (s2 == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s2->count == MAXSIZE) {
		printf("ջ����, ��ջʧ��\n");
		return ERROR;
	}

	StackNode2* p = (StackNode2*)malloc(sizeof(StackNode2));
	p->data = elem;
	p->next = s2->top;
	s2->top = p;
	(s2->count)++;
	return SUCCESS;
}

//��ջ
Status popLStack2(LinkStack2* s2, double* e) {
	if (s2 == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s2->count == 0) {
		//printf("ջ�ѿ�, ��ջʧ��\n");
		return ERROR;
	}

	*e = s2->top->data;
	StackNode2* q = s2->top;
	s2->top = s2->top->next;
	free(q);
	s2->count--;

	return SUCCESS;
}