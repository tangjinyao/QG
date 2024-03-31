#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateText(long long n, long long x, char* fileURL) {
    FILE* file = fopen(fileURL, "w"); // 打开文件，准备写入
    if (file == NULL) {
        printf("无法打开文件\n");
        return 1; // 如果文件无法打开，则退出程序
    }

    srand(time(NULL)); // 使用当前时间作为随机数生成器的种子

    for (int i = 0; i < n; i++) {
        int num = rand() % (x + 1); // 生成一个0到x之间的随机数
        fprintf(file, "%d\n", num); // 将随机数写入文件
    }

    fclose(file); // 关闭文件
    printf("随机数已成功写入%s文件中\n", fileURL);
    return 0;
}

int readText(int* arr, long long n, char* fileURL) {
    int i = 0;
    FILE* file = fopen(fileURL, "r"); // 打开文件，准备读取  

    if (file == NULL) {
        printf("无法打开文件\n");
        return 1; // 如果文件无法打开，则退出程序  
    }

    // 读取文件中的整数，直到文件结束或数组填满  
    while (fscanf(file, "%d", &arr[i]) == 1 && i < n) {
        i++;
    }

    fclose(file); // 关闭文件  

    // 输出数组中的整数以验证读取结果  
    printf("%s中的整数已读取到数组中:\n", fileURL);
    //for (int j = 0; j < i; j++) {
    //    printf("%d\n", arr[j]);
    //}

    // 如果数组未填满，则输出警告信息  
    //if (i < n) {
    //    printf("警告：文件中的整数数量少于数组容量。\n");
    //}
    //else if (i == n) {
    //    printf("注意：数组已填满，如果文件中有更多整数，它们将不会被读取。\n");
    //}

    return 0;
}

int writeText(int* arr, long long n, char* fileURL) {
    //打开文件, 准备写入
    FILE* file = fopen(fileURL, "w");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // 将数组中的每个整数写入文件，每个整数占用一行  
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d\n", arr[i]);
    }

    // 关闭文件  
    fclose(file);

    //打印成功信息
    printf("结果已保存在 %s 中\n", fileURL);
    return 0;
}