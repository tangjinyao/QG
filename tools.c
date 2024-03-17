#include <stdio.h>
#include "stu.h"
#include <string.h>

//创建一个链表的头结点（题目）
timuNode* creatTimuHead() {
	timuNode* headNode = (timuNode*)malloc(sizeof(timuNode));
	assert(headNode);
	headNode->next = NULL;
	return headNode;
}

//创建一个链表的头结点（学生）
stuNode* creatStuHead() {
	stuNode* headNode = (stuNode*)malloc(sizeof(stuNode));
	assert(headNode);
	headNode->next = NULL;
	return headNode;
}

//创建一个链表的新结点（题目）
timuNode* creatTimuNew(Timu timu) {
	timuNode* newNode = (timuNode*)malloc(sizeof(timuNode));
	assert(newNode);
	newNode->timu = timu;
	newNode->next = NULL;
	return newNode;
}

//创建一个链表的新结点（学生）
stuNode* creatStuNew(Student stu) {
	stuNode* newNode = (stuNode*)malloc(sizeof(stuNode));
	assert(newNode);
	newNode->stu = stu;
	newNode->next = NULL;
	return newNode;
}

//头插法向链表中插入元素（题目）
void insertTimuByHead(timuNode* headNode, Timu timu) {
	timuNode* newNode = creatTimuNew(timu);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//头插法向链表中插入元素（学生）
void insertStuByHead(stuNode* headNode, Student stu) {
	stuNode* newNode = creatStuNew(stu);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//打印链表中的所有元素（题目）
void printTimuList(timuNode* headNode) {
	timuNode* pMove = headNode->next;//定义一个指针，利用while循环遍历整个题目链表
	while (pMove != NULL) {//对于每一次循环，使用printf函数输出当前指针所指的结点的内容（包括题目、答案和分数）
		printf("%s\t%c\t%d\n", pMove->timu.sentence, pMove->timu.answer, pMove->timu.score);
		pMove = pMove->next;//将指针移动至下一个结点，重复循环
	}
}

//打印链表中的所有元素（学生）
void printStuList(stuNode* headNode) {
	stuNode* pMove = headNode->next;
	int sum = 0;//统计总分
	int num = 0;//统计总人数
	int sign = 0;//标记是否打印表头
	while (pMove != NULL) {
		//若分数为-1，则该生还没有统计分数
		if (pMove->stu.stuScore >= 0) {
			sum += pMove->stu.stuScore;
			num++;
		}
		if (sign == 0) {
			sign = 1;//打印表头
			printf("专业                    班级            姓名            答案            分数\n");
		}
		printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n", //输出学生信息
			pMove->stu.major, 
			pMove->stu.stuclass, 
			pMove->stu.name,
			pMove->stu.stuAnswer,
			pMove->stu.stuScore
			);
		pMove = pMove->next;
	}
	if (num == 0) {//所有学生都没有统计分数的情况
		num = 1;
	}
	printf("总分为：%d\t平均分为：%.2f\n", sum, (float)sum / num);//打印总分和平均分
}

//批量删除链表中的元素（学生-专业）
void deleteByMajor(stuNode* headNode, char* major) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	int sign = 0;//标记是否找到符合的专业
	while (posNode != NULL) {
		if (strcmp(posNode->stu.major, major) == 0) {
			preNode->next = posNode->next;
			free(posNode);
			if (sign == 0) {//如果是第一次找到
				sign = 1;
			}
			posNode = preNode->next;//因为被free掉了，所以要重新赋值
			continue;//删除后不要着急向下移，因为删除了一个，相当于向后移了
		}
		preNode = posNode;
		posNode = preNode->next;
	}
	if (sign == 1) {
		printf("删除成功！所有该专业的学生信息已被删除！\n");
	}
	else {
		printf("找不到该专业！\n");
	}
}

//批量删除链表中的元素（学生-班级）
void deleteByStuclass(stuNode* headNode, int stuclass) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	int sign = 0;//标记是否找到符合的班级
	while (posNode != NULL) {
		if (posNode->stu.stuclass == stuclass) {
			preNode->next = posNode->next;
			free(posNode);
			if (sign == 0) {//如果是第一次找到
				sign = 1;
			}
			posNode = preNode->next;//因为被free掉了，所以要重新赋值
			continue;//删除后不要着急向下移，因为删除了一个，相当于向后移了
		}
		preNode = posNode;
		posNode = preNode->next;
	}
	if (sign == 1) {
		printf("删除成功！所有该班级的学生信息已被删除！\n");
	}
	else {
		printf("找不到该班级！\n");
	}
}

//删除链表中的元素（学生-姓名）
void deleteByName(stuNode* headNode, char* name) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {//一直循环直到找到或到链表末尾为止
		preNode = posNode;
		posNode = preNode->next;
	}
	if (posNode != NULL) {//如果还没到链表末尾，说明找到了
		preNode->next = posNode->next;//进行删除操作
		free(posNode);
		printf("删除成功！");
	}
	else {//已经到了链表末尾，说明没找到
		printf("找不到该姓名！");
	}
}

//查询链表中的元素（学生-专业）
void searchByMajor(stuNode* headNode, char* major) {
	stuNode* posNode = headNode->next;
	int sum = 0;//记录学生总分
	int num = 0;//记录有合法分数的学生人数（-1表示该学生还未登记成绩）
	int searchNum = 0;//记录查询的总结果数
	int sign = 0;//标记是否打印表头
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.major, major) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//找到了
			if (posNode->stu.stuScore >= 0) {//该学生有合法分数
				sum += posNode->stu.stuScore;//将分数加在学生总分上
				num++;//有合法分数的学生人数加一
			}
			if (sign == 0) {//判断是否打印表头
				sign = 1;
				printf("专业                    班级            姓名            答案            分数\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//输出学生信息
			searchNum++;//查询的总结果数加一
			posNode = posNode->next;//将指针移至下一个结点
		}
	}

	if (searchNum != 0) {//有符合条件的学生
		if (num == 0) {//如果所有学生都没有分数
			num = 1;//为了保证除数不为零
		}
		printf("总分为：%d\t平均分为：%.2f\n", sum, (float)sum / num);
		printf("共%d条结果！", searchNum);
	}
	else {
		printf("没有找到相关结果！");
	}
}

//查询链表中的元素（学生-班级）
void searchByStuclass(stuNode* headNode, int stuclass) {
	stuNode* posNode = headNode->next;
	int sum = 0;//记录学生总分
	int num = 0;//记录有合法分数的学生人数（-1表示该学生还未登记成绩）
	int searchNum = 0;//记录查询的总结果数
	int sign = 0;//标记是否打印表头
	while (posNode != NULL) {
		while (posNode != NULL && posNode->stu.stuclass != stuclass) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//找到了
			if (posNode->stu.stuScore >= 0) {//该学生有合法分数
				sum += posNode->stu.stuScore;//将分数加在学生总分上
				num++;//有合法分数的学生人数加一
			}
			if (sign == 0) {//判断是否打印表头
				sign = 1;
				printf("专业                    班级            姓名            答案            分数\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//输出学生信息
			searchNum++;//查询的总结果数加一
			posNode = posNode->next;//将指针移至下一个结点
		}
	}

	if (searchNum != 0) {//有符合条件的学生
		if (num == 0) {//如果所有学生都没有分数
			num = 1;//为了保证除数不为零
		}
		printf("总分为：%d\t平均分为：%.2f\n", sum, (float)sum / num);
		printf("共%d条结果！", searchNum);
	}
	else {
		printf("没有找到相关结果！");
	}
}



//查询链表中的元素（学生-姓名）
void searchByName(stuNode* headNode, char* name) {
	stuNode* posNode = headNode->next;
	int sum = 0;//记录学生总分
	int num = 0;//记录有合法分数的学生人数（-1表示该学生还未登记成绩）
	int searchNum = 0;//记录查询的总结果数
	int sign = 0;//标记是否打印表头
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//找到了
			if (posNode->stu.stuScore >= 0) {//该学生有合法分数
				sum += posNode->stu.stuScore;//将分数加在学生总分上
				num++;//有合法分数的学生人数加一
			}
			if (sign == 0) {//判断是否打印表头
				sign = 1;
				printf("专业                    班级            姓名            答案            分数\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//输出学生信息
			searchNum++;//查询的总结果数加一
			posNode = posNode->next;//将指针移至下一个结点
		}
	}

	if (searchNum != 0) {//有符合条件的学生
		//if (num == 0) {//如果所有学生都没有分数
		//	num = 1;//为了保证除数不为零
		//}
		//printf("总分为：%d\t平均分为：%.2f\n", sum, (float)sum / num);
		printf("共%d条结果！", searchNum);
	}
	else {
		printf("没有找到相关结果！");
	}
}

//查询链表中的元素（学生-专业+班级）
void searchByMajorStuclass(stuNode* headNode, char* major, int stuclass) {
	stuNode* posNode = headNode->next;
	int sum = 0;//记录查询的总结果数
	int sign = 0;//标记是否打印表头
	while (posNode != NULL) {
		while (posNode != NULL 
			&& (strcmp(posNode->stu.major, major) != 0 
			|| posNode->stu.stuclass != stuclass ) ) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {
			if (sign == 0) {
				sign = 1;
				printf("专业                    班级            姓名            答案            分数\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);
			sum++;
			posNode = posNode->next;
		}
	}
	if (sum != 0) {
		printf("共%d条结果！", sum);
	}
	else {
		printf("没有找到相关结果！");
	}
}

//修改链表中的元素（学生-依据姓名）
void changeByName(stuNode* headNode, char* name) {
	stuNode* posNode = headNode->next;
	int sum = 0;//标志是否找到
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//找到了
			printf("请输入新专业：");
			scanf("%s", posNode->stu.major);
			getchar();
			printf("请输入新班级：");
			scanf("%d", &posNode->stu.stuclass);
			getchar();
			printf("请输入新姓名：");
			scanf("%s", posNode->stu.name);
			getchar();
			posNode = posNode->next;
			sum++;
		}
	}
	if (sum != 0) {//如果找到了
		printf("修改成功！\n");
	}
	else {
		printf("没有找到相关结果！\n");
	}
}

//

//排序通用函数
void sort(stuNode* stuList) {
	int sign;
	void (*p)(stuNode*);
	//输出提示语
	printf("--------------------------------------------\n");
	printf("\t\t1.降序\n");
	printf("\t\t2.升序\n");
	printf("--------------------------------------------\n");
	printf("请输入：");

	//错误判断
	while (1) {
		while (1) {
			sign = getchar();
			if (sign != ' ' && sign != '\n') {
				break;
			}
		}
		getchar();
		if (sign >= '1' && sign <= '2') {
			break;
		}
		else {
			puts("输入错误，请重试：");
		}
	}

	//依据用户输入给函数指针赋值
	if (sign == '1') {
		p = sortStuLower;
	}
	else if(sign == '2') {
		p = sortStuHigher;
	}
	p(stuList);//调用函数指针指向的函数
}

//冒泡排序（降序）
void sortStuLower(stuNode* stuList) {
	stuNode* save = NULL;
	stuNode* move = NULL;
	stuNode* turn;//循环变量 
	for (turn = stuList->next; turn->next != NULL; turn = turn->next) {
		for (move = stuList->next; move->next != save; move = move->next) {
			if (move->stu.stuScore < move->next->stu.stuScore) {//如果当前节点比下一个小
				Student stuTemp;//使用一个临时指针实现两节点交换
				stuTemp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = stuTemp;
			}
		}
		save = move;//相当于将save指向上一个节点
	}
	printf("降序排序成功！");
}

//冒泡排序（升序）
void sortStuHigher(stuNode* stuList) {
	stuNode* save = NULL;
	stuNode* move = NULL;
	stuNode* turn;
	for (turn = stuList->next; turn->next != NULL; turn = turn->next) {
		for (move = stuList->next; move->next != save; move = move->next) {
			if (move->stu.stuScore > move->next->stu.stuScore) {//如果当前节点比下一个大
				Student stuTemp;//使用一个临时指针实现两节点交换
				stuTemp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = stuTemp;
			}
		}
		save = move;//相当于将save指向上一个节点
	}
	printf("升序排序成功！");
}
