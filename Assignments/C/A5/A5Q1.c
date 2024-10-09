#include<stdio.h>
#include<conio.h>

int main()
{
    int num, sum;
    printf("Enter a Three Digit Number :\n");
    scanf("%d", &num);
    if(num<100 || num>999)
    {
        printf("You didn't enter a 3 digit number!!\nTry again.");
        return 1;
    }
    sum = (num%10) + ((num/10)%10) + ((num/100)%10);
    printf("The sum of digits in %d is %d", num, sum);
    getch();
    return 0;
}