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

void makeMainMenu();//����������
void makeStuMenu();//����ѧ������
void makeTeacherMenu();//������ʦ����

void keyMainDown();//�����潻��
void keyStuDown();//ѧ�����潻��
void keyTeacherDown();//��ʦ���潻��

int main() {
	//����һ��������Ŀ��
	timuList = creatTimuHead();
	//����һ������ѧ����
	stuList = creatStuHead();

	//����
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

//����������
void makeMainMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.ѧ����¼\n");
	printf("\t\t2.��ʦ��¼\n");
	printf("\t\t3.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

void makeStuMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.ѧ������\n");
	printf("\t\t2.�޸�ѧ��\n");
	printf("\t\t3.�޸�����\n");
	printf("\t\t4.������һ��\n");
	printf("\t\t5.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

void makeTeacherMenu() {
	printf("--------------------------------------------\n");
	printf("\t\t1.��ʾ������Ŀ\n");
	printf("\t\t2.��ʾ����ѧ��\n");
	printf("\t\t3.ɾ��ѧ��\n");
	printf("\t\t4.��ѯѧ��\n");
	printf("\t\t5.��ʼ�ľ�\n");
	printf("\t\t6.�ɼ�����\n");
	printf("\t\t7.�޸�����\n");
	printf("\t\t8.������һ��\n");
	printf("\t\t9.�˳�ϵͳ\n");
	printf("--------------------------------------------\n");
	printf("�����룺");
}

//ʵ���������û�����
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
		if (userMainKey >= '1' && userMainKey <= '3') {
			break;
		}
		else {
			puts("������������ԣ�");
		}
	}

	switch (userMainKey) {//�����潻��
	case '1':
		stuPass();
		system("cls");
		while (1) {
			makeStuMenu();
			keyStuDown();
			if (endSign == 1) {//����û�ѡ�񷵻���һ��
				system("cls");
				break;//����ѧ�������ѭ�����൱�ڷ�����һ��
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

//ʵ��ѧ�������û�����
void keyStuDown() {
	char userKey;
	char userKey2;

	//�����ж�
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
			puts("������������ԣ�");
		}
	}

	switch (userKey) {
	case '1':
		exam(stuList);
		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '2':
		printf("������ԭ������");
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
		printf("�˳��ɹ���");
		system("pause");
		exit(0);
		break;
	default:
		printf("ѧ������������������ԣ�");
	}
}

//ʵ�ֽ�ʦ�����û�����
void keyTeacherDown() {
	char userKey;
	char userKey2;

	//�����ж�
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
			puts("������������ԣ�");
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
		printf("�����������ʲôɾ����1:רҵ  2���༶  3������  0:���أ���");

		//�����ж�
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
				puts("������������ԣ�");
			}
		}



			switch (userKey2) {
			case '1':
				printf("��������ɾ����רҵ��");
				scanf("%s", major);
				getchar();
				deleteByMajor(stuList, major);
				break;
			case '2':
				printf("��������ɾ���İ༶��");
				scanf("%d", &stuclass);
				getchar();
				deleteByStuclass(stuList, stuclass);
				break;
			case '3':
				printf("��������ɾ����������");
				scanf("%s", name);
				getchar();
				deleteByName(stuList, name);
				break;
			case '0':
				break;
			default:
				printf("�������,����������:");
			}
		

		saveStuFile(stuList, FILE_URL_STU);
		break;
	case '4':
		userKey2 = 'x';
		printf("�����������ʲô��ѯ��1:רҵ  2���༶  3������  4:רҵ+�༶  0:���أ���");

		//�����ж�
		while (1) {
			while (1) {//��ջ�����
				userKey2 = getchar();
				if (userKey2 != ' ' && userKey2 != '\n') {
					break;//�����������
				}
			}
			getchar();
			if (userKey2 >= '0' && userKey2 <= '4') {//����û����������Ԥ��
				break;//����ѭ��
			}
			else {
				puts("������������ԣ�");//��ʾ�������룬���¿�ʼѭ��
			}
		}

		
			switch (userKey2) {
			case '1':
				printf("���������ѯ��רҵ��");
				scanf("%s", major);
				getchar();
				searchByMajor(stuList, major);
				break;
			case '2':
				printf("���������ѯ�İ༶��");
				scanf("%d", &stuclass);
				getchar();
				searchByStuclass(stuList, stuclass);
				break;
			case '3':
				printf("���������ѯ��������");
				scanf("%s", name);
				getchar();
				searchByName(stuList, name);
				break;
			case '4':
				printf("�����������ѯ��רҵ��");
				scanf("%s", major);
				getchar();
				printf("�����������ѯ�İ༶��");
				scanf("%d", &stuclass);
				getchar();
				searchByMajorStuclass(stuList, major, stuclass);
				break;
			case '0':
				break;
			default:
				printf("����������������룺");
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
		printf("�˳��ɹ���");
		system("pause");
		exit(0);
		break;
	default:
		printf("��ҳ��������������ԣ�");
	}
}
