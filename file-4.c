#include <stdio.h>

int main() {
    FILE* file = fopen("output.txt", "w");

    putc('A', file);
    putc('\n', file);
    fprintf(file, "%s\n", "Ez egy mondat.");
    fprintf(file, "%d\n", 25);

    fclose(file);

    return 0;
}