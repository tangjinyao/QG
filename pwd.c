#include "common.h"
#include "stu.h"
#include "file.h"
#include <stdio.h>
#include <string.h>

//#include "file.c"

//��ȡ���������
void getpwd(char* pwd, int pwdlen) {
    char ch = 0;//����ÿ��������ַ�
    int i = 0;//��¼��ǰ������ַ���λ��
    while (i < pwdlen) {
        ch = getch();

        if (ch == '\r') {  //�س���������
            printf("\n");
            break;
        }

        if (ch == '\b' && i > 0) {  //����ɾ����
            i--;
            printf("\b \b");
        }
        else if (isprint(ch)) {  //����ɴ�ӡ�ַ�
            pwd[i] = ch;
            printf("*");
            i++;
        }   
    }
    pwd[i] = 0;
}

//�������빦�ܣ�ѧ����
void stuPass() {
    int trys = TRY;
    int enter = 0;
    char stuPwd2[MAX_PWD];
    while (trys > 0) {
        printf("������ѧ�����룺");
        getpwd(stuPwd2, MAX_PWD);
        if (strcmp(stuPwd, stuPwd2) == 0) {
            enter = 1;
            break;
        }
        trys--;
        printf("������󣡻�ʣ%d�λ��ᣡ\n", trys);
    }
    if (enter == 0) {
        printf("%d�λ����þ��������˳�����", TRY);
        system("pause");
        exit(0);
    }
}

//�������빦�ܣ���ʦ��
void teacherPass() {
    int trys = TRY;
    int enter = 0;
    char teacherPwd2[MAX_PWD];
    while (trys > 0) {
        printf("�������ʦ���룺");
        getpwd(teacherPwd2, MAX_PWD);
        if (strcmp(teacherPwd, teacherPwd2) == 0) {
            enter = 1;
            break;
        }
        trys--;
        printf("������󣡻�ʣ%d�λ��ᣡ\n", trys);
    }
    if (enter == 0) {
        printf("%d�λ����þ��������˳�����", TRY);
        system("pause");
        exit(0);
    }
}

//�޸����루ѧ����
void stuChangePwd() {
    int sign = 0;
    char Pwd1[MAX_PWD];//���������ַ����飬���ڴ洢���������������
    char Pwd2[MAX_PWD];
    while (1) {
        printf("�����������룺");
        getpwd(Pwd1, MAX_PWD);
        printf("���ٴ����������룺");
        getpwd(Pwd2, MAX_PWD);
        if (strcmp(Pwd1, Pwd2) == 0) {//�Ƚ��Ƿ�һ��
            sign = 1;
            break;
        }
        else {
            printf("������������벻һ�������������룡\n");
        }
    }
    if (sign == 1) {//���һ��
        strcpy(stuPwd, Pwd1);//�������븴�Ƶ�stuPwd��
        savePwdFile(stuPwd, FILE_URL_STUPWD);//�������뱣�����ļ�
        printf("�޸�����ɹ���");
    }
}

//�޸����루��ʦ��
void teacherChangePwd() {
    int sign = 0;
    char Pwd1[MAX_PWD];
    char Pwd2[MAX_PWD];
    while (1) {
        printf("�����������룺");
        getpwd(Pwd1, MAX_PWD);
        printf("���ٴ����������룺");
        getpwd(Pwd2, MAX_PWD);
        if (strcmp(Pwd1, Pwd2) == 0) {
            sign = 1;
            break;
        }
        else {
            printf("������������벻һ�������������룡\n");
        }
    }
    if (sign == 1) {
        strcpy(teacherPwd, Pwd1);
        savePwdFile(teacherPwd, FILE_URL_TEACHERPWD);
        printf("�޸�����ɹ���");
    }
}

