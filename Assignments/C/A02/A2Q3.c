#include<stdio.h>
#include<conio.h>

int main()
{
    double p, r, t;
    printf("Enter Principle amount to calculate Simple Interest :\n");
    scanf("%lf", &p);
    printf("Enter Rate of Interest to calculate Simple Interest :\n");
    scanf("%lf", &r);
    printf("Enter Amount of Time to calculate Simple Interest :\n");
    scanf("%lf", &t);
    while(p<0 || r<0 || t<0)
    {
        printf("The values can't be in -ve, try Again!! :\n");
        if(r<0)
        {
            printf("Enter Rate of Interest again :\n");
            scanf("%lf", &r);
        }
        if(p<0)
        {
            printf("Enter Principle amount again :\n");
            scanf("%lf", &p);
        }
        if(t<0)
        {
            printf("Enter Amount of Time again :\n");
            scanf("%lf", &t);
        }
    }
    printf("The Simple Interest is %lf", (p*r*t)/100);
    getch();
    return 0;
}

