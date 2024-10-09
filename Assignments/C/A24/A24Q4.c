#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int*, int );
int countDigits(int );
int powerOf(int , int);
int armstrong(int , int);
void printArmstrong(int, int);

int main()
{
    int rangeStart, rangeEnd;
    printf("Enter 2 numbers for which you want to print armstrong numbers between them :\n");
    validInputCheck(&rangeStart, &rangeEnd, 0);

    printArmstrong(rangeStart, rangeEnd);

    getch();
    return 0;
}

//@ Valid Input Check of 2 numbers
void validInputCheck(int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || ( *n1 >= 0 && *n2>=0)))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Count Digits in the nummber
int countDigits(int n)
{
    int count = 0;
    while(n)
    {
        n /= 10;
        count++;
    }

    return count;
    
}

//@ Calculating the power of a number
int powerOf(int n, int power)
{
    int result=1, i;

    for ( i = 1; i <= power; i++)
        result *= n;

    return result;
}

//@ Check for Armstrong Number
int armstrong(int num, int digits)
{
    int result=0, remainder, num_copy=num, a;

    while (num_copy)
    {
        remainder = num_copy%10;
        result = result + powerOf(remainder, digits);
        num_copy /= 10;
    }
    if (num == result)
        return 1;
    else
        return 0;
        
}

//@ Printing Armstrong Numbers
void printArmstrong(int rangeStart, int rangeEnd)
{
    int arm, digits;
    for ( int i = rangeStart+1 ; i <= rangeEnd ; i++)
    {
        digits = countDigits(i);
        arm = armstrong(i, digits);
        if(arm)
            printf("%d ", i);
    }
    
}

