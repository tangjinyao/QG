#include "common.h"
#include "stu.h"
#include "file.h"
#include <stdio.h>
#include <string.h>

//#include "file.c"

//获取输入的密码
void getpwd(char* pwd, int pwdlen) {
    char ch = 0;//储存每次输入的字符
    int i = 0;//记录当前读入的字符的位置
    while (i < pwdlen) {
        ch = getch();

        if (ch == '\r') {  //回车结束输入
            printf("\n");
            break;
        }

        if (ch == '\b' && i > 0) {  //按下删除键
            i--;
            printf("\b \b");
        }
        else if (isprint(ch)) {  //输入可打印字符
            pwd[i] = ch;
            printf("*");
            i++;
        }   
    }
    pwd[i] = 0;
}

//输入密码功能（学生）
void stuPass() {
    int trys = TRY;
    int enter = 0;
    char stuPwd2[MAX_PWD];
    while (trys > 0) {
        printf("请输入学生密码：");
        getpwd(stuPwd2, MAX_PWD);
        if (strcmp(stuPwd, stuPwd2) == 0) {
            enter = 1;
            break;
        }
        trys--;
        printf("密码错误！还剩%d次机会！\n", trys);
    }
    if (enter == 0) {
        printf("%d次机会用尽，即将退出程序！", TRY);
        system("pause");
        exit(0);
    }
}

//输入密码功能（教师）
void teacherPass() {
    int trys = TRY;
    int enter = 0;
    char teacherPwd2[MAX_PWD];
    while (trys > 0) {
        printf("请输入教师密码：");
        getpwd(teacherPwd2, MAX_PWD);
        if (strcmp(teacherPwd, teacherPwd2) == 0) {
            enter = 1;
            break;
        }
        trys--;
        printf("密码错误！还剩%d次机会！\n", trys);
    }
    if (enter == 0) {
        printf("%d次机会用尽，即将退出程序！", TRY);
        system("pause");
        exit(0);
    }
}

//修改密码（学生）
void stuChangePwd() {
    int sign = 0;
    char Pwd1[MAX_PWD];//定义两个字符数组，用于存储两次新密码的输入
    char Pwd2[MAX_PWD];
    while (1) {
        printf("请输入新密码：");
        getpwd(Pwd1, MAX_PWD);
        printf("请再次输入新密码：");
        getpwd(Pwd2, MAX_PWD);
        if (strcmp(Pwd1, Pwd2) == 0) {//比较是否一样
            sign = 1;
            break;
        }
        else {
            printf("两次输入的密码不一样，请重新输入！\n");
        }
    }
    if (sign == 1) {//如果一样
        strcpy(stuPwd, Pwd1);//将新密码复制到stuPwd中
        savePwdFile(stuPwd, FILE_URL_STUPWD);//将新密码保存至文件
        printf("修改密码成功！");
    }
}

//修改密码（教师）
void teacherChangePwd() {
    int sign = 0;
    char Pwd1[MAX_PWD];
    char Pwd2[MAX_PWD];
    while (1) {
        printf("请输入新密码：");
        getpwd(Pwd1, MAX_PWD);
        printf("请再次输入新密码：");
        getpwd(Pwd2, MAX_PWD);
        if (strcmp(Pwd1, Pwd2) == 0) {
            sign = 1;
            break;
        }
        else {
            printf("两次输入的密码不一样，请重新输入！\n");
        }
    }
    if (sign == 1) {
        strcpy(teacherPwd, Pwd1);
        savePwdFile(teacherPwd, FILE_URL_TEACHERPWD);
        printf("修改密码成功！");
    }
}

