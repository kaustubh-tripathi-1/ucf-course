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

    num1_copy = num1;
    num2_copy = num2;

    /* //$ Simple Logic
    for ( i = (num1<num2 ? num1 : num2) ; i >= 1 ; i-- )
    {
        if( num1 % i == 0 && num2 % i == 0 )
        {
            hcf=i;
            break;
        }
    } */

   //$ Using Euclidean method for HCF
   while(num2_copy != 0)
   {
        remainder = num1_copy % num2_copy;
        num1_copy = num2_copy;
        num2_copy = remainder;
   }

    hcf = num1_copy;
    
    printf("The LCM of %d and %d is %d.", num1, num2, hcf);
    
    getch();
    return 0;
}