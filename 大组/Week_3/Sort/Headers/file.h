#ifndef FILE_H_INCLUDE
#define FILE_H_INCLUDE

//生成n个介于0到x之间的测试数据
int generateText(long long n, long long x, char* fileURL);

//读取.txt中的数据到数组中
int readText(int* arr, long long n, char* fileURL);

//将数组中的数据保存到.txt文件中
int writeText(int* arr, long long n, char* fileURL);

#endif