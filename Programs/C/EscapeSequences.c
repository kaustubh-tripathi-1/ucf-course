#include<stdio.h>
#include<conio.h>


int main()
{
    
    printf("\a\n"); // \a - Alarm or Beep sound 
    printf("Kaustubh\aTripathi\n"); // \b - Backspace
    printf("Kaustubh\aTripathi\n");
    /* \r - Carriage Return , in this case, prints Welcome and 
    then moves cursor to the beginning of the line and
    then prints Students*/

    printf("Kaustubh\aTripathi\n"); // \t - Horizontal Tab
    printf("Kaustubh\\aTripathi\n"); // \\ - print black slash
    printf("Kaustubh\'aTripathi\n"); // \\ - print single quote
    printf("Kaustubh\"aTripathi\n"); // \\ - print double quote
    printf("Kaustubh\?aTripathi\n"); // \\ - print ?
    printf("Kaustubh\0Tripathi\n"); /* 
    \0 - printf prints string until null char is encountered*/

    printf("\nKaustubh\x4bTripathi\n"); /* 
    \x- takes hex number written after it and prints the character 
    of corresponding ASCII Value.*/ 

    getch();
    return 0;
}
