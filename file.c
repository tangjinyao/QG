#include "common.h"
#include "stu.h"
#include <stdio.h>
#include <string.h>

#include "tools.c"


//读档（题目）
void readTimuFile(timuNode* headNode, char* fileURL) {
	FILE* fpTimu = fopen(fileURL, "r");
	Timu timu;
	if (fpTimu == NULL) {
		fpTimu = fopen(fileURL, "w+");
		fclose(fpTimu);
		return;
	}
	while (fscanf(fpTimu, "%s\t%c\t%d\n", timu.sentence, &timu.answer, &timu.score) != EOF) {
		insertTimuByHead(timuList, timu);
	}
	fclose(fpTimu);
}

//读档（学生）
void readStuFile(stuNode* headNode, char* fileURL) {
	FILE* fpStu = fopen(fileURL, "r");
	Student stu;
	if (fpStu == NULL) {
		fpStu = fopen(fileURL, "w+");
		fclose(fpStu);
		return;
	}
	while (fscanf(fpStu, "%s\t%d\t%s\t%s\t%d\n", 
		stu.major,
		&stu.stuclass, 
		stu.name,
		stu.stuAnswer,
		&stu.stuScore) != EOF) 
	{
		insertStuByHead(stuList, stu);
	}
	fclose(fpStu);
}

//读档（学生教师密码）
void readPwdFile(char* pwd, char* fileURL) {
	FILE* fpPwd;
	if ((fpPwd = fopen(fileURL, "r")) == NULL) {
		printf("密码文件打开失败！");
		system("pause");
		exit(0);
	}
	fscanf(fpPwd, "%s\n", pwd);
	fclose(fpPwd);
}


//存档（题目）
void saveTimuFile(timuNode* headNode, char* fileURL) {
	FILE* fpTimu = fopen(fileURL, "w");
	Timu timu;
	timuNode* pMove = headNode->next;
	while (pMove != NULL) {
		fprintf(fpTimu, "%s\t%c\t%d\n", pMove->timu.sentence, pMove->timu.answer, pMove->timu.score);
		pMove = pMove->next;
	}
}

//存档（学生）
void saveStuFile(stuNode* headNode, char* fileURL) {
	FILE* fpStu = fopen(fileURL, "w");//打开文件
	Student stu;
	stuNode* pMove = headNode->next;//设置指向结点的指针
	while (pMove != NULL) {
		fprintf(fpStu, "%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n", 
			pMove->stu.major, 
			pMove->stu.stuclass, 
			pMove->stu.name,
			pMove->stu.stuAnswer,
			pMove->stu.stuScore
		);//将链表的当前结点保存至文件
		pMove = pMove->next;//结点移动至下一个
	}
}

//存档（密码）
void savePwdFile(char* pwd, const char* fileURL) {
	FILE* fpPwd = fopen(fileURL, "w");
	fprintf(fpPwd, "%s\n", pwd);
}
