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

        //& Use of new and delete
        
        //$ Default Param. Constructor
        Numbers(int size = 0) : size(size), ptrarr(nullptr) 
        {
            if ( ptrarr == nullptr && size > 0)
                ptrarr = new int[size]();
        }

        //$ Copy Constructor
        Numbers(const Numbers &n) : size(n.size), ptrarr(nullptr)
        {
            if ( ptrarr == nullptr && size > 0)
                ptrarr = new int[size];

            for ( int i = 0 ; i < size ; i++)
            {
                ptrarr[i] = n.ptrarr[i];
            }

        }

        //$ Destructor
        ~Numbers()
        {
            delete[] ptrarr;
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