#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Status InitList(LinkedList* L) {//ע�� LinkedList �������һ��ָ��
	(*L) = (LNode*)malloc(sizeof(LNode));//����ͷ���
	(*L)->next = NULL;
	return SUCCESS;
}

//������������
void DestroyList(LinkedList* L) {
	if ((*L) == NULL) return;
	LNode* p = (*L);
	LNode* q;
	do {
		q = p;
		p = p->next;
		free(q);
	} while (p != NULL);
	*L = NULL;
}

//��ĳ��Ԫ�غ������һ��Ԫ��
Status InsertList(LNode* L, ElemType elem, LNode* q) {
	if (L == NULL && L->next == NULL) return ERROR; //�����ж�

	//Ѱ�ҽڵ�ֵΪelem�������е�λ��
	LNode* p = L->next;
	while (p != NULL) {//Ѱ��elem
		if (p->data == elem) break;
		p = p->next;
	}
	if (p == NULL) return ERROR;//�Ҳ�������������elem

	//�ȴ����������
	if (p->next == NULL) {
		p->next = q;
		q->next = NULL;
		return SUCCESS;
	}

	//һ�����
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//ɾ��p�ڵ�ĺ�һ���ڵ�,������ֵ����e
Status DeleteList(LNode* L, ElemType elem, ElemType* e) {
	if (L == NULL) return ERROR; //�����ж�

	//Ѱ�ҽڵ�ֵΪelem�������е�λ��
	LNode* p = L->next;
	while (p != NULL) {//Ѱ��elem
		if (p->data == elem) break;
		p = p->next;
	}
	if (p == NULL) return ERROR;//�Ҳ�������������elem

	//�ȴ����������
	if (p->next == NULL) {
		return ERROR;
	}

	//һ�����
	*e = p->next->data;//��Ҫɾ���Ľڵ��ֵ����*e
	LNode* temp = p->next;//tempָ��Ҫɾ���Ľڵ�
	p->next = temp->next;
	free(temp);
	return SUCCESS;
}

//������������
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	//��ͷ���Ϊ��
	if (L == NULL) {
		printf("����������\n");
		return;
	}
	if (L->next == NULL) {
		printf("���Ǹ�������\n");
		return;
	}

	//��ͷ������һ����ʼ����
	LNode* p = L->next;
	while (p != NULL) {
		visit(p->data);//����visit����,��ӡ��ǰԪ��
		p = p->next;
	}
	printf("NULL\n");
}

//�ж��������Ƿ����ĳԪ��
Status SearchList(LinkedList L, ElemType e) {
	if (L == NULL) return ERROR;

	LNode* p = L->next;
	while (p != NULL) {//��������
		if (p->data == e) {//���ҵ����ϵ�Ԫ��
			return SUCCESS;
		}
		p = p->next;
	}
	return ERROR;//û���ҵ����ϵ�Ԫ��
}

//��ת����(������)
Status ReverseList(LinkedList* L) {
	if ((*L) == NULL) return SUCCESS;
	LNode* cur = ((*L)->next);//����ָ��ǰ�ڵ�,��ʼ��Ϊͷ���
	LNode* pre = NULL;//����ָ��ǰ�ڵ����һ���ڵ�
	while (cur != NULL) {
		LNode* temp = cur->next;//���ڱ�����һ��Ҫ����Ľڵ�,��ֹ��ʧ
		cur->next = pre;//����ǰ�ڵ�(��cur)��nextָ����һ���ڵ�(��pre)
		pre = cur;
		cur = temp;
	}
	//curָ��NULLʱ,��������,�˳�ѭ��
	(*L)->next = pre;//��ʱpreָ��ת�������ͷ���
	return SUCCESS;
}

/*
�ݹ�д������:

�ݹ麯��
void reverse(LNode* cur, LNode* pre) {
	if (cur == NULL) return;
	LNode* temp = cur->next;
	cur->next = pre;
	reverse(temp, cur);
}

���õݹ麯��
Status ReverseList(LinkedList* L) {
	reverse(L, NULL);
	return SUCCESS;
}
*/

//�ж������Ƿ�ɻ�
Status IsLoopList(LinkedList L) {
	if (L == NULL) return ERROR;
	if (L->next == NULL) return ERROR;

	LNode* fast, * slow;//�������ָ��
	fast = slow = L;//�Կ���ָ���ʼ��
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;//��ָ��һ��������
		slow = slow->next;//��ָ��һ����һ��
		if (fast == slow) {//�������ָ������
			return SUCCESS;//˵������ɻ�
		}
	}
	return ERROR;//����ָ���ߵ������β��,������û�гɻ�
}

//�������������е�Ԫ��
LNode* ReverseEvenList(LinkedList* L) {
	if ((*L) == NULL) {
		printf("����������!\n");
		return (*L);//����ǿ�,��ֱ�ӷ���
	}
	LNode* cur = (*L);

	//ֻ��cur�ĺ�������������NULL����Ҫ����
	while (cur->next != NULL && cur->next->next != NULL) {
		LNode* temp = cur->next;//��ʱָ��
		LNode* temp1 = cur->next->next->next;//��ʱָ��

		//ִ�н�������
		cur->next = temp->next;
		cur->next->next = temp;
		temp->next = temp1;

		//����cur��ֵ
		cur = temp;
	}
	return L;
}

//Ѱ��������м�ڵ�
LNode* FindMidNode(LinkedList* L) {
	if (*L == NULL) return *L;
	if ((*L)->next == NULL) return (*L)->next;
	LNode* fast, * slow;//ʹ��˫ָ�뷨
	fast = slow = (*L)->next;//����ָ���ʼ��
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;//��ָ��ÿ��������
		slow = slow->next;//��ָ��ÿ����һ��
	}

	//��ָ���ߵ������β��ʱ,��ָ�������ߵ�������м�
	return slow;
}