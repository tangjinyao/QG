#include "common.h"
#include "stu.h"
#include <stdio.h>
#include <string.h>

//#include "tools.c"

//¼����Ŀ
void inputTimu(timuNode* timuList) {
	int i;
	for (i = 1; i <= 1; i++) {
		Timu timu;
		printf("Ŀǰ����¼���%d����Ŀ��\n", i);
		printf("��������Ŀ,�𰸣���ֵ��");
		//scanf("%s", timu.sentence);
		fgets(timu.sentence, MAX_SENTENCE, stdin);
		timu.sentence[strlen(timu.sentence) - 1] = '\0';
		while ((timu.answer = getchar()) == ' ');
		//printf("������𰸣�");
		//scanf("%c", &timu.answer);
		//printf("�������ֵ��");
		scanf("%d", &timu.score);

		insertTimuByHead(timuList, timu);
	}
}

//������ѧ��
void inputManyStu(stuNode* stuList) {
	int i;
	for (i = 1; i <= 1; i++) {
		Student stu;
		printf("Ŀǰ����¼���%d��ѧ����\n", i);
		printf("������רҵ��");
		scanf("%s", stu.major);
		getchar();
		printf("������༶��");
		scanf("%d", &stu.stuclass);
		getchar();
		printf("������������");
		scanf("%s", stu.name);

		insertStuByHead(stuList, stu);
	}
}

//��ӵ���ѧ��
void inputSingleStu(stuNode* stuList) {
		Student stu;
		printf("������רҵ��");
		scanf("%s", stu.major);
		getchar();
		printf("������༶��");
		scanf("%d", &stu.stuclass);
		getchar();
		printf("������������");
		scanf("%s", stu.name);

		insertStuByHead(stuList, stu);
}

//ѧ������
void exam(stuNode* stuList) {
	int i = -1;//��¼��ǰ�ǵڼ����⣨��0��ʼ��

	Student stu;
	printf("������רҵ��");
	scanf("%s", stu.major);
	getchar();
	printf("������༶��");
	scanf("%d", &stu.stuclass);
	getchar();
	printf("������������");
	scanf("%s", stu.name);
	stu.stuScore = 0;

	timuNode* pMove = timuList->next;
	while (pMove != NULL) {
		i++;
		//�����Ŀ��ѧ������
		getchar();
		printf("%s\t��Ĵ𰸣�Y��ʾ��ȷ��N��ʾ���󣩣�", pMove->timu.sentence);
		scanf("%c", &stu.stuAnswer[i]);

		//�ش���ȷ�ӷ�
		if (stu.stuAnswer[i] == pMove->timu.answer) {
			stu.stuScore += pMove->timu.score;
		}

		pMove = pMove->next;
	}
	stu.stuAnswer[i + 1] = '\0';
	printf("���Խ�������ĳɼ��ǣ�%d!", stu.stuScore);
	insertStuByHead(stuList, stu);
}

//��ʦ�ľ�
void examTeacher(timuNode* timuList, stuNode* stuList) {
	int i;//ѭ������ 
	timuNode* pTimuMove = timuList->next; //��������ָ��pTimuNode��pStuNode, �ֱ�ָ����Ŀ�����ѧ�������ͷ�ڵ����һ�����
	stuNode* pStuMove = stuList->next;
	
	while (pStuMove != NULL) {//ʹ��whileѭ������ѧ������ֱ���ﵽ�����ĩβ
		pStuMove->stu.stuScore = 0;//��ѧ�����ķ�����ʼ��Ϊ0
		pTimuMove = timuList->next;
		for (i = 0; i < NUM_TIMU; i++) {//����ÿ��ѧ����㣬������Ŀ����
			if (pStuMove->stu.stuAnswer[i] == pTimuMove->timu.answer) {//����ÿ����Ŀ��㣬���ѧ���Ĵ��Ƿ�����Ŀ�Ĵ���ͬ
				pStuMove->stu.stuScore += pTimuMove->timu.score;//�������ͬ���򽫸���Ŀ�ķ����ӵ�ѧ�����ܷ���
			}
			pTimuMove = pTimuMove->next;
		}

		pStuMove = pStuMove->next;//����ɵ�ǰѧ���ķ���������ƶ�ָ�뵽��һ��ѧ�����
	}
	printf("�ľ���ɣ�");
}
