#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void validInputCheck(int *, int *, int );
int calculateLCM(int , int );

int main()
{
    int num1, num2, LCM;
    printf("Enter 2 numbers to calculate LCM -\n");
    validInputCheck(&num1, &num2, 0);

    LCM = calculateLCM(num1, num2);
    
    printf("LCM of %d and %d is - %d", num1, num2, LCM);    


    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck( int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || (*n1 > 0 && *n2 > 0)))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

int calculateLCM(int num1, int num2)
{
    int lcm;

    for ( int i = (num1 > num2 ? num1 : num2 ) ; i < num1 * num2 ; i++)
    {
        if ( i % num1 == 0 && i % num2 == 0)
        {
            lcm = i;
            break;
        }
    }

    return lcm;
    
}