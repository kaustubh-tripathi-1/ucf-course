#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int*, int );
int LCM(int, int);

int main()
{
    int num1, num2, lcm;
    printf("Enter 2 numbers to calculate their LCM -\n");
    validInputCheck(&num1, &num2, 0);

    lcm = LCM(num1, num2);

    printf("The LCM of %d & %d is %d.\n", num1, num2, lcm);

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

        if(validInput == 2 && (allowNegative || ( *n1 > 0 && *n2 > 0)))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Calculation of LCM

int LCM(int a, int b)
{
    int n1 = a, n2 = b, remainder, hcf, lcm;

    //$ Most Efficient, Using Euclidean method for HCF and HCF, LCM Relatioship
    while(b != 0)
    {
        remainder = a % b;
        a = b;
        b = remainder;
    }

    hcf = a;

    lcm = (n1 * n2) / hcf;

    return lcm;
    
    //$ How we actually Calculate LCM, My logic
    /* int i=2;    
    while( a!=1 || b!=1 )
    {
        if( a % i == 0 || b % i == 0 )
        {
            if( a % i == 0 )
            {
                a /= i;
            }
            if (b % i == 0)
            {
                b /= i;
            }
            lcm *= i;
        }
        else
            i++;

        return lcm;

    } */

   //$ Good Logic
    /* for( i = a>b?a:b ; i <= a*b ; i = i + (a>b?a:b) ) 
    {
        if ( i % a == 0 && i % b == 0)
        {
            return i;
        }
        
    } */
}