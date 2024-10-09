#include<stdio.h>
#include<conio.h>

int main()
{
    double cp, sp;
    printf("Enter the Cost price of a single Banana per dozen :\n");
    if(scanf("%lf", &cp)!=1)
    {
        printf("Invalid Input. Enter numeric value only!!");
        return 1;
    }
    printf("Enter the Selling price of a single Banana per dozen :\n");
    if(scanf("%lf", &sp)!=1)
    {
        printf("Invalid Input. Enter numeric value only!!");
        return 1;
    }


    while(cp<0 || sp<0)
    {
        if(cp<0)
        {
            printf("Cost price can't be -ve. Enter +ve value :\n");
            if(scanf("%lf", &cp)!=1)
            {
                printf("Invalid Input. Enter numeric value only!!");
                return 1;
            }
        }
        if (sp<0)
        {
            printf("Selling price can't be -ve. Enter +ve value :\n");
            if(scanf("%lf", &sp)!=1)
            {
                printf("Invalid Input. Enter numeric value only!!");
                return 1;
            }
        }
    }

    if(cp<sp)
    {
        printf("Profit earned on selling 25 bananas is %.2lf\n", (sp-cp)/12*25);
    }
    else if(cp>sp)
    {
        printf("Loss on selling 25 bananas is %.2lf\n", (cp-sp)/12*25);
    }
    else
    {
        printf("Cost and Selling price are equal. No Profit or Loss.\n");
    }
    getch();
    return 0;
}