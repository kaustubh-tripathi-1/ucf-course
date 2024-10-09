#include<stdio.h>
#include<conio.h>

int main()
{
    double cp, sp;
    int validInput;
    printf("Enter cost price and selling price of a product -\n");
    while (1)
    {
        validInput = scanf("%lf%lf", &cp, &sp);
        if(validInput==2)
            break;
        else
        {
            printf("Enter valid numbers!!\n");
            while( getchar() != '\n');
        }
    }
    
    

    if (cp<sp)
        printf("Profit Percentage is %lf%%\n", ((sp-cp)/cp*100));
    else if(sp<cp)
        printf("Loss Percentage is %lf%%\n", ((cp-sp)/cp*100));
    else
        printf("No profit or Loss. Profit/Loss Percentage is 0\n");
    
    getch();
    return 0;    
}