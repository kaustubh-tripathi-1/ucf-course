#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned long long int a, b, term;
    int  term_no, validInput, i;
    printf("Enter the no. of terms of Fibonacci series that you want to print:\n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &term_no);

        if ( validInput==1 && term_no>0 )
            break;
        else
        {
            printf("Enter valid and positive number of term!!\n");
            while( getchar() != '\n');
        }
    }

    a=-1;
    b=1;

    for ( i = 1; i <= term_no; i++)
    {
        term = a+b;
        printf("%llu ", term);
        a=b;
        b=term;
    }

    getch();
    return 0;
}