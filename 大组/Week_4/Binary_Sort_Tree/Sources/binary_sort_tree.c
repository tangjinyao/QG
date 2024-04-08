#include <stdio.h>
#include <stdlib.h>

#include "binary_sort_tree.h"

Status BST_init(BinarySortTreePtr BST) {
	BST = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	BST->root = NULL;
	return succeed;
}

//��������
Status BST_insert(BinarySortTreePtr BST, ElemType elem) {
	NodePtr node = (Node*)malloc(sizeof(Node));//������������ݷ�װ��һ���ڵ�
	node->value = elem;
	node->left = node->right = NULL;

	if (BST->root == NULL) {//�����Ϊ�գ�ֱ�Ӳ���
		BST->root = node;
		return succeed;
	}

	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����
	while (p != NULL) {//���Ҳ���λ��
		if (elem < p->value) {//�������������С�ڵ�ǰ�ڵ�����
			if (p->left == NULL) {//�����ǰ�ڵ�����Ϊ�գ�ֱ�Ӳ���
				p->left = node;
				return succeed;
			}
			p = p->left;//�����������
		}
		else if (elem > p->value) {//������������ݴ��ڵ�ǰ�ڵ�����
			if (p->right == NULL) {//�����ǰ�ڵ��Һ���Ϊ�գ�ֱ�Ӳ���
				p->right = node;
				return succeed;
			}
			p = p->right;//�����������
		}
		else {
			return failed;//������������ݵ��ڵ�ǰ�ڵ����ݣ�����ʧ��
		}
	}
	return failed;
}

//ɾ��ĳһ���ڵ�
Status BST_delete(BinarySortTreePtr BST, ElemType elem) {
	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����
	NodePtr parent = NULL;//��¼��ɾ���ڵ�ĸ��ڵ�

	while (p != NULL && p->value != elem) {//���Ҵ�ɾ���ڵ�
		parent = p;
		if (elem < p->value) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (p == NULL) {//���û���ҵ���ɾ���ڵ�
		return failed;
	}

	if (p->left != NULL && p->right != NULL) {//�����ɾ���ڵ�����������
		NodePtr minParent = p;//��¼����������С�ڵ�ĸ��ڵ�
		NodePtr min = p->right;//��¼����������С�ڵ�

		while (min->left != NULL) {//��������������С�ڵ�
			minParent = min;
			min = min->left;
		}
		p->value = min->value;//������������С�ڵ��ֵ������ɾ���ڵ�
		p = min;//����ɾ���ڵ�ָ������������С�ڵ�
		parent = minParent;//����ɾ���ڵ�ĸ��ڵ�ָ������������С�ڵ�ĸ��ڵ�
	}

	NodePtr child = NULL;
	if (p->left != NULL) {//�����ɾ���ڵ�ֻ������
		child = p->left;
	}
	else if (p->right != NULL) {//�����ɾ���ڵ�ֻ���Һ���
		child = p->right;
	}

	if (parent == NULL) {//�����ɾ���ڵ��Ǹ��ڵ�
		BST->root = child;
	}
	else if (parent->left == p) {//�����ɾ���ڵ��Ǹ��ڵ������
		parent->left = child;
	}
	else {//�����ɾ���ڵ��Ǹ��ڵ���Һ���
		parent->right = child;
	}
	free(p);
	return succeed;
}

//��������
Status BST_search(BinarySortTreePtr BSD, ElemType elem) {
	NodePtr p = BSD->root;//�Ӹ��ڵ㿪ʼ����
	while (p != NULL) {//���Ҵ���������
		if (elem < p->value) {
			p = p->left;
		}
		else if (elem > p->value) {
			p = p->right;
		}
		else {
			return succeed;
		}
	}
	return failed;
}

//ǰ�����(�ǵݹ�)
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����
	NodePtr stack[100];//ģ��ջ
	int top = -1;//ջ��ָ��


	while (p != NULL || top != -1) {
		while (p != NULL) {
			visit(p);
			stack[++top] = p;
			p = p->left;
		}
		if (top != -1) {
			p = stack[top--];
			p = p->right;
		}
	}
	return succeed;
}

//ǰ�����(�ݹ�)
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		visit(p);
		BST_preorderR(p->left, visit);
		BST_preorderR(p->right, visit);
	}
	return succeed;
}

//�������(�ǵݹ�)
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����
	NodePtr stack[100];//ģ��ջ
	int top = -1;//ջ��ָ��

	while (p != NULL || top != -1) {
		while (p != NULL) {
			stack[++top] = p;
			p = p->left;
		}
		if (top != -1) {
			p = stack[top--];
			visit(p);
			p = p->right;
		}
	}
	return succeed;
}

//�������(�ݹ�)
Status BST_inorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		BST_inorderR(p->left, visit);
		visit(p);
		BST_inorderR(p->right, visit);
	}
	return succeed;
}

//�������(�ǵݹ�)
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����
	NodePtr stack[100];//ģ��ջ
	int top = -1;//ջ��ָ��
	NodePtr lastVisit = NULL;//��¼�ϴη��ʵĽڵ�

	while (p != NULL || top != -1) {
		while (p != NULL) {
			stack[++top] = p;
			p = p->left;
		}
		p = stack[top];
		if (p->right == NULL || p->right == lastVisit) {
			visit(p);
			lastVisit = p;
			top--;
			p = NULL;
		}
		else {
			p = p->right;
		}
	}
	return succeed;
}

//�������(�ݹ�)
Status BST_postorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		BST_postorderR(p->left, visit);
		BST_postorderR(p->right, visit);
		visit(p);
	}
	return succeed;
}

//��α���
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr queue[100];//ģ�����
	int front = 0, rear = 0;//��ͷ�Ͷ�βָ��
	NodePtr p = BST->root;//�Ӹ��ڵ㿪ʼ����

	if (p != NULL) {
		queue[rear++] = p;
	}

	while (front != rear) {
		p = queue[front++];
		visit(p);
		if (p->left != NULL) {
			queue[rear++] = p->left;
		}
		if (p->right != NULL) {
			queue[rear++] = p->right;
		}
	}
	return succeed;
}

//���ɲ�������
void generateTestData(BinarySortTreePtr BST) {
	BST_insert(BST, 5);
	BST_insert(BST, 3);
	BST_insert(BST, 7);
	BST_insert(BST, 2);
	BST_insert(BST, 4);
	BST_insert(BST, 6);
	BST_insert(BST, 8);
}