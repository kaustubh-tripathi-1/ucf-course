#include<stdio.h>
#include<conio.h>

int main()
{
    int num, num_copy, binary[64], len, i;
    printf("Enter a number to know its binary :\n");
    while((scanf("%d", &num) != 1) ||  num < 0 )
    {
        while ( getchar() != '\n');
        printf("Enter a valid positive number!!\n");
    }
    len = sizeof(binary)/sizeof(binary[0]);
    num_copy = num;
    for(i = 0; i < len ; i++ )
    {
        if(num_copy >= 1)
        {
            binary[i] = num_copy % 2;
            num_copy/=2;
        }
        else
            binary[i] = 0;
    }
    printf("The binary of %d is -\n", num);
    for( i= len-1 ; i>=0 ; i--)
        printf("%d ", binary[i]);

    getch();
    return 0;
}