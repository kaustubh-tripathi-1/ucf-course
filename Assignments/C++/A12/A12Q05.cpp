#include<iostream>
using namespace std;

//@ Class for Matrix 3x3
class Matrix
{
    private :

        int mat[3][3];

    public :

        //& Constructors
        //$ Default Constructor
        Matrix()
        {
            for ( int i = 0 ; i < 3 ; i++)
            {
                for ( int j = 0 ; j < 3 ; j++)
                {
                    mat[i][j] = 0;
                }
            }
        }

        //$ Constructor for direct initialization
        Matrix(int n1, int n2, int n3, int n4, int n5, int n6, int n7, int n8, int n9)
        {
            mat[0][0] = n1;
            mat[0][1] = n2;
            mat[0][2] = n3;
            mat[1][0] = n4;
            mat[1][1] = n5;
            mat[1][2] = n6;
            mat[2][0] = n7;
            mat[2][1] = n8;
            mat[2][2] = n9;
        }

        //$ Copy Constructor
        Matrix(const Matrix &m)
        {
            for ( int i = 0 ; i < 3 ; i++)
            {
                for ( int j = 0 ; j < 3 ; j++)
                {
                    mat[i][j] = m.mat[i][j];
                }
            }
        }

        //& Methods
        //$ Displays matrix
        void displayMatrix() const
        {
            cout << "Matrix:\n";
            for ( int i = 0 ; i < 3 ; i++)
            {
                for ( int j = 0 ; j < 3 ; j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }

        //$ Sets the values for the Matrix
        void setMatrix()
        {
            cout<<"Enter the elements for a Matrix 3x3 :\n";
            for ( int i = 0 ; i < 3 ; i++)
            {
                for ( int j = 0 ; j < 3 ; j++)
                {
                    cin>>mat[i][j];
                }
            }
        }

        //$ Adds the caller object matrix with the passed object Matrix and returns the resultant matrix
        Matrix operator+(const Matrix &m) const
        {
            Matrix result;
            int i, j;

            for ( i = 0 ; i < 3 ; i++)
            {
                for ( j = 0 ; j < 3 ; j++)
                {
                    result.mat[i][j] = this->mat[i][j] + m.mat[i][j];
                }
            }

            return result;
            
        }

        //$ Subtracts the caller object matrix with the passed object Matrix and returns the resultant matrix
        Matrix operator-(const Matrix &m) const
        {
            Matrix result;
            int i, j;

            for ( i = 0 ; i < 3 ; i++)
            {
                for ( j = 0 ; j < 3 ; j++)
                {
                    result.mat[i][j] = this->mat[i][j] - m.mat[i][j];
                }
            }

            return result;
            
        }

        //$ Multiplies the caller object matrix with the passed object Matrix and returns the resultant matrix
        Matrix operator*(const Matrix &m) const
        {
            Matrix result;
            int i, j, k;

            for ( i = 0 ; i < 3 ; i++)
            {
                for ( j = 0 ; j < 3 ; j++)
                {
                    for ( k = 0 ; k < 3 ; k++)
                    {
                        result.mat[i][j] += this->mat[i][k] * m.mat[k][j];
                    }
                }
            }

            return result;
            
        }

        //$ Returns a new Transposed matrix of the caller object
        Matrix transposeMatrix() const
        {
            Matrix transposed;
            int i, j;

            for ( i = 0 ; i < 3 ; i++)
            {
                for ( j = 0 ; j < 3 ; j++)
                {
                    transposed.mat[i][j] = this->mat[j][i];
                }
            }

            return transposed;
        }

        //$ Evaluates if the caller object matrix is singular or not  
        bool isSingular() const
        {
            int determinant;

            determinant = (mat[0][0] * ( (mat[1][1] * mat[2][2]) - (mat[1][2] * mat[2][1]) )) 
                        - (mat[0][1] * ( (mat[1][0] * mat[2][2]) - (mat[1][2] * mat[2][0]) )) 
                        + (mat[0][2] * ( (mat[1][0] * mat[2][1]) - (mat[1][1] * mat[2][0]) ));

            if ( determinant )
                return false;   //& Determinant non-zero, Matrix is not singular
            else
                return true;    //& Determinant zero, Matrix is singular
            
        }

};

int main()
{
    Matrix m1;
    cout<<"Enter elements for Matrix 1 :\n";
    m1.setMatrix();
    cout<<"Matrix 1 :\n";
    m1.displayMatrix();

    Matrix m2;
    cout<<"Enter elements for Matrix 2 :\n";
    m2.setMatrix();
    cout<<"Matrix 2 :\n";
    m2.displayMatrix();

    Matrix add = m1 + m2;
    cout<<"Matrix 1 and 2 addition :\n";
    add.displayMatrix();

    Matrix sub = m1 - m2;
    cout<<"Matrix 1 and 2 subtraction :\n";
    sub.displayMatrix();

    Matrix mult = m1 * m2;
    cout<<"Matrix 1 and 2 multiplication :\n";
    mult.displayMatrix();

    Matrix transpose1 = m1.transposeMatrix();
    cout<<"Matrix 1 transpose :\n";
    transpose1.displayMatrix();

    Matrix transpose2 = m2.transposeMatrix();
    cout<<"Matrix 2 transpose :\n";
    transpose2.displayMatrix();

    Matrix m3;
    cout<<"Enter elements for Matrix to check if it's singular or not :\n";
    m3.setMatrix();
    m3.displayMatrix();

    cout<<"Checking for singular :\n";
    if ( m3.isSingular() )
        cout<<"The Matrix is a singular matrix.\n";
    else
        cout<<"The Matrix is not a singular matrix.\n";



    // while ( getchar() != '\n');
    cin.get();
    return 0;
}