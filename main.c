#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "common.h"
#include "stu.h"
#include "file.h"

#include "stu.c"
#include "file.c" 
#include "pwd.c"
//#include "tools.c"

timuNode* timuList;
stuNode* stuList;
char pwd[MAX_PWD];

void makeMainMenu();//创建主界面
void makeStuMenu();//创建学生界面
void makeTeacherMenu();//创建教师界面

void keyMainDown();//主界面交互
void keyStuDown();//学生界面交互
void keyTeacherDown();//教师界面交互

int main() {
	//创建一个链表（题目）
	timuList = creatTimuHead();
	//创建一个链表（学生）
	stuList = creatStuHead();

	//读档
	readTimuFile(timuList, FILE_URL_TIMU);
	readStuFile(stuList, FILE_URL_STU);
	readPwdFile(stuPwd, FILE_URL_STUPWD);
	readPwdFile(teacherPwd, FILE_URL_TEACHERPWD);


	while (1) {
		makeMainMenu();
		keyMainDown();
		//system("pause");
		system("cls");
	}

	return 0;
}

//创建主界面
void makeMainMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.学生登录\n");
	printf("\t\t2.教师登录\n");
	printf("\t\t3.退出系统\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}

void makeStuMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.学生答题\n");
	printf("\t\t2.修改学生\n");
	printf("\t\t3.修改密码\n");
	printf("\t\t4.返回上一级\n");
	printf("\t\t5.退出系统\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}

void makeTeacherMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.显示所有题目\n");
	printf("\t\t2.显示所有学生\n");
	printf("\t\t3.删除学生\n");
	printf("\t\t4.查询学生\n");
	printf("\t\t5.开始改卷\n");
	printf("\t\t6.成绩排序\n");
	printf("\t\t7.修改密码\n");
	printf("\t\t8.返回上一级\n");
	printf("\t\t9.退出系统\n");
	printf("--------------------------------------------\n");
	printf("请输入：");
}

//实现主界面用户交互
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
		if (userMainKey >= '1' && userMainKey <= '3') {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userMainKey) {//主界面交互
	case '1':
		stuPass();
		system("cls");
		while (1) {
			makeStuMenu();
			keyStuDown();
			if (endSign == 1) {//如果用户选择返回上一级
				system("cls");
				break;//结束学生界面的循环，相当于返回上一级
			}
			system("pause");
			system("cls");
		}
		break;
	case '2':
		teacherPass();
		system("cls");
		while (1) {
			endSign = 0;
			makeTeacherMenu();
			keyTeacherDown();
			if (endSign == 1) {
				system("cls");
				break;
			}
			system("pause");
			system("cls");
		}

		break;
	case '3':
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

//实现学生界面用户交互
void keyStuDown() {
	char userKey;
	char userKey2;

	//错误判断
	while (1) {
		while (1) {
			userKey = getchar();
			if (userKey != ' ' && userKey != '\n') {
				break;
			}
		}
		getchar();
		if (userKey >= '1' && userKey <= '5') {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userKey) {
	case '1':
		exam(stuList);
		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '2':
		printf("请输入原姓名：");
		scanf("%s", name);
		getchar();
		changeByName(stuList, name);
		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '3':
		stuChangePwd();
		break;
	case '4':
		endSign = 1;
		break;
	case '5':
		printf("退出成功！");
		system("pause");
		exit(0);
		break;
	default:
		printf("学生界面输入错误，请重试！");
	}
}

//实现教师界面用户交互
void keyTeacherDown() {
	char userKey;
	char userKey2;

	//错误判断
	while (1) {
		while (1) {
			userKey = getchar();
			if (userKey != ' ' && userKey != '\n') {
				break;
			}
		}
		getchar();
		if (userKey >= '1' && userKey <= '9') {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	switch (userKey) {
	case '1':
		printTimuList(timuList);
		break;
	case '2':
		printStuList(stuList);
		break;
	case '3':
		//userKey2 = -1;
		printf("请输入想根据什么删除（1:专业  2：班级  3：姓名  0:返回）：");

		//错误判断
		while (1) {
			while (1) {
				userKey2 = getchar();
				if (userKey2 != ' ' && userKey2 != '\n') {
					break;
				}
			}
			getchar();
			if (userKey2 >= '0' && userKey2 <= '3') {
				break;
			}
			else {
				puts("输入错误，请重试：");
			}
		}



			switch (userKey2) {
			case '1':
				printf("请输入想删除的专业：");
				scanf("%s", major);
				getchar();
				deleteByMajor(stuList, major);
				break;
			case '2':
				printf("请输入想删除的班级：");
				scanf("%d", &stuclass);
				getchar();
				deleteByStuclass(stuList, stuclass);
				break;
			case '3':
				printf("请输入想删除的姓名：");
				scanf("%s", name);
				getchar();
				deleteByName(stuList, name);
				break;
			case '0':
				break;
			default:
				printf("输入错误,请重新输入:");
			}
		

		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '4':
		userKey2 = 'x';
		printf("请输入想根据什么查询（1:专业  2：班级  3：姓名  4:专业+班级  0:返回）：");

		//错误判断
		while (1) {
			while (1) {//清空缓冲区
				userKey2 = getchar();
				if (userKey2 != ' ' && userKey2 != '\n') {
					break;//缓冲区已清空
				}
			}
			getchar();
			if (userKey2 >= '0' && userKey2 <= '4') {//如果用户的输入符合预期
				break;//跳出循环
			}
			else {
				puts("输入错误，请重试：");//提示重新输入，重新开始循环
			}
		}

		
			switch (userKey2) {
			case '1':
				printf("请输入想查询的专业：");
				scanf("%s", major);
				getchar();
				searchByMajor(stuList, major);
				break;
			case '2':
				printf("请输入想查询的班级：");
				scanf("%d", &stuclass);
				getchar();
				searchByStuclass(stuList, stuclass);
				break;
			case '3':
				printf("请输入想查询的姓名：");
				scanf("%s", name);
				getchar();
				searchByName(stuList, name);
				break;
			case '4':
				printf("请先输入想查询的专业：");
				scanf("%s", major);
				getchar();
				printf("请再输入想查询的班级：");
				scanf("%d", &stuclass);
				getchar();
				searchByMajorStuclass(stuList, major, stuclass);
				break;
			case '0':
				break;
			default:
				printf("输入错误，请重新输入：");
			}

		break;
	case '5':
		examTeacher(timuList, stuList);

		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '6':
		
		sort(stuList);

		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '7':
		teacherChangePwd();
		break;
	case '8':
		endSign = 1;
		break;
	case '9':
		printf("退出成功！");
		system("pause");
		exit(0);
		break;
	default:
		printf("主页面输入错误，请重试！");
	}
}
