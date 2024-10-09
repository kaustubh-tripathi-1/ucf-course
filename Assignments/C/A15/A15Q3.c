#include<stdio.h>
#include<conio.h>

int main()
{
    int i, j, num, isPrime, validInput;
    printf("Enter a number to find next prime number :\n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &num);

        if ( validInput==1 && num>=0)
            break;
        else
        {
            printf("Enter valid number!!\n");
            while( getchar() != '\n');
        }
    }

    for ( i = num+1 ; ; i++)
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
            printf("%d\n", i);
            break;          //$ Found next Prime, break the loop
        }
        
    }
    
    getch();
    return 0;
}