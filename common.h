#ifndef _COMMON_H
#define _COMMON_H

//���²������ɵ�
#define NUM_TIMU 4//һ���м�����Ŀ
#define NUM_TIMU_CHOOSE 4//һ���м���ѡ����

//���²����ɵ�
#define MAX_SENTENCE 13//ÿ����Ŀ����󳤶�
#define MAX_MAJOR 20//ѧ��רҵ����󳤶�
#define MAX_NAME 20//ѧ�����ֵ���󳤶�
#define FILE_URL_TIMU "./timu.txt"//��Ŀ�洢��λ��
#define FILE_URL_STU "./stu.txt"//ѧ����Ϣ�洢��λ��
#define FILE_URL_STUPWD "./pwdStu.txt"//ѧ������洢��λ��
#define FILE_URL_TEACHERPWD "./pwdTeacher.txt"//��ʦ����洢��λ��
#define MAX_PWD 10//���볤����󲻳���10
#define TRY 3//��ೢ������Ĵ���

//����ΪһЩȫ�ֱ����Ķ���
char name[MAX_NAME];
char major[MAX_MAJOR];
int stuclass;
char ch;
int endSign;
char stuPwd[MAX_PWD];//�洢������ѧ������
char teacherPwd[MAX_PWD];//�洢�����Ľ�ʦ���� 

#endif
