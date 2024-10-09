#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int*, int );
double powerOf(int, int);

int main()
{
    int power, num;
    double result;
    printf("Enter the number and the power in that particular order to know the resulted number :\n");
    
    validInputCheck(&num, &power, 1);

    result = powerOf(num, power);

    printf("The result of %d to the power of %d is %lf.", num, power, result);
    
    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(int *n1, int *n2, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d%d", n1, n2);

        if(validInput == 2 && (allowNegative || (*n1 >= 0 && *n2 >=0) ))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Calculating Power of a number
double powerOf(int num, int power)
{

    if( power == 0 )
        return 1;
    
    if(power > 0 )
        return num * powerOf(num, power-1);

    /* else
        return 1.0 / num * powerOf(num, power+1); */

    else
        return 1.0 /powerOf(num, -power);

}