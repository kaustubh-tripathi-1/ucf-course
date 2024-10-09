#include<stdio.h>
#include<conio.h>

int main()
{
     unsigned long long int a, b, num, term;
     int validInput, i;
    printf("Enter the number to check if it's there in Fibonacci series or not:\n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%llu", &num);

        if ( validInput==1 && num>=0 )
            break;
        else
        {
            printf("Enter valid and positive number!!\n");
            while( getchar() != '\n');
        }
    }

    a = -1;
    b = 1;
    while ( a+b <= num )
    {
        term = a+b;
        if (num == term)
        {
            printf("Yes, %llu is present in Fibonacci Series.", num);
            break;
        }
        a=b;
        b=term;
    }

    if( term > num )
        printf("No, %llu is not present in Fibonacci Series.", num);

    getch();
    return 0;
}