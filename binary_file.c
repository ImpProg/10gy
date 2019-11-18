#include <stdio.h>

typedef struct Rational {
    int num;
    int denom;
} Rational;

int main() {
    Rational r[] = {{.num = 1, .denom = 2}, {.num = 2, .denom = 3}, {.num = 4, .denom = 5}};
    
    FILE* file = fopen("binary.xyz", "wb");
    if (!file) {
        printf("File can not be saved.\n");
        return -1;
    }
    
    for (int i = 0; i < 3; ++i) {
        fwrite(&r[i], sizeof(Rational), 1, file);
    }

    fclose(file);

    // read

    file = fopen("binary.xyz", "rb");
    Rational rational;
    while (fread(&rational, sizeof(Rational), 1, file) == 1) {
        printf("%d / %d\n", rational.num, rational.denom);
    }

    return 0;
}