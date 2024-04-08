#include <stdio.h>
#include <stdlib.h>

#include "binary_sort_tree.h"

#include "binary_sort_tree.c" 

BinarySortTree BST;//定义一个二叉排序树
Status result;//记录函数返回值
ElemType elem;//p节点的值
int sign = 0;//标记是否退出二级菜单

void makeMainMenu();//创建主界面
void keyMainDown();//主界面交互

void makeSubMenu();//创建二级菜单
void keySubDown();//二级菜单交互

//访问节点
void visit(NodePtr node) {
	printf("%d  ", node->value);
}

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
	printf("\t\t1.初始化二叉排序树\n");
	printf("\t\t2.插入数据\n");
	printf("\t\t3.删除数据\n");
	printf("\t\t4.查找数据\n");
	printf("\t\t5.遍历\n");
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
		if ((userMainKey >= '1' && userMainKey <= '5') || (userMainKey == '#')) {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userMainKey) {//主界面交互
	case '1':
		system("cls");
		BST_init(&BST);//初始化二叉排序树

		generateTestData(&BST);//生成测试数据

		printf("初始化成功!\n");
		printf("依次插入数据：5,3,7,2,4,6,8\n");

		break;
	case '2':
		system("cls");

		printf("请输入要插入的数据（int类型）:\n");
		scanf("%d", &elem);
		result = BST_insert(&BST, elem);
		if (result == succeed) {
			printf("插入成功!\n");
		}
		else {
			printf("树中已有该数据，插入失败\n");
		}

		break;
	case '3':
		system("cls");

		printf("请输入要删除的数据:\n");
		scanf("%d", &elem);
		result = BST_delete(&BST, elem);
		if (result == succeed) {
			printf("删除成功!\n");
		}
		else {
			printf("该数不存在，删除失败\n");
		}

		break;
	case '4':
		system("cls");

		printf("请输入要查找的数据:\n");
		scanf("%d", &elem);
		result = BST_search(&BST, elem);
		if (result == succeed) {
			printf("查找成功!\n");
		}
		else {
			printf("该数不存在，查找失败\n");
		}

		break;
	case '5':
		system("cls");

		while(1) {
			makeSubMenu();
			keySubDown();
			if (sign == 1) {
				break;
			}
			system("pause");
			system("cls");
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

//二级菜单界面
void makeSubMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.前序遍历(非递归)\n");
	printf("\t\t2.前序遍历(递归)\n");
	printf("\t\t3.中序遍历(非递归)\n");
	printf("\t\t4.中序遍历(递归)\n");
	printf("\t\t5.后序遍历(非递归)\n");
	printf("\t\t6.后序遍历(递归)\n");
	printf("\t\t7.层次遍历\n");
	printf("\t\t#.返回主菜单\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}

//二级菜单交互
void keySubDown() {
	char userSubKey = 0;

	//错误判断
	while (1) {
		while (1) {
			userSubKey = getchar();
			if (userSubKey != ' ' && userSubKey != '\n') {
				break;
			}
		}
		getchar();
		if ((userSubKey >= '0' && userSubKey <= '9') || (userSubKey == '#')) {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userSubKey) {//二级菜单交互
	case '1':
		system("cls");
		//前序遍历(非递归)
		BST_preorderI(&BST, visit);
		break;
	case '2':
		system("cls");
		//前序遍历(递归)
		BST_preorderR(BST.root, visit);
		break;
	case '3':
		system("cls");
		//中序遍历(非递归)
		BST_inorderI(&BST, visit);
		break;
	case '4':
		system("cls");
		//中序遍历(递归)
		BST_inorderR(BST.root, visit);
		break;
	case '5':
		system("cls");
		//后序遍历(非递归)
		BST_postorderI(&BST, visit);
		break;
	case '6':
		system("cls");
		//后序遍历(递归)
		BST_postorderR(BST.root, visit);
		break;
	case '7':
		system("cls");
		//层次遍历
		BST_levelOrder(&BST, visit);
		break;
	case '#':
		system("cls");
		printf("返回成功！\n");
		sign = 1;
		break;
	default:
		printf("输入错误，请重试！");
		system("pause");
		system("cls");
	}
}
