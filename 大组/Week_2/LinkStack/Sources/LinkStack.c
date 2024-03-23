#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"

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
		printf("栈不为空\n");
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("栈为空!\n");
		return ERROR;
	}

	(*e) = s->top->data;
	return SUCCESS;
}

//清空整个栈
Status clearLStack(LinkStack* s) {
	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	if (s->count == 0) {
		printf("栈本来就是空的, 无需清空\n");
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
//销毁整个栈
Status destroyLStack(LinkStack* s) {
	if (s == NULL) {
		printf("栈不存在, 无法销毁\n");
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


//销毁整个栈
Status destroyLStack(LinkStack** s) {
	if (s == NULL || (*s) == NULL) {
		printf("栈不存在, 无法销毁\n");
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

//检测栈长度
Status LStackLength(LinkStack* s, int* pl) {

	if (s == NULL) {
		printf("栈不存在!\n");
		return ERROR;
	}
	
	*pl = s->count;
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
		printf("栈已空, 出栈失败\n");
		return ERROR;
	}

	*e = s->top->data;
	StackNode* q = s->top;
	s->top = s->top->next;
	free(q);
	s->count--;

	return SUCCESS;
}