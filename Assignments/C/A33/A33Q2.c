#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void matrixInput(int m, int n, int a[m][n]);
void printMatrix(int m, int n, int a[m][n]);
void multiplyMatrices(int m1, int n1, int m2, int n2, int matrix1[m1][n1], int matrix2[m2][n2], int result[m1][n2]);

int main()
{
    int m1, n1, m2, n2;
    printf("Enter m order for Matrix1 -\n");
    validInputCheck(&m1, 0);
    printf("Enter n order for Matrix1 -\n");
    validInputCheck(&n1, 0);
    printf("Enter m order for Matrix2 -\n");
    validInputCheck(&m2, 0);
    printf("Enter n order for Matrix2 -\n");
    validInputCheck(&n2, 0);
    int matrix1[m1][n1], matrix2[m2][n2], result[m1][n2];

    if(n1==m2)
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

        //$ Multiplying Matrices
        multiplyMatrices(m1, n1, m2, n2, matrix1, matrix2, result);
    }
    else
        printf("The product of these 2 matrices is not possible as the number of columns in matrix 1 is not equal to numbers of rows in matrix 2.\n");


    //$ Printing Result
    printf("The product of 2 matrices is -\n");
    printMatrix(m1, n2, result);
    

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

//@ Multiplying 2 Matrices
void multiplyMatrices(int m1, int n1, int m2, int n2, int matrix1[m1][n1], int matrix2[m2][n2], int result[m1][n2])
{
    int i, j, k;

    for(i=0;i<m1;i++)
        for(j=0;j<n2;j++)
            result[i][j]=0;
    
    for( i=0 ; i < m1 ; i++)
    {
        for( j = 0 ; j < n2 ; j++ )
        {
            for( k = 0 ; k < n1 ; k++ )
                result[i][j] += matrix1[i][k] * matrix2[k][j];
        }
    }
}