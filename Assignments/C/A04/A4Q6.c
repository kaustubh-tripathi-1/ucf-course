#include<stdio.h>
#include<conio.h>

int main()
{
    int a, b, validInput = 0;
    printf("Enter values of a & b except 0 :\n");
    while(1)
    {
        validInput = scanf("%d%d", &a, &b);
        if(validInput==2)
        {
           if(a!=0 && b!=0)
                break;
            else
            {
                printf("Enter valid integer numbers except 0!!\n");
                while( getchar() != '\n');
            }
        }
        else
        {
            printf("Enter valid integer numbers!!\n");
            while( getchar() != '\n');
        }
       
    }
    printf("Before swapping, Value of a = %d & value of b = %d.\n", a, b);
    a = a*b;
    b = a/b;
    a = a/b;
    printf("After swapping, Value of a = %d & value of b = %d.\n", a, b);
    getch();
    return 0;
}