#ifndef _COMMON_H
#define _COMMON_H

//以下参数不可调
#define NUM_TIMU 4//一共有几道题目
#define NUM_TIMU_CHOOSE 4//一共有几道选择题

//以下参数可调
#define MAX_SENTENCE 13//每道题目的最大长度
#define MAX_MAJOR 20//学生专业的最大长度
#define MAX_NAME 20//学生名字的最大长度
#define FILE_URL_TIMU "./timu.txt"//题目存储的位置
#define FILE_URL_STU "./stu.txt"//学生信息存储的位置
#define FILE_URL_STUPWD "./pwdStu.txt"//学生密码存储的位置
#define FILE_URL_TEACHERPWD "./pwdTeacher.txt"//教师密码存储的位置
#define MAX_PWD 10//密码长度最大不超过10
#define TRY 3//最多尝试密码的次数

//以下为一些全局变量的定义
char name[MAX_NAME];
char major[MAX_MAJOR];
int stuclass;
char ch;
int endSign;
char stuPwd[MAX_PWD];//存储真正的学生密码
char teacherPwd[MAX_PWD];//存储真正的教师密码 

#endif
