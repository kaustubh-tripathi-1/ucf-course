#include<stdio.h>
#include<conio.h>

int main()
{
    int i, j, isPrime;

    for ( i = 2; i <= 100; i++)
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