#include<stdio.h>
#include<conio.h>

void validInputCheck(int *, int);
void matrixInput(int m, int n, int a[m][n]);
void printMatrix(int m, int n, int a[m][n]);
void transposeMatrix(int m, int n, int matrix1[m][n], int transposed[n][m]);

int main()
{
    int m, n;
    printf("Enter m order for Matrix -\n");
    validInputCheck(&m, 0);
    printf("Enter n order for Matrix -\n");
    validInputCheck(&n, 0);
    int matrix1[m][n], transposed[n][m];

    
    //$ Input of Matrix
    printf("Enter the values for Matrix :\n");
    matrixInput(m, n, matrix1);

    //$ Printing Matrix
    printf("Matrix -\n");
    printMatrix(m, n, matrix1);

    //$ Transpose of Matrix
    if(m==n)
    {
        //$ For square matrix, we can transpose without extra space
        transposeMatrix(m, n, matrix1, matrix1);
        printf("The transpose of the matrix is -\n");
        printMatrix(m, n, matrix1);         //$ Printing Result
    }
    else
    {
        //$ For non-square matrix, transpose into another matrix
        transposeMatrix(m, n, matrix1, transposed);
        printf("The transpose of the matrix is -\n");
        printMatrix(n, m, transposed);         //$ Printing Result
    }
    
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

//@ Transposeof a matrix
void transposeMatrix(int m, int n, int matrix1[m][n], int transposed[n][m])
{
    //$ Using Extra Space for Non-Square Matrix
    int temp, i, j;
    if(m!=n)
    {
        for(  i=0 ; i < m ; i++)
        {
            for(  j = 0 ; j < n ; j++ )
            {
                transposed[j][i] = matrix1[i][j];
            }
        }
    }

   //$ W/O Using Extra Space
   else
   {
        for( i=0 ; i < m ; i++)
        {
            for( j = i+1 ; j < n ; j++ )
            {
                temp = matrix1[i][j];
                matrix1[i][j] = matrix1[j][i];
                matrix1[j][i] = temp;
            }
        }
   }
}