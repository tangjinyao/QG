#include <stdio.h>
#include <stdlib.h>

#include "LinkStack.h"
#include "LinkStack.c" 

LinkStack* s = NULL;//声明一个结构体存储栈的信息
Status result;//记录函数返回值
ElemType elem;//p节点的值
ElemType* e = &elem;//存储元素值的指针
int length;
int* pl = &length;

void makeMainMenu();//创建主界面
void keyMainDown();//主界面交互


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
	printf("\t\t1.初始化栈\n");
	printf("\t\t2.判断栈是否为空\n");
	printf("\t\t3.获取栈顶元素\n");
	printf("\t\t4.清空栈\n");
	printf("\t\t5.销毁栈\n");
	printf("\t\t6.检测栈长度\n");
	printf("\t\t7.入栈\n");
	printf("\t\t8.出栈\n");
	printf("\t\t0.退出系统\n");
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

		//清空缓冲区
		int c;
		while ((c = getchar()) != '\n' && c != EOF);

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
		InitLStack(&s);//初始化栈(一个头结点)

		//将栈初始化为  栈顶-> 0 1 2 3 4 5 6 7 8 9 栈底|
		for (int i = 9; i >= 0; i--) {
			pushLStack(s, i);
		}

		printf("栈初始化成功!(将栈初始化为  栈顶-> 0 1 2 3 4 5 6 7 8 9 |)\n");
		break;
	case '2':
		system("cls");

		result = isEmptyLStack(s);
		if (result == SUCCESS) {
			printf("栈为空\n");
		}
		
		break;
	case '3':
		system("cls");

		result = getTopLStack(s, e);
		if (result == SUCCESS) {
			printf("栈顶元素的值为: %d\n", *e);
		}

		break;
	case '4':
		system("cls");

		result = clearLStack(s);
		if (result == SUCCESS) {
			printf("清空栈成功!\n");
		}

		break;
	case '5':
		system("cls");

		result = destroyLStack(&s);//销毁栈
		if (result == SUCCESS) {
			printf("销毁成功!\n");
		}

		break;
	case '6':
		system("cls");

		result = LStackLength(s, pl);
		if (result == SUCCESS) {
			printf("栈的长度为: %d\n", *pl);
		}

		break;
	case '7':
		system("cls");

		if (s == NULL) {
			printf("栈不存在!\n");
			break;
		}

		printf("请输入入栈p节点的值(-999 - 999 范围内的整数):\n");
		scanf("%d", &elem);

		result = pushLStack(s, elem);
		if (result == SUCCESS) {
			printf("入栈成功!\n");
		}

		break;
	case '8':
		system("cls");

		result = popLStack(s, e);
		if (result == SUCCESS) {
			printf("出栈成功, 出栈元素的值为: %d\n", *e);
		}

		break;


	case '0':
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



