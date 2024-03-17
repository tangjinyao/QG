#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

Status InitList(LinkedList* L) {//注意 LinkedList 本身就是一个指针
	(*L) = (LNode*)malloc(sizeof(LNode));//创造头结点
	(*L)->next = NULL;
	return SUCCESS;
}

//销毁整个链表
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

//在某个元素后面插入一个元素
Status InsertList(LNode* L, ElemType elem, LNode* q) {
	if (L == NULL && L->next == NULL) return ERROR; //错误判断

	//寻找节点值为elem在链表中的位置
	LNode* p = L->next;
	while (p != NULL) {//寻找elem
		if (p->data == elem) break;
		p = p->next;
	}
	if (p == NULL) return ERROR;//找不到符合条件的elem

	//先处理特殊情况
	if (p->next == NULL) {
		p->next = q;
		q->next = NULL;
		return SUCCESS;
	}

	//一般情况
	q->next = p->next;
	p->next = q;
	return SUCCESS;
}

//删除p节点的后一个节点,并将其值赋给e
Status DeleteList(LNode* L, ElemType elem, ElemType* e) {
	if (L == NULL) return ERROR; //错误判断

	//寻找节点值为elem在链表中的位置
	LNode* p = L->next;
	while (p != NULL) {//寻找elem
		if (p->data == elem) break;
		p = p->next;
	}
	if (p == NULL) return ERROR;//找不到符合条件的elem

	//先处理特殊情况
	if (p->next == NULL) {
		return ERROR;
	}

	//一般情况
	*e = p->next->data;//将要删除的节点的值赋给*e
	LNode* temp = p->next;//temp指向要删除的节点
	p->next = temp->next;
	free(temp);
	return SUCCESS;
}

//遍历整个链表
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	//若头结点为空
	if (L == NULL) {
		printf("该链表不存在\n");
		return;
	}
	if (L->next == NULL) {
		printf("这是个空链表\n");
		return;
	}

	//从头结点的下一个开始遍历
	LNode* p = L->next;
	while (p != NULL) {
		visit(p->data);//调用visit函数,打印当前元素
		p = p->next;
	}
	printf("NULL\n");
}

//判断链表中是否存在某元素
Status SearchList(LinkedList L, ElemType e) {
	if (L == NULL) return ERROR;

	LNode* p = L->next;
	while (p != NULL) {//遍历链表
		if (p->data == e) {//若找到符合的元素
			return SUCCESS;
		}
		p = p->next;
	}
	return ERROR;//没有找到符合的元素
}

//翻转链表(迭代法)
Status ReverseList(LinkedList* L) {
	if ((*L) == NULL) return SUCCESS;
	LNode* cur = ((*L)->next);//用于指向当前节点,初始化为头结点
	LNode* pre = NULL;//用于指向当前节点的上一个节点
	while (cur != NULL) {
		LNode* temp = cur->next;//用于保存下一个要处理的节点,防止丢失
		cur->next = pre;//将当前节点(即cur)的next指向上一个节点(即pre)
		pre = cur;
		cur = temp;
	}
	//cur指向NULL时,遍历结束,退出循环
	(*L)->next = pre;//此时pre指向翻转后链表的头结点
	return SUCCESS;
}

/*
递归写法如下:

递归函数
void reverse(LNode* cur, LNode* pre) {
	if (cur == NULL) return;
	LNode* temp = cur->next;
	cur->next = pre;
	reverse(temp, cur);
}

调用递归函数
Status ReverseList(LinkedList* L) {
	reverse(L, NULL);
	return SUCCESS;
}
*/

//判断链表是否成环
Status IsLoopList(LinkedList L) {
	if (L == NULL) return ERROR;
	if (L->next == NULL) return ERROR;

	LNode* fast, * slow;//定义快慢指针
	fast = slow = L;//对快慢指针初始化
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;//快指针一次走两步
		slow = slow->next;//慢指针一次走一步
		if (fast == slow) {//如果快慢指针相遇
			return SUCCESS;//说明链表成环
		}
	}
	return ERROR;//若快指针走到链表的尾部,则链表没有成环
}

//两两交换链表中的元素
LNode* ReverseEvenList(LinkedList* L) {
	if ((*L) == NULL) {
		printf("该链表不存在!\n");
		return (*L);//如果是空,则直接返回
	}
	LNode* cur = (*L);

	//只有cur的后面两个都不是NULL才需要操作
	while (cur->next != NULL && cur->next->next != NULL) {
		LNode* temp = cur->next;//临时指针
		LNode* temp1 = cur->next->next->next;//临时指针

		//执行交换操作
		cur->next = temp->next;
		cur->next->next = temp;
		temp->next = temp1;

		//更新cur的值
		cur = temp;
	}
	return L;
}

//寻找链表的中间节点
LNode* FindMidNode(LinkedList* L) {
	if (*L == NULL) return *L;
	if ((*L)->next == NULL) return (*L)->next;
	LNode* fast, * slow;//使用双指针法
	fast = slow = (*L)->next;//快慢指针初始化
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;//快指针每次走两步
		slow = slow->next;//慢指针每次走一步
	}

	//快指针走到链表的尾部时,慢指针正好走到链表的中间
	return slow;
}