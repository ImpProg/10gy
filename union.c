#include <stdio.h>

typedef union A {
    int x;
    int y;
} A;

typedef union B {
    char c;
    double d;
} B;

typedef struct B2 {
    char c;
    double d;
} B2;

int main() {
    A a;
    A a2;
    a.x = 3;
    a2.y = 12;

    printf("x: %d, y: %d\n", a.x, a.y);
    printf("x: %d, y: %d\n", a2.x, a2.y);

    printf("Union B: %ld\n", sizeof(B));
    printf("Struct B2: %ld\n", sizeof(B2));

    return 0;
}