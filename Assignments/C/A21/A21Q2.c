#include<stdio.h>
#include<conio.h>

void validInputCheck(double *, double *, double *, int);
double simpleInterest(double, double, double);

int main()
{
    double p, r, t, SI;
    printf("Enter the principal amount, rate and time to calculate Simple Interest - \n");
    validInputCheck(&p, &r, &t, 0);

    SI = simpleInterest(p, r, t);

    printf("The Simple Interest is %.2lf.\n", SI);
    
    getch();
    return 0;
}

//@ Valid Input Check 3 double
void validInputCheck(double *a, double *b, double *c, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%lf%lf%lf", a, b, c);

        if(validInput == 3 && (allowNegative || (*a>=0 && *b>=0 && *c>=0)))
            break;
        else
        {
            printf("Enter 3 valid and +ve number!!\n");
            while( getchar() != '\n');
        }
    }
    
}

//@ Simple Interest
double simpleInterest(double p, double r, double t)
{
    return (p*r*t)/100;
}