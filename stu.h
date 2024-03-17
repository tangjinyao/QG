#ifndef _STU_H
#define _STU_H

#include <stdlib.h>
#include "common.h"
#include <assert.h>



//定义结构体（题目）
typedef struct _Timu {
	char sentence[MAX_SENTENCE];//原题
	char answer;//答案
	int score;//分数
}Timu;

//定义结构体（学生）
typedef struct _Student {
	char major[MAX_MAJOR];//专业
	int stuclass;//班级
	char name[20];//姓名
	char stuAnswer[NUM_TIMU + 5];//学生的答案（从下标1开始存储）
	int stuScore;//学生的成绩
}Student;

//定义链表中的每个节点（题目）
typedef struct _timuNode {
	Timu timu;
	struct _timuNode* next;
}timuNode;



//定义链表中的每个节点（学生）
typedef struct _stuNode {
	Student stu;
	struct _stuNode* next;
}stuNode;

//定义两个链表
extern timuNode* timuList;
extern stuNode* stuList;

//对链表的增删查改
extern timuNode* creatTimuHead();
extern stuNode* creatStuHead();
extern timuNode* creatTimuNew(Timu timu);
extern stuNode* creatStuNew(Student stu);
extern void insertTimuByHead(timuNode* headNode, Timu timu);
extern void insertStuByHead(stuNode* headNode, Student stu);
extern void printTimuList(timuNode* headNode);
extern void printStuList(stuNode* headNode);
extern void deleteByMajor(stuNode* headNode, char* major);
extern void deleteByStuclass(stuNode* headNode, int stuclass);
extern void deleteByName(stuNode* headNode, char* name);
extern void searchByMajor(stuNode* headNode, char* major);
extern void searchByStuclass(stuNode* headNode, int stuclass);
extern void searchByName(stuNode* headNode, char* name);
extern void searchByMajorStuclass(stuNode* headNode, char* major, int stuclass);
extern void changeByName(stuNode* headNode, char* name);
extern void sort(stuNode* stuList);
extern void sortStuLower(stuNode* stuList);
extern void sortStuHigher(stuNode* stuList);


extern void inputTimu(timuNode* timuList);
extern void inputManyStu(stuNode* stuList);
extern void inputSingleStu(stuNode* stuList);
extern void exam(stuNode* stuList);
extern void examTeacher(timuNode* timuList, stuNode* stuList);

//密码相关
extern void getpwd(char* pwd, int pwdlen);
extern void stuPass();
extern void teacherPass();
extern void stuChangePwd();
extern void teacherChangePwd();

#endif