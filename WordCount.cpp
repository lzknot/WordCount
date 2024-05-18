#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    // 检查是否提供了正确数量的命令行参数
    if(argc != 3) {
        printf("用法: WordCount [-c | -w] [input_file_name]\n");
        return 1;
    }

    // 提取命令行参数
    char *parameter = argv[1];
    char *filename = argv[2];
    
    // 打开输入文件
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("打开文件时出错。\n");
        return 1;
    }

    char buffer[MAX_SIZE];
    int count = 0;

    // 如果参数是“-c”，则计算字符数
    if(strcmp(parameter, "-c") == 0) {
        while(fgets(buffer, MAX_SIZE, file) != NULL) {
            count += strlen(buffer);
        }
        printf("字符数：%d\n", count);
    } 
    // 如果参数是“-w”，则计算单词数
    else if(strcmp(parameter, "-w") == 0) {
        while(fscanf(file, "%s", buffer) == 1) {
            count++;
        }
        printf("单词数：%d\n", count);
    } 
    // 参数无效
    else {
        printf("无效参数。请使用 -c 或 -w。\n");
        return 1;
    }

    // 关闭文件
    fclose(file);

    return 0;
}
