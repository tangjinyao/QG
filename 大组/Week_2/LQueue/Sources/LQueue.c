#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

//初始化队列
void InitLQueue(LQueue** Q) {
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	(*Q)->front = (*Q)->rear = (Node*)malloc(sizeof(Node));
	(*Q)->front->next = NULL;
	(*Q)->length = 0;
}

//销毁队列
Status DestoryLQueue(LQueue** Q) {
	if ((*Q) == NULL) {
		printf("队列不存在, 无法销毁!\n");
		return;
	}
	Node* p = (*Q)->front;
	Node* q = p;
	while (p->next != NULL) {
		p = p->next;
		free(q);
		q = p;
	}
	free(p);
	free(*Q);
	*Q = NULL;
	return TRUE;
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q == NULL) {
		printf("队列不存在!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		return TRUE;
	}
	if (Q->length != 0) {
		printf("队列不为空\n");
		return FALSE;
	}
}

//查看队头元素
Status GetHeadLQueue(LQueue* Q, void** e) {
	if (Q == NULL) {
		printf("队列不存在, 无法查看队头元素!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("队列为空, 无法查看队头元素!\n");
		return FALSE;
	}
	Node* p = Q->front->next;
	if (p) {
		*e = p->data;
		return TRUE;
	}
	return FALSE;
}

//确定队列长度
int LengthLQueue(LQueue* Q) {
	if (Q == NULL) {
		printf("队列不存在!\n");
		return -1;
	}
	return Q->length;
}

//入队
Status EnLQueue(LQueue* Q, void* data) {
	if (Q == NULL) {
		printf("队列不存在, 无法入队!\n");
		return FALSE;
	}
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->length++;
	return TRUE;
}

//出队
Status DeLQueue(LQueue* Q, void** e) {
	if (Q == NULL) {
		printf("队列不存在, 无法出队!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("队列为空, 无法出队!\n");
		return FALSE;
	}
	*e = Q->front->next->data;
	Node* p = Q->front;
	Node* q = p;
	p = p->next;
	free(q);
	Q->front = p;
	Q->length--;
	return TRUE;
}

//清空队列
Status ClearLQueue(LQueue* Q) {
	if (Q == NULL) {
		printf("队列不存在, 无法清空!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("队列本来就是空的, 无需清空\n");
		return FALSE;
	}
	Node* p = Q->front;
	Node* q = p;
	while (p->next != NULL) {
		p = p->next;
		free(q);
		q = p;
	}
	Q->front = p;
	Q->length = 0;
	return TRUE;
}

//遍历函数操作
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (Q == NULL) {
		printf("队列不存在, 无法遍历!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("队列为空, 无法遍历!\n");
		return FALSE;
	}
	Node* p = Q->front->next;
	while (p != NULL) {
		foo(p->data);
		p = p->next;
	}
	printf("\n");
	return TRUE;
}

//操作函数
void LPrint(void* q) {
	printf("%d ", q);
}