#ifndef FILE_H_INCLUDE
#define FILE_H_INCLUDE

//����n������0��x֮��Ĳ�������
int generateText(long long n, long long x, char* fileURL);

//��ȡ.txt�е����ݵ�������
int readText(int* arr, long long n, char* fileURL);

//�������е����ݱ��浽.txt�ļ���
int writeText(int* arr, long long n, char* fileURL);

#endif