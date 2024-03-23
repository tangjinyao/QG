#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "func.c" 

LinkStack* s = NULL;//声明一个结构体存储栈的信息
Status result;//记录函数返回值
ElemType elem;//p节点的值
ElemType* e = &elem;//存储元素值的指针
int length;
int* pl = &length;
char arr1[200];//存储用户输入的表达式(中缀表达式)
char arr2[200];//存储转换后的后缀表达式
char ch = '\0';
LinkStack* s2 = NULL;

void makeMainMenu();
void keyMainDown();

void trans(char* arr1, LinkStack* s, char* arr2, int* size);
void cacul(char* arr2, int* size);

int main() {
	InitLStack(&s);
	InitLStack(&s2);
	while (1) {
		memset(arr1, '\0', sizeof(arr1));
		memset(arr2, '\0', sizeof(arr2));
		makeMainMenu();
		keyMainDown();
		system("pause");
		system("cls");
	}
}

void makeMainMenu() {
	printf("请输入表达式: ");
}

void keyMainDown() {
	scanf("%s", arr1);
	int size = 1;
	trans(arr1, s, arr2, &size);
	cacul(arr2, &size);
}

void trans(char* arr1, LinkStack* s, char* arr2, int* size) {
	char* p = arr1;
	char* q = arr2;
	while (*p != '\0' && *size == 1) {
		switch (*p) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		case '.':
			*q = *p;
			q++;

			ch = *(p + 1);
			if ((ch < '0' || ch > '9') && ch != '.') {
				*q = ' ';
				q++;
			}


			break;
		case '(':
			pushLStack(s, *p);
			break;
		case ')':
			result = popLStack(s, &ch);
			while (ch != '(') {
				if (result == ERROR) {
					*size = 0;
					printf("表达式有误!\n");
					break;
				}
				*q = ch;
				q++;

				*q = ' ';
				q++;

				popLStack(s, &ch);
			}
			break;
		case '*':
		case '/':
			getTopLStack(s, &ch);
			while (ch == '*' || ch == '/') {
				popLStack(s, &ch);

				*q = ' ';
				q++;

				*q = ch;
				q++;
			}
			pushLStack(s, *p);
			
			break;
		case '+':
		case '-':
			getTopLStack(s, &ch);
			while (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
				popLStack(s, &ch);

				*q = ch;
				q++;

				*q = ' ';
				q++;

				getTopLStack(s, &ch);
			}
			pushLStack(s, *p);
			break;
		case ' ':
			break;
		default:
			printf("表达式输入有误!\n");
			*size = 0;
			break;
		}
		p++;
	}

	while (isEmptyLStack(s) == ERROR && *size == 1) {
		popLStack(s, &ch);
		*q = ch;
		q++;

		*q = ' ';
		q++;
	}

	if(*size == 1) printf("后缀表达式为: %s\n", arr2);
}

void cacul(char* arr2, int* size) {
	char* q = arr2;
	double number = 0;
	while (*q != '\0' && *size == 1) {
		if (*q >= '0' && *q <= '9') {

			char* p = q;
			while (*p != ' ') {
				p++;
			}

			sscanf(q, "%lf", &number);
			pushLStack2(s2, number);

			q = p;
		}
		
		if (*q == '+' || *q == '-' || *q == '*' || *q == '/') {
			int result;
			double num2; 
			result = popLStack2(s2, &num2);
			if (result == ERROR) {
				printf("表达式有误!\n");
				*size = 0;
				break;
			}
			double num1; 
			result = popLStack2(s2, &num1);
			if (result == ERROR) {
				printf("表达式有误!\n");
				*size = 0;
				break;
			}
			switch (*q) {
			case '+':
				pushLStack2(s2, num1 + num2);
				break;
			case '-':
				pushLStack2(s2, num1 - num2);
				break;
			case '*':
				pushLStack2(s2, num1 * num2);
				break;
			case '/':
				if (num2 == 0) {
					printf("除数不能为零!\n");
					*size = 0;
					break;
				}
				pushLStack2(s2, num1 / num2);
				break;
			}
		}
		q++;
	}
	if (*size == 0) {
		return;
	}
	double ans;
	popLStack2(s2, &ans);
	printf("结果为: %.3lf\n", ans);
}
