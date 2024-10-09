#include<stdio.h>
#include<conio.h>

int main()
{
    int i, j, isPrime, range_start, range_end, validInput;
    printf("Enter the range in which you want to print prime numbers :\n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d%d", &range_start, &range_end);

        if ( validInput==2 && range_start>=2 && range_end>0)
            break;
        else
        {
            printf("Enter valid range!!\n");
            while( getchar() != '\n');
        }
    }

    for ( i = range_start; i < range_end; i++)
    {
        isPrime=1;
        for( j=2 ; j*j <= i ; j++)    //$ Checking till square root of the number
        {
            if (i%j==0)
            {
                isPrime=0;  //$ Found a divisor, break the loop.
                break;
            }
        }
        if (isPrime)
        {
            printf("%d ", i);
        }
        
    }
    
    getch();
    return 0;
}