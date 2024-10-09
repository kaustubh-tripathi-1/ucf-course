#include<stdio.h>
#include<conio.h>

int main()
{
    int num, num_copy, binary[64], len, i;
    printf("Enter a number to check if it's even or odd :\n");
    while((scanf("%d", &num) != 1) ||  num < 0 )
    {
        while ( getchar() != '\n');
        printf("Enter a valid positive number!!\n");
    }
    /* if( (num & 1) == 0 ) // ?Using Bitwise &
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num); */ 
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
    if(binary[0] == 0)
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num);
    

    getch();
    return 0;
}