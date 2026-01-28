#include <stdio.h>

#define DEBUG

int main(int argc, char** argv) {
    if (argc > 2) {
        printf("Too many arguments\n");
        return 0;
    }

    FILE* file;
    if (argc > 1) {
        file = fopen(argv[1], "w");
    }
    else {
        file = fopen("test.txt", "w");
    }
#ifdef DEBUG
    printf("File created\n");
#endif

    if (file == NULL) {
        perror("Error creating file\n");
        return 1;
    }

    fclose(file);
#ifdef DEBUG
    printf("File closed\n");
#endif
    return 0;
}