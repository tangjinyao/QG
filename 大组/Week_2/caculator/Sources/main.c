#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "calculate.h"
#include "func.c" 

LinkStack* s = NULL;//����һ���ṹ��洢ջ����Ϣ
Status result;//��¼��������ֵ
ElemType elem;//p�ڵ��ֵ
ElemType* e = &elem;//�洢Ԫ��ֵ��ָ��
int length;
int* pl = &length;
char arr1[200];//�洢�û�����ı��ʽ(��׺���ʽ)
char arr2[200];//�洢ת����ĺ�׺���ʽ
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
	printf("��������ʽ: ");
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
					printf("���ʽ����!\n");
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
			printf("���ʽ��������!\n");
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

	if(*size == 1) printf("��׺���ʽΪ: %s\n", arr2);
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
				printf("���ʽ����!\n");
				*size = 0;
				break;
			}
			double num1; 
			result = popLStack2(s2, &num1);
			if (result == ERROR) {
				printf("���ʽ����!\n");
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
					printf("��������Ϊ��!\n");
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
	printf("���Ϊ: %.3lf\n", ans);
}
