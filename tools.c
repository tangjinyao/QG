#include <stdio.h>
#include "stu.h"
#include <string.h>

//����һ�������ͷ��㣨��Ŀ��
timuNode* creatTimuHead() {
	timuNode* headNode = (timuNode*)malloc(sizeof(timuNode));
	assert(headNode);
	headNode->next = NULL;
	return headNode;
}

//����һ�������ͷ��㣨ѧ����
stuNode* creatStuHead() {
	stuNode* headNode = (stuNode*)malloc(sizeof(stuNode));
	assert(headNode);
	headNode->next = NULL;
	return headNode;
}

//����һ��������½�㣨��Ŀ��
timuNode* creatTimuNew(Timu timu) {
	timuNode* newNode = (timuNode*)malloc(sizeof(timuNode));
	assert(newNode);
	newNode->timu = timu;
	newNode->next = NULL;
	return newNode;
}

//����һ��������½�㣨ѧ����
stuNode* creatStuNew(Student stu) {
	stuNode* newNode = (stuNode*)malloc(sizeof(stuNode));
	assert(newNode);
	newNode->stu = stu;
	newNode->next = NULL;
	return newNode;
}

//ͷ�巨�������в���Ԫ�أ���Ŀ��
void insertTimuByHead(timuNode* headNode, Timu timu) {
	timuNode* newNode = creatTimuNew(timu);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//ͷ�巨�������в���Ԫ�أ�ѧ����
void insertStuByHead(stuNode* headNode, Student stu) {
	stuNode* newNode = creatStuNew(stu);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//��ӡ�����е�����Ԫ�أ���Ŀ��
void printTimuList(timuNode* headNode) {
	timuNode* pMove = headNode->next;//����һ��ָ�룬����whileѭ������������Ŀ����
	while (pMove != NULL) {//����ÿһ��ѭ����ʹ��printf���������ǰָ����ָ�Ľ������ݣ�������Ŀ���𰸺ͷ�����
		printf("%s\t%c\t%d\n", pMove->timu.sentence, pMove->timu.answer, pMove->timu.score);
		pMove = pMove->next;//��ָ���ƶ�����һ����㣬�ظ�ѭ��
	}
}

//��ӡ�����е�����Ԫ�أ�ѧ����
void printStuList(stuNode* headNode) {
	stuNode* pMove = headNode->next;
	int sum = 0;//ͳ���ܷ�
	int num = 0;//ͳ��������
	int sign = 0;//����Ƿ��ӡ��ͷ
	while (pMove != NULL) {
		//������Ϊ-1���������û��ͳ�Ʒ���
		if (pMove->stu.stuScore >= 0) {
			sum += pMove->stu.stuScore;
			num++;
		}
		if (sign == 0) {
			sign = 1;//��ӡ��ͷ
			printf("רҵ                    �༶            ����            ��            ����\n");
		}
		printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n", //���ѧ����Ϣ
			pMove->stu.major, 
			pMove->stu.stuclass, 
			pMove->stu.name,
			pMove->stu.stuAnswer,
			pMove->stu.stuScore
			);
		pMove = pMove->next;
	}
	if (num == 0) {//����ѧ����û��ͳ�Ʒ��������
		num = 1;
	}
	printf("�ܷ�Ϊ��%d\tƽ����Ϊ��%.2f\n", sum, (float)sum / num);//��ӡ�ֺܷ�ƽ����
}

//����ɾ�������е�Ԫ�أ�ѧ��-רҵ��
void deleteByMajor(stuNode* headNode, char* major) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	int sign = 0;//����Ƿ��ҵ����ϵ�רҵ
	while (posNode != NULL) {
		if (strcmp(posNode->stu.major, major) == 0) {
			preNode->next = posNode->next;
			free(posNode);
			if (sign == 0) {//����ǵ�һ���ҵ�
				sign = 1;
			}
			posNode = preNode->next;//��Ϊ��free���ˣ�����Ҫ���¸�ֵ
			continue;//ɾ����Ҫ�ż������ƣ���Ϊɾ����һ�����൱���������
		}
		preNode = posNode;
		posNode = preNode->next;
	}
	if (sign == 1) {
		printf("ɾ���ɹ������и�רҵ��ѧ����Ϣ�ѱ�ɾ����\n");
	}
	else {
		printf("�Ҳ�����רҵ��\n");
	}
}

//����ɾ�������е�Ԫ�أ�ѧ��-�༶��
void deleteByStuclass(stuNode* headNode, int stuclass) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	int sign = 0;//����Ƿ��ҵ����ϵİ༶
	while (posNode != NULL) {
		if (posNode->stu.stuclass == stuclass) {
			preNode->next = posNode->next;
			free(posNode);
			if (sign == 0) {//����ǵ�һ���ҵ�
				sign = 1;
			}
			posNode = preNode->next;//��Ϊ��free���ˣ�����Ҫ���¸�ֵ
			continue;//ɾ����Ҫ�ż������ƣ���Ϊɾ����һ�����൱���������
		}
		preNode = posNode;
		posNode = preNode->next;
	}
	if (sign == 1) {
		printf("ɾ���ɹ������иð༶��ѧ����Ϣ�ѱ�ɾ����\n");
	}
	else {
		printf("�Ҳ����ð༶��\n");
	}
}

//ɾ�������е�Ԫ�أ�ѧ��-������
void deleteByName(stuNode* headNode, char* name) {
	stuNode* preNode = headNode;
	stuNode* posNode = headNode->next;
	while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {//һֱѭ��ֱ���ҵ�������ĩβΪֹ
		preNode = posNode;
		posNode = preNode->next;
	}
	if (posNode != NULL) {//�����û������ĩβ��˵���ҵ���
		preNode->next = posNode->next;//����ɾ������
		free(posNode);
		printf("ɾ���ɹ���");
	}
	else {//�Ѿ���������ĩβ��˵��û�ҵ�
		printf("�Ҳ�����������");
	}
}

//��ѯ�����е�Ԫ�أ�ѧ��-רҵ��
void searchByMajor(stuNode* headNode, char* major) {
	stuNode* posNode = headNode->next;
	int sum = 0;//��¼ѧ���ܷ�
	int num = 0;//��¼�кϷ�������ѧ��������-1��ʾ��ѧ����δ�Ǽǳɼ���
	int searchNum = 0;//��¼��ѯ���ܽ����
	int sign = 0;//����Ƿ��ӡ��ͷ
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.major, major) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//�ҵ���
			if (posNode->stu.stuScore >= 0) {//��ѧ���кϷ�����
				sum += posNode->stu.stuScore;//����������ѧ���ܷ���
				num++;//�кϷ�������ѧ��������һ
			}
			if (sign == 0) {//�ж��Ƿ��ӡ��ͷ
				sign = 1;
				printf("רҵ                    �༶            ����            ��            ����\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//���ѧ����Ϣ
			searchNum++;//��ѯ���ܽ������һ
			posNode = posNode->next;//��ָ��������һ�����
		}
	}

	if (searchNum != 0) {//�з���������ѧ��
		if (num == 0) {//�������ѧ����û�з���
			num = 1;//Ϊ�˱�֤������Ϊ��
		}
		printf("�ܷ�Ϊ��%d\tƽ����Ϊ��%.2f\n", sum, (float)sum / num);
		printf("��%d�������", searchNum);
	}
	else {
		printf("û���ҵ���ؽ����");
	}
}

//��ѯ�����е�Ԫ�أ�ѧ��-�༶��
void searchByStuclass(stuNode* headNode, int stuclass) {
	stuNode* posNode = headNode->next;
	int sum = 0;//��¼ѧ���ܷ�
	int num = 0;//��¼�кϷ�������ѧ��������-1��ʾ��ѧ����δ�Ǽǳɼ���
	int searchNum = 0;//��¼��ѯ���ܽ����
	int sign = 0;//����Ƿ��ӡ��ͷ
	while (posNode != NULL) {
		while (posNode != NULL && posNode->stu.stuclass != stuclass) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//�ҵ���
			if (posNode->stu.stuScore >= 0) {//��ѧ���кϷ�����
				sum += posNode->stu.stuScore;//����������ѧ���ܷ���
				num++;//�кϷ�������ѧ��������һ
			}
			if (sign == 0) {//�ж��Ƿ��ӡ��ͷ
				sign = 1;
				printf("רҵ                    �༶            ����            ��            ����\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//���ѧ����Ϣ
			searchNum++;//��ѯ���ܽ������һ
			posNode = posNode->next;//��ָ��������һ�����
		}
	}

	if (searchNum != 0) {//�з���������ѧ��
		if (num == 0) {//�������ѧ����û�з���
			num = 1;//Ϊ�˱�֤������Ϊ��
		}
		printf("�ܷ�Ϊ��%d\tƽ����Ϊ��%.2f\n", sum, (float)sum / num);
		printf("��%d�������", searchNum);
	}
	else {
		printf("û���ҵ���ؽ����");
	}
}



//��ѯ�����е�Ԫ�أ�ѧ��-������
void searchByName(stuNode* headNode, char* name) {
	stuNode* posNode = headNode->next;
	int sum = 0;//��¼ѧ���ܷ�
	int num = 0;//��¼�кϷ�������ѧ��������-1��ʾ��ѧ����δ�Ǽǳɼ���
	int searchNum = 0;//��¼��ѯ���ܽ����
	int sign = 0;//����Ƿ��ӡ��ͷ
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//�ҵ���
			if (posNode->stu.stuScore >= 0) {//��ѧ���кϷ�����
				sum += posNode->stu.stuScore;//����������ѧ���ܷ���
				num++;//�кϷ�������ѧ��������һ
			}
			if (sign == 0) {//�ж��Ƿ��ӡ��ͷ
				sign = 1;
				printf("רҵ                    �༶            ����            ��            ����\n");
			}
			printf("%-20s\t%-10d\t%-10s\t%-10s\t%-10d\n",
				posNode->stu.major,
				posNode->stu.stuclass,
				posNode->stu.name,
				posNode->stu.stuAnswer,
				posNode->stu.stuScore
			);//���ѧ����Ϣ
			searchNum++;//��ѯ���ܽ������һ
			posNode = posNode->next;//��ָ��������һ�����
		}
	}

	if (searchNum != 0) {//�з���������ѧ��
		//if (num == 0) {//�������ѧ����û�з���
		//	num = 1;//Ϊ�˱�֤������Ϊ��
		//}
		//printf("�ܷ�Ϊ��%d\tƽ����Ϊ��%.2f\n", sum, (float)sum / num);
		printf("��%d�������", searchNum);
	}
	else {
		printf("û���ҵ���ؽ����");
	}
}

//��ѯ�����е�Ԫ�أ�ѧ��-רҵ+�༶��
void searchByMajorStuclass(stuNode* headNode, char* major, int stuclass) {
	stuNode* posNode = headNode->next;
	int sum = 0;//��¼��ѯ���ܽ����
	int sign = 0;//����Ƿ��ӡ��ͷ
	while (posNode != NULL) {
		while (posNode != NULL 
			&& (strcmp(posNode->stu.major, major) != 0 
			|| posNode->stu.stuclass != stuclass ) ) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {
			if (sign == 0) {
				sign = 1;
				printf("רҵ                    �༶            ����            ��            ����\n");
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
		printf("��%d�������", sum);
	}
	else {
		printf("û���ҵ���ؽ����");
	}
}

//�޸������е�Ԫ�أ�ѧ��-����������
void changeByName(stuNode* headNode, char* name) {
	stuNode* posNode = headNode->next;
	int sum = 0;//��־�Ƿ��ҵ�
	while (posNode != NULL) {
		while (posNode != NULL && strcmp(posNode->stu.name, name) != 0) {
			posNode = posNode->next;
		}
		if (posNode != NULL) {//�ҵ���
			printf("��������רҵ��");
			scanf("%s", posNode->stu.major);
			getchar();
			printf("�������°༶��");
			scanf("%d", &posNode->stu.stuclass);
			getchar();
			printf("��������������");
			scanf("%s", posNode->stu.name);
			getchar();
			posNode = posNode->next;
			sum++;
		}
	}
	if (sum != 0) {//����ҵ���
		printf("�޸ĳɹ���\n");
	}
	else {
		printf("û���ҵ���ؽ����\n");
	}
}

//

//����ͨ�ú���
void sort(stuNode* stuList) {
	int sign;
	void (*p)(stuNode*);
	//�����ʾ��
	printf("--------------------------------------------\n");
	printf("\t\t1.����\n");
	printf("\t\t2.����\n");
	printf("--------------------------------------------\n");
	printf("�����룺");

	//�����ж�
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
			puts("������������ԣ�");
		}
	}

	//�����û����������ָ�븳ֵ
	if (sign == '1') {
		p = sortStuLower;
	}
	else if(sign == '2') {
		p = sortStuHigher;
	}
	p(stuList);//���ú���ָ��ָ��ĺ���
}

//ð�����򣨽���
void sortStuLower(stuNode* stuList) {
	stuNode* save = NULL;
	stuNode* move = NULL;
	stuNode* turn;//ѭ������ 
	for (turn = stuList->next; turn->next != NULL; turn = turn->next) {
		for (move = stuList->next; move->next != save; move = move->next) {
			if (move->stu.stuScore < move->next->stu.stuScore) {//�����ǰ�ڵ����һ��С
				Student stuTemp;//ʹ��һ����ʱָ��ʵ�����ڵ㽻��
				stuTemp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = stuTemp;
			}
		}
		save = move;//�൱�ڽ�saveָ����һ���ڵ�
	}
	printf("��������ɹ���");
}

//ð����������
void sortStuHigher(stuNode* stuList) {
	stuNode* save = NULL;
	stuNode* move = NULL;
	stuNode* turn;
	for (turn = stuList->next; turn->next != NULL; turn = turn->next) {
		for (move = stuList->next; move->next != save; move = move->next) {
			if (move->stu.stuScore > move->next->stu.stuScore) {//�����ǰ�ڵ����һ����
				Student stuTemp;//ʹ��һ����ʱָ��ʵ�����ڵ㽻��
				stuTemp = move->stu;
				move->stu = move->next->stu;
				move->next->stu = stuTemp;
			}
		}
		save = move;//�൱�ڽ�saveָ����һ���ڵ�
	}
	printf("��������ɹ���");
}
