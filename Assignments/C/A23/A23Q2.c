#include<stdio.h>
#include<stdlib.h>

void validInputCheck(int *, int*, int );
int HCF(int, int);

int main()
{
    int num1, num2, hcf;
    printf("Enter 2 numbers to calculate their HCF -\n");
    validInputCheck(&num1, &num2, 0);

    hcf = HCF(num1, num2);

    printf("The HCF of %d & %d is %d.\n", num1, num2, hcf);

    system("pause");
    return 0;
}

//@ Valid Input Check
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

//@ Calculation of HCF

int HCF(int a, int b)
{
    int remainder, hcf;

   /* //$ Simple Logic
    for ( i = (num1<num2 ? num1 : num2) ; i >= 1 ; i-- )
    {
        if( num1 % i == 0 && num2 % i == 0 )
        {
            return i;
        }
    } */
   
   

   //$ Most Efficient, Using Euclidean method
   while(b != 0)
   {
        remainder = a % b;
        a = b;
        b = remainder;
   }

    hcf = a;

    return hcf;
}