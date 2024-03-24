#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h"

//��ʼ������
void InitLQueue(LQueue** Q) {
	(*Q) = (LQueue*)malloc(sizeof(LQueue));
	(*Q)->front = (*Q)->rear = (Node*)malloc(sizeof(Node));
	(*Q)->front->next = NULL;
	(*Q)->length = 0;
}

//���ٶ���
Status DestoryLQueue(LQueue** Q) {
	if ((*Q) == NULL) {
		printf("���в�����, �޷�����!\n");
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

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q == NULL) {
		printf("���в�����!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		return TRUE;
	}
	if (Q->length != 0) {
		printf("���в�Ϊ��\n");
		return FALSE;
	}
}

//�鿴��ͷԪ��
Status GetHeadLQueue(LQueue* Q, void** e) {
	if (Q == NULL) {
		printf("���в�����, �޷��鿴��ͷԪ��!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("����Ϊ��, �޷��鿴��ͷԪ��!\n");
		return FALSE;
	}
	Node* p = Q->front->next;
	if (p) {
		*e = p->data;
		return TRUE;
	}
	return FALSE;
}

//ȷ�����г���
int LengthLQueue(LQueue* Q) {
	if (Q == NULL) {
		printf("���в�����!\n");
		return -1;
	}
	return Q->length;
}

//���
Status EnLQueue(LQueue* Q, void* data) {
	if (Q == NULL) {
		printf("���в�����, �޷����!\n");
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

//����
Status DeLQueue(LQueue* Q, void** e) {
	if (Q == NULL) {
		printf("���в�����, �޷�����!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("����Ϊ��, �޷�����!\n");
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

//��ն���
Status ClearLQueue(LQueue* Q) {
	if (Q == NULL) {
		printf("���в�����, �޷����!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("���б������ǿյ�, �������\n");
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

//������������
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (Q == NULL) {
		printf("���в�����, �޷�����!\n");
		return FALSE;
	}
	if (Q->length == 0) {
		printf("����Ϊ��, �޷�����!\n");
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

//��������
void LPrint(void* q) {
	printf("%d ", q);
}