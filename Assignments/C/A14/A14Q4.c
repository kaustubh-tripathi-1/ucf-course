#include<stdio.h>
#include<conio.h>

int main()
{
    int lcm=1, hcf, i, num1, num2, validInput, num1_copy, num2_copy, remainder;
    printf("Enter 2 numbers to calculate their LCM -\n");

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

    //$ How we actually Calculate LCM, My logic
    /* i=2;    
    while( num1_copy!=1 || num2_copy!=1 )
    {
        if( num1_copy % i == 0 || num2_copy % i == 0 )
        {
            if( num1_copy % i == 0 )
            {
                num1_copy /= i;
            }
            if (num2_copy % i == 0)
            {
                num2_copy /= i;
            }
            lcm *= i;
        }
        else
            i++;

        printf("The LCM of %d and %d is %d.", num1, num2, lcm);

    } */

   //$ Good Logic
    /* for( i = num1_copy>num2_copy?num1_copy:num2_copy ; i <= num1_copy*num2_copy ; i = i+ (num1_copy>num2_copy?num1_copy:num2_copy) ) 
    {
        if ( i % num1_copy == 0 && i % num2_copy == 0)
        {
            printf("LCM is %d", i);
            break;
        }
        
    } */
   
   

   //$ Most Efficient, Using Euclidean method for HCF and HCF, LCM Relatioship
   while(num2_copy != 0)
   {
        remainder = num1_copy % num2_copy;
        num1_copy = num2_copy;
        num2_copy = remainder;
   }

    hcf = num1_copy;

    lcm = (num1 * num2) / hcf;

    printf("The LCM of %d and %d is %d.", num1, num2, lcm);
    
    getch();
    return 0;
}