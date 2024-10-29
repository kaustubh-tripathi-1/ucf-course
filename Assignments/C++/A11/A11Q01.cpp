#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Numbers
{
    private :

        int size;
        int *ptrarr;

    public :

        //& Use of calloc() and free()
        
        //$ Default Param. Constructor
        Numbers(int size = 0) : size(size), ptrarr(NULL) 
        {
            if ( ptrarr == NULL && size > 0)
                ptrarr = (int *)calloc(size, sizeof(int));
        }

        //$ Copy Constructor
        Numbers(const Numbers &n) : size(n.size), ptrarr(NULL)
        {
            if ( ptrarr == NULL && size > 0)
                ptrarr = (int *)calloc(size, sizeof(int));

            for ( int i = 0 ; i < size ; i++)
            {
                ptrarr[i] = n.ptrarr[i];
            }

        }

        //$ Destructor
        ~Numbers()
        {
            free(ptrarr);
        }

        void setArrayData()
        {
            cout<<"\nEnter array values - \n";
            for ( int i = 0 ; i < size ; i++)
            {
                cout<<"Enter "<<i+1<<" value -\n";
                cin>>ptrarr[i];
            }
        }

        void showArray()
        {
            cout<<"\nThe array is :\n";
            for ( int i = 0 ; i < size ; i++)
            {
                cout<<ptrarr[i]<<" ";
            }
            cout<<endl;
        }

};

int main()
{

    Numbers n1(5);
    n1.setArrayData();
    n1.showArray();

    Numbers n2 = n1;

    n2.showArray();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}