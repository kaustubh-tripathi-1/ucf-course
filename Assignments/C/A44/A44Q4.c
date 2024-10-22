#include<stdio.h>
#include<conio.h>
#include<string.h>

typedef struct Employee
{
    int id;
    char name[40];
    float salary;
}Employee;

void structureInput(Employee *, int);
void displayStructure(Employee *, int);
void removeNewLine(char *str, int len);
Employee findHighestSalary(Employee *, int );

int main()
{
    Employee e1[10] = {
        {101, "Kaustubh Tripathi", 220000.5}, 
        {102, "Rashmi Tripathi", 230000.5},
        {103, "Shyam Nandan Tripathi", 250000.5},
        {104, "Nakshatra Gupta", 220000.5},
        {105, "Arun Gupta", 20000.5},
        {106, "Kushal Goyal", 22000.0},
        {107, "Kushagra Sahu", 112000.0},
        {108, "Thiya Sahu", 222000.0},
        {109, "Nidhi Sahu", 230000.0},
        {110, "Amit Sahu", 250000.0},
};

    int size = sizeof(e1)/sizeof(e1[0]);



    // structureInput(e1, size);

    /* printf("\n");
    displayStructure(e1, size); */

    Employee highestSalaryEmployee = findHighestSalary(e1, size);

    printf("\nThe highest salaried employee is -\nID - %d\nName - %s\nSalary - %.2f\n", highestSalaryEmployee.id, highestSalaryEmployee.name ,highestSalaryEmployee.salary);
    
    getch();
    return 0;
}

//@ Removing New Line at the end of a String
void removeNewLine(char *str, int len)
{
    if( len > 0 && str[len-1] == '\n')
    {
        str[len-1] = '\0';
        (len)--;
    }
}

//@ Taking Input for Each Employee
void structureInput(Employee *e1, int size)
{
    for( int i = 0 ; i < size ; i++)
    {
        printf("Enter the Employee Data for Employee %d -\n", i+1);
        printf("Enter Employee ID -\n");
        scanf("%d", &e1[i].id);

        while ( getchar() != '\n');

        printf("Enter Name -\n");
        fgets(e1[i].name, sizeof(e1[i].name), stdin);

        int length = strlen(e1[i].name);
        removeNewLine(e1[i].name, length);
        
        printf("Enter Employee salary -\n");
        scanf("%f", &e1[i].salary);
    }

}

//@ Print detail of each Employee
void displayStructure(Employee *e1, int size)
{
    for( int i = 0 ; i < size ; i++)
    {
        printf("Employee ID - %d\nEmployee Name - %s\nEmployee Salary - %.2f\n", e1[i].id, e1[i].name, e1[i].salary);
        printf("\n");
    }
}

//@ Finding Highest Salary paid to an Employee
Employee findHighestSalary(Employee *e1, int size)
{
    Employee highestSalaryEmployee = e1[0];
    int i;

    for( i = 1 ; i < size ; i++)
    {
        if ( highestSalaryEmployee.salary < e1[i].salary)
            highestSalaryEmployee = e1[i];
    }

    return highestSalaryEmployee;
}
