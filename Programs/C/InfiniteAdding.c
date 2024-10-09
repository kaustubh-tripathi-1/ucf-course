#include<stdio.h>
#include<conio.h>


int main()
{
    int i, num, sum=0;

    for( i = 1; ; i++)
    {
        printf("Enter a number to keep adding the numbers, to stop enter 0 :\n");
        scanf("%d", &num);
        if(num==0)
            break;

        sum+=num;
    }

    printf("The sum is %d.", sum);
    getch();
    return 0;
}