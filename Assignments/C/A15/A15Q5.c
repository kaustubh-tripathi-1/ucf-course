#include<stdio.h>
#include<conio.h>

int main()
{
    int i, num1, num2, hcf, validInput, num1_copy, num2_copy, remainder;
    printf("Enter 2 numbers to calculate their HCF/GCD -\n");
    
    //& Valid Input Check
    while(1)
    {
        validInput = scanf("%d%d", &num1, &num2);

        if ( validInput==2 && num1>0 && num2>0 )
            break;
        else
        {
            printf("Enter valid and positive numbers only!!\n");
            while( getchar() != '\n');
        }
    }

    //$ If numbers are consecutive, no need to check with loop
    if ( num2 == num1+1 || num2 == num1-1 )
    {
        printf("%d and %d are Co-prime numberssss.", num1, num2);
        getch();
        return 0;
    }
    

    num1_copy = num1;
    num2_copy = num2;

    while(num2_copy != 0)
   {
        remainder = num1_copy % num2_copy;
        num1_copy = num2_copy;
        num2_copy = remainder;
   }

    hcf = num1_copy;

    if(hcf==1)
        printf("%d and %d are Co-prime numbers.", num1, num2);
    else
        printf("%d and %d are not Co-prime numbers.", num1, num2);
    
    getch();
    return 0;
}