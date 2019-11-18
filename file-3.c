#include <stdio.h>

int main() {
    FILE* file = fopen("input.txt", "r");

    if (!file) {
        printf("File can not be opened!\n");
        return -1;
    }

    char line[10];

    while (fscanf(file, "%s\n", line) == 1) {
        printf("%s\n", line);
    }

    fclose(file);

    return 0;
}