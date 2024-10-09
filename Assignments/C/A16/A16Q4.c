#include<stdio.h>
#include<conio.h>

void validInputCheck(int* );
int countDigits(int );
int powerOf(int , int);
void armstrong(int , int);

int main()
{
    int i, num, digits;
    printf("Enter a number to check it it's armstrong -\n");

    validInputCheck(&num);

    digits = countDigits(num);

    armstrong(num, digits);
    
    getch();
    return 0;
}

//@ Valid Input Checking 
void validInputCheck(int *n)
{
    int validInput;
    while(1)
    {
        validInput = scanf("%d", n);

        if (validInput == 1 && *n>=0)
            break;
        else
        {
            printf("Invalid input! Please enter a valid positive integer.\n");
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
void armstrong(int num, int digits)
{
    int result=0, remainder, num_copy=num;

    while (num_copy)
    {
        remainder = num_copy%10;
        result = result + powerOf(remainder, digits);
        num_copy /= 10;
    }
    if (num == result)
        printf("%d is an Armstrong Number.", num);
    else
        printf("%d is not an Armstrong Number.", num);
    
}