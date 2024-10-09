#include<stdio.h>
#include<conio.h>

int main()
{
    int i=1, n, validInput;
    printf("Enter the number of odd natural numbers you want to print :\n");

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
    
    printf("The First %d odd natural numbers are - \n", n);
    while (i<=n)
    {
        printf("%d\n", (2*i-1));
        i++;
    }
    
    
    getch();
    return 0;
}