#include<stdio.h>
#include<conio.h>



int main()
{
    double marks1, marks2, marks3, marks4, marks5, total_marks;
    printf("Enter marks of 5 subjects to check if you passed or failed -\n");
    printf("Subject 1 - \n");
    scanf("%lf", &marks1);
    while(marks1<0 || marks1>100)
    {
        printf("Please enter Marks of Subject 1 again within the defined range!\n");
        scanf("%lf", &marks1);
    }
    printf("Subject 2 - \n");
    scanf("%lf", &marks2);
    while(marks2<0 || marks2>100)
    {
        printf("Please enter Marks of Subject 2 again within the defined range!\n");
        scanf("%lf", &marks2);
    }
    printf("Subject 3 - \n");
    scanf("%lf", &marks3);
    while(marks3<0 || marks3>100)
    {
        printf("Please enter Marks of Subject 3 again within the defined range!\n");
        scanf("%lf", &marks3);
    }
    printf("Subject 4 - \n");
    scanf("%lf", &marks4);
    while(marks4<0 || marks4>100)
    {
        printf("Please enter Marks of Subject 4 again within the defined range!\n");
        scanf("%lf", &marks4);
    }
    printf("Subject 5 - \n");
    scanf("%lf", &marks5);
    while(marks5<0 || marks5>100)
    {
        printf("Please enter Marks of Subject 5 again within the defined range!\n");
        scanf("%lf", &marks5);
    }

    total_marks = marks1+marks2+marks3+marks4+marks5;
    if(total_marks >= 165 && marks1>=33 && marks2>=33 && marks3>=33 && marks4>=33 && marks5>=33)
        printf("You've passed with %.1lf total marks out of 500.", total_marks);
    else
        printf("You've failed as you didn't score above 33 in a exam.");
    getch();
    return 0;
}