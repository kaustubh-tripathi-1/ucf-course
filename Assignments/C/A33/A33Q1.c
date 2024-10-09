#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void matrixInput(int m, int n, int a[m][n]);
void printMatrix(int m, int n, int a[m][n]);
void addMatrices(int m, int n, int matrix1[m][n], int matrix2[m][n], int matrix3[m][n]);

int main()
{
    int m1, n1, m2, n2;
    printf("Enter m order for Matrix1 -\n");
    validInputCheck(&m1, 0);
    printf("Enter n order for Matrix1 -\n");
    validInputCheck(&n1, 0);
    printf("Enter  order for Matrix2 -\n");
    validInputCheck(&m2, 0);
    printf("Enter n order for Matrix2 -\n");
    validInputCheck(&n2, 0);
    int matrix1[m1][n1], matrix2[m2][n2], matrix3[m1][n1];

    if(m1 == m2 && n1 == n2)
    {
        //$ Input of Matrix 1
        printf("Enter the values for Matrix 1 :\n");
        matrixInput(m1, n1, matrix1);
        //$ Input of Matrix 2
        printf("Enter the values for Matrix 2 :\n");
        matrixInput(m2, n2, matrix2);

        //$ Printing Matrix 1
        printf("Matrix 1 -\n");
        printMatrix(m1, n1, matrix1);
        //$ Printing Matrix 2
        printf("Matrix 2 -\n");
        printMatrix(m2, n2, matrix2);

        //$ Adding Matrices
        addMatrices(m1, n1, matrix1, matrix2, matrix3);
    
        //$ Printing Result
        printf("The sum of 2 matrices is -\n");
        printMatrix(m1, n1, matrix3);
    }
    else
        printf("The order of the 2 matrices is not same. Addition cannot be performed.");

    getch();
    return 0;
}

//@ Valid Input Check
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');  //$ Clear Input Buffer if invalid Input
        }
    }
}

//@ Matrix Input
void matrixInput(int m, int n, int a[m][n])
{
    for( int i=0 ; i < m ; i++)
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("Enter [%d][%d] value for matrix :\n", i+1, j+1);
            validInputCheck(&a[i][j], 1); //$ Allowing Negative Values
        }
    }
}

//@ Print Matrix
void printMatrix(int m, int n, int a[m][n])
{
    for( int i = 0 ; i < m ; i++)
    {
        for( int j = 0 ; j < n ; j++ )
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

//@ Adding 2 Matrices of same order
void addMatrices(int m, int n, int matrix1[m][n], int matrix2[m][n], int matrix3[m][n])
{
    for( int i=0 ; i < m ; i++)
    {
        for( int j = 0 ; j < n ; j++ )
        {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}