#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int );
// int countDigits(int, int);
int countDigits(int);

int main()
{
    int digits, num;
    printf("Enter a number to count its digits :\n");
    validInputCheck(&num, 1);

    // digits =  countDigits(num, 0);
    if(num == 0)
        digits = 1;
    else
        digits = countDigits(num);

    printf("There are %d digits in %d.", digits, num);

    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}


//@ Count Digits in a Number using Recursion

int countDigits(int n)
{
    if(n == 0)
        return 0;

    return 1 + countDigits(n/10);

}

/* int countDigits(int n, int count)
{
    if (n == 0)   // Base case: when number becomes 0
        return count;

    return countDigits(n / 10, count + 1);  // Increment count for each recursion

    // if(n > 0)
    // {
    //     return countDigits(n / 10, ++count);
    // }
} */




