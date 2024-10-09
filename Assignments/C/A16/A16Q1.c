#include<stdio.h>
#include<conio.h>

int main()
{
    unsigned long long int a, b, term ;
    int term_no, i, validInput;
    printf("Enter the no. of term of Fibonacci series that you want to know:\n");

    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d", &term_no);

        if ( validInput==1 && term_no>=0 )
            break;
        else
        {
            printf("Enter valid and positive number of term!!\n");
            while( getchar() != '\n');
        }
    }

    a=0;
    b=1;

    //$ For 0th term
    if (term_no==0)
    {
        printf("The 0th term is %llu", a);
        return 0;
    }
    //$ For 1st term
    else if (term_no==1)
    {
        printf("The 1st term is %llu", b);
        return 0;
    }
    
    //$ For terms greater than 1
    else
    {
        for ( i = 2; i <= term_no; i++)
        {
            term = a+b;
            a=b;
            b=term;
        }
        printf("The %d term is %llu", term_no, term);
    }

    getch();
    return 0;
}