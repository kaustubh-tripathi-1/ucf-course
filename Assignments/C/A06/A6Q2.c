#include<stdio.h>
#include<conio.h>

int main()
{
    int num, remainder, rotated_number;
    printf("Enter a Three Digit Number to rotate it 1 position to the right :\n");
    if(scanf("%d", &num)!=1 || num<100 || num>999)
    {
        printf("You didn't enter a 3 digit or a valid number!!\nTry again.");
        return 1;
    }
    remainder = num%10;
    rotated_number = (remainder*100) + num/10;
    printf("The Rotated Number is %d.", rotated_number);
    getch();
    return 0;
}