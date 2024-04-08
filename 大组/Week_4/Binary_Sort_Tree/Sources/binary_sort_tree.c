#include <stdio.h>
#include <stdlib.h>

#include "binary_sort_tree.h"

Status BST_init(BinarySortTreePtr BST) {
	BST = (BinarySortTree*)malloc(sizeof(BinarySortTree));
	BST->root = NULL;
	return succeed;
}

//插入数据
Status BST_insert(BinarySortTreePtr BST, ElemType elem) {
	NodePtr node = (Node*)malloc(sizeof(Node));//将待插入的数据封装成一个节点
	node->value = elem;
	node->left = node->right = NULL;

	if (BST->root == NULL) {//如果树为空，直接插入
		BST->root = node;
		return succeed;
	}

	NodePtr p = BST->root;//从根节点开始查找
	while (p != NULL) {//查找插入位置
		if (elem < p->value) {//如果待插入数据小于当前节点数据
			if (p->left == NULL) {//如果当前节点左孩子为空，直接插入
				p->left = node;
				return succeed;
			}
			p = p->left;//否则继续查找
		}
		else if (elem > p->value) {//如果待插入数据大于当前节点数据
			if (p->right == NULL) {//如果当前节点右孩子为空，直接插入
				p->right = node;
				return succeed;
			}
			p = p->right;//否则继续查找
		}
		else {
			return failed;//如果待插入数据等于当前节点数据，返回失败
		}
	}
	return failed;
}

//删除某一个节点
Status BST_delete(BinarySortTreePtr BST, ElemType elem) {
	NodePtr p = BST->root;//从根节点开始查找
	NodePtr parent = NULL;//记录待删除节点的父节点

	while (p != NULL && p->value != elem) {//查找待删除节点
		parent = p;
		if (elem < p->value) {
			p = p->left;
		}
		else {
			p = p->right;
		}
	}
	if (p == NULL) {//如果没有找到待删除节点
		return failed;
	}

	if (p->left != NULL && p->right != NULL) {//如果待删除节点有两个孩子
		NodePtr minParent = p;//记录右子树中最小节点的父节点
		NodePtr min = p->right;//记录右子树中最小节点

		while (min->left != NULL) {//查找右子树中最小节点
			minParent = min;
			min = min->left;
		}
		p->value = min->value;//将右子树中最小节点的值赋给待删除节点
		p = min;//将待删除节点指向右子树中最小节点
		parent = minParent;//将待删除节点的父节点指向右子树中最小节点的父节点
	}

	NodePtr child = NULL;
	if (p->left != NULL) {//如果待删除节点只有左孩子
		child = p->left;
	}
	else if (p->right != NULL) {//如果待删除节点只有右孩子
		child = p->right;
	}

	if (parent == NULL) {//如果待删除节点是根节点
		BST->root = child;
	}
	else if (parent->left == p) {//如果待删除节点是父节点的左孩子
		parent->left = child;
	}
	else {//如果待删除节点是父节点的右孩子
		parent->right = child;
	}
	free(p);
	return succeed;
}

//查找数据
Status BST_search(BinarySortTreePtr BSD, ElemType elem) {
	NodePtr p = BSD->root;//从根节点开始查找
	while (p != NULL) {//查找待查找数据
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

//前序遍历(非递归)
Status BST_preorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//从根节点开始遍历
	NodePtr stack[100];//模拟栈
	int top = -1;//栈顶指针


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

//前序遍历(递归)
Status BST_preorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		visit(p);
		BST_preorderR(p->left, visit);
		BST_preorderR(p->right, visit);
	}
	return succeed;
}

//中序遍历(非递归)
Status BST_inorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//从根节点开始遍历
	NodePtr stack[100];//模拟栈
	int top = -1;//栈顶指针

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

//中序遍历(递归)
Status BST_inorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		BST_inorderR(p->left, visit);
		visit(p);
		BST_inorderR(p->right, visit);
	}
	return succeed;
}

//后序遍历(非递归)
Status BST_postorderI(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr p = BST->root;//从根节点开始遍历
	NodePtr stack[100];//模拟栈
	int top = -1;//栈顶指针
	NodePtr lastVisit = NULL;//记录上次访问的节点

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

//后序遍历(递归)
Status BST_postorderR(NodePtr p, void (*visit)(NodePtr)) {
	if (p != NULL) {
		BST_postorderR(p->left, visit);
		BST_postorderR(p->right, visit);
		visit(p);
	}
	return succeed;
}

//层次遍历
Status BST_levelOrder(BinarySortTreePtr BST, void (*visit)(NodePtr)) {
	NodePtr queue[100];//模拟队列
	int front = 0, rear = 0;//队头和队尾指针
	NodePtr p = BST->root;//从根节点开始遍历

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

//生成测试数据
void generateTestData(BinarySortTreePtr BST) {
	BST_insert(BST, 5);
	BST_insert(BST, 3);
	BST_insert(BST, 7);
	BST_insert(BST, 2);
	BST_insert(BST, 4);
	BST_insert(BST, 6);
	BST_insert(BST, 8);
}