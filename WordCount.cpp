#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    // ����Ƿ��ṩ����ȷ�����������в���
    if(argc != 3) {
        printf("�÷�: WordCount [-c | -w] [input_file_name]\n");
        return 1;
    }

    // ��ȡ�����в���
    char *parameter = argv[1];
    char *filename = argv[2];
    
    // �������ļ�
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("���ļ�ʱ����\n");
        return 1;
    }

    char buffer[MAX_SIZE];
    int count = 0;

    // ��������ǡ�-c����������ַ���
    if(strcmp(parameter, "-c") == 0) {
        while(fgets(buffer, MAX_SIZE, file) != NULL) {
            count += strlen(buffer);
        }
        printf("�ַ�����%d\n", count);
    } 
    // ��������ǡ�-w��������㵥����
    else if(strcmp(parameter, "-w") == 0) {
        while(fscanf(file, "%s", buffer) == 1) {
            count++;
        }
        printf("��������%d\n", count);
    } 
    // ������Ч
    else {
        printf("��Ч��������ʹ�� -c �� -w��\n");
        return 1;
    }

    // �ر��ļ�
    fclose(file);

    return 0;
}
