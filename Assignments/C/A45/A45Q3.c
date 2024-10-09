#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Student {

    int roll_no;
    char name[25];
    int age;
    int class;
    char section;
    long long int mobile_no;
    char email[30];

}Student;

void validInputCheck(int *, int );
void studentsDataInput(Student *, int );
void studentsDataDisplay(Student *, int );
void removeNewLine(char *, int* );

int main()
{
    int numberOfStudents;
    printf("Enter the number of students in you class -\n");
    validInputCheck(&numberOfStudents, 0);
    Student students[numberOfStudents];


    studentsDataInput(students, numberOfStudents);

    studentsDataDisplay(students, numberOfStudents);

    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Taking Input and Checking if it's valid
void validInputCheckMobile(long long int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%lld", n);

        if(validInput == 1 && (allowNegative || (*n > 0 )))
            break;
        else
        {
            printf("Enter valid numbers!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Removing New Line at the end of a String
void removeNewLine(char *pstr, int* len)
{
    if( *len > 0 && pstr[*len-1] == '\n')
    {
        pstr[*len-1] = '\0';
        (*len)--;
    }
}

//@ Taking Input of Student Data
void studentsDataInput(Student *ptrStudents, int size)
{
    for ( int i = 0 ; i < size ; i++)
    {
        printf("Enter data for student %d -\n", i+1);
        printf("Enter Roll No -\n");
        validInputCheck(&ptrStudents[i].roll_no, 0);

        while ( getchar() != '\n');

        printf("Enter Name -\n");
        fgets( ptrStudents[i].name, sizeof(ptrStudents[i].name), stdin);
        int length1 = strlen(ptrStudents[i].name);
        removeNewLine(ptrStudents[i].name, &length1);

        printf("Enter the age -\n");
        validInputCheck(&ptrStudents[i].age, 0);

        printf("Enter the class -\n");
        validInputCheck(&ptrStudents[i].class, 0);

        while ( getchar() != '\n');
        printf("Enter the section -\n");
        scanf("%c", &ptrStudents[i].section);

        printf("Enter the Mobile no. -\n");
        validInputCheckMobile(&ptrStudents[i].mobile_no, 0);

        while ( getchar() != '\n');

        printf("Enter email -\n");
        fgets( ptrStudents[i].email, sizeof(ptrStudents[i].email), stdin);
        int length2 = strlen(ptrStudents[i].email);
        removeNewLine(ptrStudents[i].email, &length2);
        
    }
}

//@ Displaying Student Data
void studentsDataDisplay(Student *ptrStudents, int size)
{
    printf("Here's the student Data -\n");
    for ( int i = 0 ; i < size ; i++)
    {
        printf("\nStudent %d ", i+1);

        printf("Roll No. - %d\n", ptrStudents[i].roll_no);
        printf("Name - %s\n", ptrStudents[i].name);
        printf("Age - %d\n", ptrStudents[i].age);
        printf("Class & Section- %d-%c\n", ptrStudents[i].class, ptrStudents[i].section);
        printf("Mobile No. - %lld\n", ptrStudents[i].mobile_no);
        printf("Email - %s\n", ptrStudents[i].email);

        printf("\n");
    }
}