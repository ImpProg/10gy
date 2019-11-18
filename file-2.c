#include <stdio.h>

int main() {
    FILE* file = fopen("input.txt", "r");

    unsigned char buffer[100];
    int numberOfCharacters = fread(buffer, sizeof(char), 100, file);
    for (int i = 0; i < numberOfCharacters; ++i) {
        putchar(buffer[i]);
    }

    fclose(file);

    return 0;
}