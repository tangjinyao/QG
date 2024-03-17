#include "common.h"
#include "stu.h"
#include <stdio.h>
#include <string.h>

//#include "tools.c"

//录入题目
void inputTimu(timuNode* timuList) {
	int i;
	for (i = 1; i <= 1; i++) {
		Timu timu;
		printf("目前正在录入第%d条题目：\n", i);
		printf("请输入题目,答案，分值：");
		//scanf("%s", timu.sentence);
		fgets(timu.sentence, MAX_SENTENCE, stdin);
		timu.sentence[strlen(timu.sentence) - 1] = '\0';
		while ((timu.answer = getchar()) == ' ');
		//printf("请输入答案：");
		//scanf("%c", &timu.answer);
		//printf("请输入分值：");
		scanf("%d", &timu.score);

		insertTimuByHead(timuList, timu);
	}
}

//添加许多学生
void inputManyStu(stuNode* stuList) {
	int i;
	for (i = 1; i <= 1; i++) {
		Student stu;
		printf("目前正在录入第%d个学生：\n", i);
		printf("请输入专业：");
		scanf("%s", stu.major);
		getchar();
		printf("请输入班级：");
		scanf("%d", &stu.stuclass);
		getchar();
		printf("请输入姓名：");
		scanf("%s", stu.name);

		insertStuByHead(stuList, stu);
	}
}

//添加单个学生
void inputSingleStu(stuNode* stuList) {
		Student stu;
		printf("请输入专业：");
		scanf("%s", stu.major);
		getchar();
		printf("请输入班级：");
		scanf("%d", &stu.stuclass);
		getchar();
		printf("请输入姓名：");
		scanf("%s", stu.name);

		insertStuByHead(stuList, stu);
}

//学生答题
void exam(stuNode* stuList) {
	int i = -1;//记录当前是第几道题（从0开始）

	Student stu;
	printf("请输入专业：");
	scanf("%s", stu.major);
	getchar();
	printf("请输入班级：");
	scanf("%d", &stu.stuclass);
	getchar();
	printf("请输入姓名：");
	scanf("%s", stu.name);
	stu.stuScore = 0;

	timuNode* pMove = timuList->next;
	while (pMove != NULL) {
		i++;
		//输出题目，学生作答
		getchar();
		printf("%s\t你的答案（Y表示正确，N表示错误）：", pMove->timu.sentence);
		scanf("%c", &stu.stuAnswer[i]);

		//回答正确加分
		if (stu.stuAnswer[i] == pMove->timu.answer) {
			stu.stuScore += pMove->timu.score;
		}

		pMove = pMove->next;
	}
	stu.stuAnswer[i + 1] = '\0';
	printf("考试结束，你的成绩是：%d!", stu.stuScore);
	insertStuByHead(stuList, stu);
}

//教师改卷
void examTeacher(timuNode* timuList, stuNode* stuList) {
	int i;//循环变量 
	timuNode* pTimuMove = timuList->next; //定义两个指针pTimuNode和pStuNode, 分别指向题目链表和学生链表的头节点的下一个结点
	stuNode* pStuMove = stuList->next;
	
	while (pStuMove != NULL) {//使用while循环遍历学生链表，直到达到链表的末尾
		pStuMove->stu.stuScore = 0;//将学生结点的分数初始化为0
		pTimuMove = timuList->next;
		for (i = 0; i < NUM_TIMU; i++) {//对于每个学生结点，遍历题目链表
			if (pStuMove->stu.stuAnswer[i] == pTimuMove->timu.answer) {//对于每个题目结点，检查学生的答案是否与题目的答案相同
				pStuMove->stu.stuScore += pTimuMove->timu.score;//如果答案相同，则将该题目的分数加到学生的总分上
			}
			pTimuMove = pTimuMove->next;
		}

		pStuMove = pStuMove->next;//在完成当前学生的分数计算后，移动指针到下一个学生结点
	}
	printf("改卷完成！");
}
