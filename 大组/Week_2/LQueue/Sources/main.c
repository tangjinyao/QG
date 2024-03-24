#include <stdio.h>
#include <stdlib.h>

#include "LQueue.h"
#include "LQueue.c" 

LQueue* Q = NULL;//声明一个结构体存储队列的信息
Status result;//记录函数返回值
void* elem;//p节点的值
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
	printf("\t\t1.初始化队列\n");
	printf("\t\t2.判断队列是否为空\n");
	printf("\t\t3.查看队头元素\n");
	printf("\t\t4.清空队列\n");
	printf("\t\t5.销毁队列\n");
	printf("\t\t6.检测队列长度\n");
	printf("\t\t7.入队\n");
	printf("\t\t8.出队\n");
	printf("\t\t9.遍历队列\n");
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
		InitLQueue(&Q);//初始化栈(一个头结点)

		//将队列初始化为  <-队头 0 1 2 3 4 5 6 7 8 9 队尾<-
		for (int i = 0; i <10; i++) {
			EnLQueue(Q, i);
		}

		printf("队列初始化成功!(将队列初始化为  <-队头 0 1 2 3 4 5 6 7 8 9 队尾<-)\n");
		break;
	case '2':
		system("cls");

		result = IsEmptyLQueue(Q);
		if (result == TRUE) {
			printf("队列为空\n");
		}

		break;
	case '3':
		system("cls");

		result = GetHeadLQueue(Q, &elem);
		if (result == TRUE) {
			printf("队头元素的值为: %d\n", elem);
		}

		break;
	case '4':
		system("cls");

		result = ClearLQueue(Q);
		if (result == TRUE) {
			printf("清空队列成功!\n");
		}

		break;
	case '5':
		system("cls");

		result = DestoryLQueue(&Q);//销毁栈
		if (result == TRUE) {
			printf("销毁成功!\n");
		}

		break;
	case '6':
		system("cls");

		length = LengthLQueue(Q);
		if (length != -1) {
			printf("队列的长度为: %d\n", length);
		}

		break;
	case '7':
		system("cls");

		if (Q == NULL) {
			printf("队列不存在!\n");
			break;
		}

		printf("请输入 入队节点 的值(-999 - 999 范围内的整数):\n");
		scanf("%d", &elem);

		result = EnLQueue(Q, elem);
		if (result == TRUE) {
			printf("入队成功!\n");
		}

		break;
	case '8':
		system("cls");

		result = DeLQueue(Q, &elem);
		if (result == TRUE) {
			printf("出队成功, 出队元素的值为: %d\n", elem);
		}

		break;
	case '9':
		system("cls");

		TraverseLQueue(Q, LPrint);


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



