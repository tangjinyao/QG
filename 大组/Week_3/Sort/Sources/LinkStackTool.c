#include <stdio.h>
#include <stdlib.h>
#include "LinkStackTool.h"

Status InitLStack(LinkStack** s) {//注意 LinkStackPtr 本身就是一个指针
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (StackNode*)malloc(sizeof(StackNode));//创造头结点
	(*s)->top->next = NULL;
	(*s)->count = 0;//设置当前栈的元素数量
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType begin, ElemType end) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == MAXSIZE) {
		printf("栈已满, 入栈失败\n");
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

//出栈
Status popLStack(LinkStack* s, ElemType* pBegin, ElemType* pEnd) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("栈已空, 出栈失败\n");
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