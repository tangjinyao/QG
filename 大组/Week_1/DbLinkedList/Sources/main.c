#include <stdio.h>
#include <stdlib.h>

#include "DbLinkedList.h"
#include "func.c"

//#include "func.c" 

LNode* list;//声明一个链表
Status result;//记录函数返回值
ElemType elem;//p节点的值

void makeMainMenu();//创建主界面
void keyMainDown();//主界面交互

void Visit(ElemType e) {
	printf("%d  ", e);
}
void (*visit)(ElemType e) = Visit;

int main() {
	while (1) {
		makeMainMenu();
		keyMainDown();
		system("pause");
		system("cls");
	}
}

void makeMainMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.初始化链表\n");
	printf("\t\t2.销毁整个链表\n");
	printf("\t\t3.在p节点前面插入一个q节点\n");
	printf("\t\t4.在p节点后面插入一个q节点\n");
	printf("\t\t5.删除元素并输出删除的节点值\n");
	printf("\t\t6.遍历链表\n");
	printf("\t\t7.查询元素\n");
	printf("\t\t#.退出系统\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}

void keyMainDown() {
	char userMainKey = 0;
	char userKey2 = 0;

	//错误判断
	while (1) {
		while (1) {
			userMainKey = getchar();
			if (userMainKey != ' ' && userMainKey != '\n') {
				break;
			}
		}
		getchar();
		if ((userMainKey >= '0' && userMainKey <= '9') || (userMainKey == '#')) {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userMainKey) {//主界面交互
	case '1':
		system("cls");
		InitList(&list);//初始化链表(一个头结点)
		LNode* p1 = list;

		//将链表初始化为  0<->1<->2<->3<->4<->5<->6<->7<->8<->9
		for (int i = 0; i < 10; i++) {
			LNode* p2 = (LNode*)malloc(sizeof(LNode));
			p2->data = i;
			p2->pre = NULL;
			p2->next = NULL;
			p1->next = p2;
			p2->pre = p1;
			p1 = p2;
		}

		printf("链表初始化成功! (将链表初始化为  0<->1<->2<->3<->4<->5<->6<->7<->8<->9)\n");
		break;
	case '2':
		system("cls");
		DestroyList(&list);//销毁链表
		printf("销毁成功!\n");
		break;
	case '3':
		system("cls");

		LNode* q;//要插入的q节点
		q = (LNode*)malloc(sizeof(LNode));

		printf("在p节点前面插入一个q节点\n");
		printf("请输入p节点的值:\n");
		scanf("%d", &elem);
		printf("请输入q节点的值:\n");
		scanf("%d", &q->data);
		result = insertBeforeNode(list, elem, q);
		if (result == SUCCESS) {
			printf("插入成功!\n");
		}
		else {
			printf("找不到符合条件的p节点!\n");
		}
		break;
	case '4':
		system("cls");

		//LNode* q;//要插入的q节点
		q = (LNode*)malloc(sizeof(LNode));

		printf("在p节点后面插入一个q节点\n");
		printf("请输入p节点的值:\n");
		scanf("%d", &elem);
		printf("请输入q节点的值:\n");
		scanf("%d", &q->data);
		result = insertAfterNode(list, elem, q);
		if (result == SUCCESS) {
			printf("插入成功!\n");
		}
		else {
			printf("找不到符合条件的p节点!\n");
		}
		break;
	case '5':
		system("cls");

		printf("请输入要删除的节点的值:\n");
		scanf("%d", &elem);
		result = DeleteList(list, elem);
		if (result == SUCCESS) {
			printf("删除成功!\n");
		}
		else {
			printf("删除失败\n");
		}
		break;
	case '6':
		system("cls");
		TraverseList(list, visit);
		break;
	case '7':
		system("cls");
		ElemType e1;
		printf("请输入要查找的元素:\n");
		scanf("%d", &e1);

		result = SearchList(list, e1);
		if (result == SUCCESS) {
			printf("该数存在\n");
		}
		else {
			printf("该数不存在\n");
		}
		break;
	case '#':
		printf("退出成功！");
		system("pause");
		exit(0);
		break;
	default:
		printf("主页面输入错误，请重试！");
		system("pause");
		system("cls");
	}
}


