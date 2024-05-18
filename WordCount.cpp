#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: WordCount [-c | -w] [input_file_name]\n");
        return 1;
    }

    char *parameter = argv[1];
    char *filename = argv[2];
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char buffer[MAX_SIZE];
    int count = 0;

    if(strcmp(parameter, "-c") == 0) {
        while(fgets(buffer, MAX_SIZE, file) != NULL) {
            count += strlen(buffer);
        }
        printf("×Ö·ûÊý£º%d\n", count);
    } else if(strcmp(parameter, "-w") == 0) {
        while(fscanf(file, "%s", buffer) == 1) {
            count++;
        }
        printf("µ¥´ÊÊý£º%d\n", count);
    } else {
        printf("Invalid parameter. Please use -c or -w.\n");
        return 1;
    }

    fclose(file);

    return 0;
}
