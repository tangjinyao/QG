#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateText(long long n, long long x, char* fileURL) {
    FILE* file = fopen(fileURL, "w"); // ���ļ���׼��д��
    if (file == NULL) {
        printf("�޷����ļ�\n");
        return 1; // ����ļ��޷��򿪣����˳�����
    }

    srand(time(NULL)); // ʹ�õ�ǰʱ����Ϊ�����������������

    for (int i = 0; i < n; i++) {
        int num = rand() % (x + 1); // ����һ��0��x֮��������
        fprintf(file, "%d\n", num); // �������д���ļ�
    }

    fclose(file); // �ر��ļ�
    printf("������ѳɹ�д��%s�ļ���\n", fileURL);
    return 0;
}

int readText(int* arr, long long n, char* fileURL) {
    int i = 0;
    FILE* file = fopen(fileURL, "r"); // ���ļ���׼����ȡ  

    if (file == NULL) {
        printf("�޷����ļ�\n");
        return 1; // ����ļ��޷��򿪣����˳�����  
    }

    // ��ȡ�ļ��е�������ֱ���ļ���������������  
    while (fscanf(file, "%d", &arr[i]) == 1 && i < n) {
        i++;
    }

    fclose(file); // �ر��ļ�  

    // ��������е���������֤��ȡ���  
    printf("%s�е������Ѷ�ȡ��������:\n", fileURL);
    //for (int j = 0; j < i; j++) {
    //    printf("%d\n", arr[j]);
    //}

    // �������δ�����������������Ϣ  
    //if (i < n) {
    //    printf("���棺�ļ��е�����������������������\n");
    //}
    //else if (i == n) {
    //    printf("ע�⣺����������������ļ����и������������ǽ����ᱻ��ȡ��\n");
    //}

    return 0;
}

int writeText(int* arr, long long n, char* fileURL) {
    //���ļ�, ׼��д��
    FILE* file = fopen(fileURL, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // �������е�ÿ������д���ļ���ÿ������ռ��һ��  
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    // �ر��ļ�  
    fclose(file);

    //��ӡ�ɹ���Ϣ
    printf("����ѱ����� %s ��\n", fileURL);
    return 0;
}