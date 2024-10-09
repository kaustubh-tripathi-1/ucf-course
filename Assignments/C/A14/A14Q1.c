#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned long long int fact=1;
    long long int num, i;
    int validInput;
    printf("Enter a number to calculate it's factorial - \n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%lld", &num);

        if ( validInput==1 && num>=0 )
            break;
        else
        {
            printf("Enter valid and positive numbers only!!\n");
            while( getchar() != '\n');
        }
    }

    if (num==0)
    {
        fact = 1;
    }
    
    else
    {
        for( i=num ; i > 1 ; i--)
        {
            fact = fact * i;
        }
    }
    
    printf("The Factorial of %d is %llu.", num, fact);

    getch();
    return 0;
}