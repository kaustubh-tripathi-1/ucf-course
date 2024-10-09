#include<stdio.h>
#include<conio.h>

int main()
{
    int num, validInput, i, isPrime=1; 
    printf("Enter a positive number to check for prime :\n");
    
    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &num);

        if ( validInput==1 && num>0 )
            break;
        else
        {
            printf("Enter valid and positive numbers only!!\n");
            while( getchar() != '\n');
        }
    }

    if (num==1)         //$ Check for 1 as 1 is not prime
        printf("%d is not Prime.", num);

    else if (num==2)    //$ Check for 2 as 2 is prime
        printf("%d is Prime.", num);

    else
    {
        for( i=2 ; i*i <= num ; i++)    //$ Checking till square root of the number
        {
            if (num%i==0)
            {
                isPrime=0;  //$ Found a divisor, break the loop.
                break;
            }
        }
        if( isPrime )
            printf("%d is Prime.", num);
        else
            printf("%d is not Prime.", num);
    }
    
    
    

    

    getch();
    return 0;
}