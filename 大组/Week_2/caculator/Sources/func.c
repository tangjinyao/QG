#include <stdio.h>
#include <stdlib.h>
#include "calculate.h"

Status InitLStack(LinkStack** s) {//注意 LinkStackPtr 本身就是一个指针
	(*s) = (LinkStack*)malloc(sizeof(LinkStack));
	(*s)->top = (StackNode*)malloc(sizeof(StackNode));//创造头结点
	(*s)->top->next = NULL;
	(*s)->count = 0;//设置当前栈的元素数量
	return SUCCESS;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		return SUCCESS;
	}
	else {
		return ERROR;
		//printf("栈不为空\n");
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		//printf("栈为空!\n");
		*e = 0;
		return ERROR;
	}

	(*e) = s->top->data;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType elem) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == MAXSIZE) {
		printf("栈已满, 入栈失败\n");
		return ERROR;
	}

	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	p->data = elem;
	p->next = s->top;
	s->top = p;
	(s->count)++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		//printf("栈已空, 出栈失败\n");
		return ERROR;
	}

	*e = s->top->data;
	StackNode* q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;

	return SUCCESS;
}

//入栈
Status pushLStack2(LinkStack2* s2, double elem) {
	if (s2 == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s2->count == MAXSIZE) {
		printf("栈已满, 入栈失败\n");
		return ERROR;
	}

	StackNode2* p = (StackNode2*)malloc(sizeof(StackNode2));
	p->data = elem;
	p->next = s2->top;
	s2->top = p;
	(s2->count)++;
	return SUCCESS;
}

//出栈
Status popLStack2(LinkStack2* s2, double* e) {
	if (s2 == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s2->count == 0) {
		//printf("栈已空, 出栈失败\n");
		return ERROR;
	}

	*e = s2->top->data;
	StackNode2* q = s2->top;
	s2->top = s2->top->next;
	free(q);
	s2->count--;

	return SUCCESS;
}