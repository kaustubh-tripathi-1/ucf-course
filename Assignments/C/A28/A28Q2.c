#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int*, int );
// int HCF(int, int, int);
int HCF(int, int);

int main()
{
    int num1, num2, hcf;
    printf("Enter 2 numbers to calculate HCF :\n");

    validInputCheck(&num1, &num2, 0);

    // hcf = HCF(num1, num2, num1<num2?num1:num2); //& Simple Logic
    hcf = HCF(num1, num2);               //& Euclidean Method

    printf("The HCF of %d & %d is %d.", num1, num2, hcf);

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

//@ HCF of 2 Number with Recursion

/* //& Simple Logic
int HCF(int n1, int n2, int hcf)
{
    
    if( n1 % hcf == 0 && n2 % hcf ==0 )
        return hcf;

    return HCF(n1, n2, hcf-1);
} */

//& Euclidean Method
int HCF(int n1, int n2)
{
    if( n2 == 0 )
        return n1;
    
    return HCF(n2, n1%n2);
}