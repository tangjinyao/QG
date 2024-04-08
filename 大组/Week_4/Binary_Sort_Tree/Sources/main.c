#include <stdio.h>
#include <stdlib.h>

#include "binary_sort_tree.h"

#include "binary_sort_tree.c" 

BinarySortTree BST;//����һ������������
Status result;//��¼��������ֵ
ElemType elem;//p�ڵ��ֵ
int sign = 0;//����Ƿ��˳������˵�

void makeMainMenu();//����������
void keyMainDown();//�����潻��

void makeSubMenu();//���������˵�
void keySubDown();//�����˵�����

//���ʽڵ�
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
	printf("\t\t1.��ʼ������������\n");
	printf("\t\t2.��������\n");
	printf("\t\t3.ɾ������\n");
	printf("\t\t4.��������\n");
	printf("\t\t5.����\n");
	printf("\t\t#.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

void keyMainDown() {
	char userMainKey = 0;
	char userKey2 = 0;

	//�����ж�
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
			puts("������������ԣ�");
		}
	}

	switch (userMainKey) {//�����潻��
	case '1':
		system("cls");
		BST_init(&BST);//��ʼ������������

		generateTestData(&BST);//���ɲ�������

		printf("��ʼ���ɹ�!\n");
		printf("���β������ݣ�5,3,7,2,4,6,8\n");

		break;
	case '2':
		system("cls");

		printf("������Ҫ��������ݣ�int���ͣ�:\n");
		scanf("%d", &elem);
		result = BST_insert(&BST, elem);
		if (result == succeed) {
			printf("����ɹ�!\n");
		}
		else {
			printf("�������и����ݣ�����ʧ��\n");
		}

		break;
	case '3':
		system("cls");

		printf("������Ҫɾ��������:\n");
		scanf("%d", &elem);
		result = BST_delete(&BST, elem);
		if (result == succeed) {
			printf("ɾ���ɹ�!\n");
		}
		else {
			printf("���������ڣ�ɾ��ʧ��\n");
		}

		break;
	case '4':
		system("cls");

		printf("������Ҫ���ҵ�����:\n");
		scanf("%d", &elem);
		result = BST_search(&BST, elem);
		if (result == succeed) {
			printf("���ҳɹ�!\n");
		}
		else {
			printf("���������ڣ�����ʧ��\n");
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
		printf("�˳��ɹ���");
		system("pause");
		exit(0);
		break;
	default:
		printf("��ҳ��������������ԣ�");
		system("pause");
		system("cls");
	}
}

//�����˵�����
void makeSubMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.ǰ�����(�ǵݹ�)\n");
	printf("\t\t2.ǰ�����(�ݹ�)\n");
	printf("\t\t3.�������(�ǵݹ�)\n");
	printf("\t\t4.�������(�ݹ�)\n");
	printf("\t\t5.�������(�ǵݹ�)\n");
	printf("\t\t6.�������(�ݹ�)\n");
	printf("\t\t7.��α���\n");
	printf("\t\t#.�������˵�\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

//�����˵�����
void keySubDown() {
	char userSubKey = 0;

	//�����ж�
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
			puts("������������ԣ�");
		}
	}

	switch (userSubKey) {//�����˵�����
	case '1':
		system("cls");
		//ǰ�����(�ǵݹ�)
		BST_preorderI(&BST, visit);
		break;
	case '2':
		system("cls");
		//ǰ�����(�ݹ�)
		BST_preorderR(BST.root, visit);
		break;
	case '3':
		system("cls");
		//�������(�ǵݹ�)
		BST_inorderI(&BST, visit);
		break;
	case '4':
		system("cls");
		//�������(�ݹ�)
		BST_inorderR(BST.root, visit);
		break;
	case '5':
		system("cls");
		//�������(�ǵݹ�)
		BST_postorderI(&BST, visit);
		break;
	case '6':
		system("cls");
		//�������(�ݹ�)
		BST_postorderR(BST.root, visit);
		break;
	case '7':
		system("cls");
		//��α���
		BST_levelOrder(&BST, visit);
		break;
	case '#':
		system("cls");
		printf("���سɹ���\n");
		sign = 1;
		break;
	default:
		printf("������������ԣ�");
		system("pause");
		system("cls");
	}
}
