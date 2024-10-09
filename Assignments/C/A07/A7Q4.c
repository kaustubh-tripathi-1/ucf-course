#include<stdio.h>
#include<conio.h>

int main()
{
    int num, quotient, remainder;
    printf("Enter a number to check if it's even or odd :\n");
    while(scanf("%d", &num) != 1)
    {
        while ( getchar() != '\n');
        printf("Enter a valid number!!\n");
    }
    /* quotient = num/2;        // ?My logic, to calculate remainder explicitly, also good logic
    remainder = num - (quotient*2);
    if(remainder == 0)
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num);  */
    if((num/2)*2==num)          // *Good Logic
        printf("%d is Even.", num);
    else
        printf("%d is Odd.", num); 

    getch();
    return 0;
}