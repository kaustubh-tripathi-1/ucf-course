#include<stdio.h>
#include<conio.h>

void validInputCheck(int *);
int countDigits(int );
int powerOf(int , int);
int armstrong(int , int);
void printArmstrong(int);

int main()
{
    int i, digits, range;
    printf("Enter a number to display armstrong numbers upto -\n");

    validInputCheck(&range);

    printArmstrong(range);
    
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
void printArmstrong(int range)
{
    int arm, digits;
    for ( int i = 0; i <= range ; i++)
    {
        digits = countDigits(i);
        arm = armstrong(i, digits);
        if(arm)
            printf("%d ", i);
        else
            continue;
    }
    
}