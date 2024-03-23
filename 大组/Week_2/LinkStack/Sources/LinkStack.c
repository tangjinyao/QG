#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

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
		printf("ջ��Ϊ��\n");
	}
}

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("ջΪ��!\n");
		return ERROR;
	}

	(*e) = s->top->data;
	return SUCCESS;
}

//�������ջ
Status clearLStack(LinkStack* s) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("ջ�������ǿյ�, �������\n");
		return ERROR;
	}
	StackNode* p = s->top;
	StackNode* q;
	do {
		q = p;
		p = p->next;
		free(q);
	} while (p != NULL);
	s->count = 0;
	return SUCCESS;
}

/*
//��������ջ
Status destroyLStack(LinkStack* s) {
	if (s == NULL) {
		printf("ջ������, �޷�����\n");
		return ERROR;
	}
	if ((s->count) == 0) {
		free(s);
		s = NULL;
		return SUCCESS;
	}
	StackNode* p = s->top;
	StackNode* q;
	do {
		q = p;
		p = p->next;
		free(q);
	} while (p != NULL);
	free(s);
	s = NULL;
	return SUCCESS;
}
*/


//��������ջ
Status destroyLStack(LinkStack** s) {
	if (s == NULL || (*s) == NULL) {
		printf("ջ������, �޷�����\n");
		return ERROR;
	}
	if (((*s)->count) == 0) {
		free((*s));
		*s = NULL;
		return SUCCESS;
	}
	StackNode* p = (*s)->top;
	StackNode* q;
	do {
		q = p;
		p = p->next;
		free(q);
	} while (p != NULL);
	free((*s));
	*s = NULL;
	return SUCCESS;
}

//���ջ����
Status LStackLength(LinkStack* s, int* pl) {

	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	
	*pl = s->count;
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
		printf("ջ�ѿ�, ��ջʧ��\n");
		return ERROR;
	}

	*e = s->top->data;
	StackNode* q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;

	return SUCCESS;
}