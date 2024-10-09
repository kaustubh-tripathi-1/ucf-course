#include <stdio.h>

int main() {
    int a = 1;
    int b = 2;
    int c = 3;
    printf("a - %d %d %d\n", a++, ++a, a++);
    printf("b - %d %d %d\n", b++, b++, ++b);
    return 0;
}
