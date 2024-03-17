#ifndef _STU_H
#define _STU_H

#include <stdlib.h>
#include "common.h"
#include <assert.h>



//����ṹ�壨��Ŀ��
typedef struct _Timu {
	char sentence[MAX_SENTENCE];//ԭ��
	char answer;//��
	int score;//����
}Timu;

//����ṹ�壨ѧ����
typedef struct _Student {
	char major[MAX_MAJOR];//רҵ
	int stuclass;//�༶
	char name[20];//����
	char stuAnswer[NUM_TIMU + 5];//ѧ���Ĵ𰸣����±�1��ʼ�洢��
	int stuScore;//ѧ���ĳɼ�
}Student;

//���������е�ÿ���ڵ㣨��Ŀ��
typedef struct _timuNode {
	Timu timu;
	struct _timuNode* next;
}timuNode;



//���������е�ÿ���ڵ㣨ѧ����
typedef struct _stuNode {
	Student stu;
	struct _stuNode* next;
}stuNode;

//������������
extern timuNode* timuList;
extern stuNode* stuList;

//���������ɾ���
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

//�������
extern void getpwd(char* pwd, int pwdlen);
extern void stuPass();
extern void teacherPass();
extern void stuChangePwd();
extern void teacherChangePwd();

#endif