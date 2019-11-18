#include <stdio.h>

int main() {
    FILE* file = fopen("input.txt", "r");

    int c;
    while ((c = fgetc(file)) != EOF) {
        putchar(c);
    }

    fclose(file);

    return 0;
}