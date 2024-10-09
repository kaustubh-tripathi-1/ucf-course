#include<stdio.h>
#include<conio.h>
#define USD 84.23

int main()
{
    double inr, usd;
    printf("Enter INR to convert to USD :\n");
    if(scanf("%lf", &inr)!=1)
    {
        printf("You didn't enter a valid number!!");
        return 1;
    }
    usd = inr / 84.23;
    printf("The conversion of %lf INR to USD is %.2lf USD.", inr , usd);
    getch();
    return 0;
}