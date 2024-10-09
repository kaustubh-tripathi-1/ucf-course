#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() 
{
    char c = 'A';
    int i = -1234;
    float f = 123.456;
    double d = 123.456789;
    long int li = 1234567890;
    long long int lli = 123456789012345;
    unsigned int ui = 12345;
    unsigned long ul = 1234567890;
    unsigned long long ull = 123456789012345;
    int oct = 075;
    int hex = 0x1A3;
    char str[] = "Hello, World!";
    int n = 0;
    void *ptr = &i;

    printf("Character: %c\n", c);
    printf("Signed integer: %d\n", i);
    printf("Scientific notation: %e\n", f);
    printf("Scientific notation (uppercase): %E\n", f);
    printf("Float: %f\n", f);
    printf("Float with current precision: %g\n", f);
    printf("Float with current precision (uppercase): %G\n", f);
    printf("Signed integer: %i\n", i);
    printf("Long int: %ld\n", li);
    printf("Long int: %li\n", li);
    printf("Double: %lf\n", d);
    printf("Unsigned int: %u\n", ui);
    printf("Unsigned long: %lu\n", ul);
    printf("Long long int: %lld\n", lli);
    printf("Long long int: %lli\n", lli);
    printf("Unsigned long long: %llu\n", ull);
    printf("Octal: %o\n", oct);
    printf("Pointer: %p\n", ptr);
    printf("String: %s\n", str);
    printf("Unsigned int: %u\n", ui);
    printf("Hexadecimal: %x\n", hex);
    printf("Hexadecimal (uppercase): %X\n", hex);
    printf("Prints nothing: %n\n", &n);
    printf("Value of n after %%n specifier: %d\n", n);
    printf("Prints %% character: %%\n");

    getch();
    return 0;
}

