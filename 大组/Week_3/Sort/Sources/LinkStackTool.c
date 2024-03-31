#include <stdio.h>
#include <stdlib.h>
#include "LinkStackTool.h"

Status InitLStack(LinkStack** s) {//ע�� LinkStackPtr �������һ��ָ��
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (StackNode*)malloc(sizeof(StackNode));//����ͷ���
	(*s)->top->next = NULL;
	(*s)->count = 0;//���õ�ǰջ��Ԫ������
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType begin, ElemType end) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == MAXSIZE) {
		printf("ջ����, ��ջʧ��\n");
		return ERROR;
	}

	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->begin = begin;
	p->end = end;
	p->next = s->top;
	s->top = p;
	(s->count)++;
	return SUCCESS;
}

//��ջ
Status popLStack(LinkStack* s, ElemType* pBegin, ElemType* pEnd) {
	if (s == NULL) {
		printf("ջ������!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("ջ�ѿ�, ��ջʧ��\n");
		return ERROR;
	}

	*pBegin = s->top->begin;
	*pEnd = s->top->end;
	StackNode* q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;

	return SUCCESS;
}