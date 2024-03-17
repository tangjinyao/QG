#include "common.h"
#include "stu.h"
#include <stdio.h>
#include <string.h>

#include "tools.c"


//��������Ŀ��
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

//������ѧ����
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

//������ѧ����ʦ���룩
void readPwdFile(char* pwd, char* fileURL) {
	FILE* fpPwd;
	if ((fpPwd = fopen(fileURL, "r")) == NULL) {
		printf("�����ļ���ʧ�ܣ�");
		system("pause");
		exit(0);
	}
	fscanf(fpPwd, "%s\n", pwd);
	fclose(fpPwd);
}


//�浵����Ŀ��
void saveTimuFile(timuNode* headNode, char* fileURL) {
	FILE* fpTimu = fopen(fileURL, "w");
	Timu timu;
	timuNode* pMove = headNode->next;
	while (pMove != NULL) {
		fprintf(fpTimu, "%s\t%c\t%d\n", pMove->timu.sentence, pMove->timu.answer, pMove->timu.score);
		pMove = pMove->next;
	}
}

//�浵��ѧ����
void saveStuFile(stuNode* headNode, char* fileURL) {
	FILE* fpStu = fopen(fileURL, "w");//���ļ�
	Student stu;
	stuNode* pMove = headNode->next;//����ָ�����ָ��
	while (pMove != NULL) {
		fprintf(fpStu, "%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n", 
			pMove->stu.major, 
			pMove->stu.stuclass, 
			pMove->stu.name,
			pMove->stu.stuAnswer,
			pMove->stu.stuScore
		);//������ĵ�ǰ��㱣�����ļ�
		pMove = pMove->next;//����ƶ�����һ��
	}
}

//�浵�����룩
void savePwdFile(char* pwd, const char* fileURL) {
	FILE* fpPwd = fopen(fileURL, "w");
	fprintf(fpPwd, "%s\n", pwd);
}
