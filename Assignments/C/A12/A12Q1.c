#include<stdio.h>
#include<conio.h>

int main()
{
    int i=0, n, validInput;
    printf("Enter how many times you want to print MySirG :\n");

    while (1)
    {
        validInput = scanf("%d", &n);
        if(validInput==1)
            break;
        else
        {
            printf("Enter valid numbers!!\n");
            while( getchar() != '\n');
        }
    }

    while(i<n)
    {
        printf("MySirG\n");
        i++;
    }
    
    getch();
    return 0;
}