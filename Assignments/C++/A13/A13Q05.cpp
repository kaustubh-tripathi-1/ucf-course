#include<iostream>
#include <string>
// using namespace std;

class Array
{
    private :

        int size;
        int *ptr;

    public :

        //$ Default Param. Constructor
        Array(int size)
        :
            size(size), ptr(nullptr)
        {
            if( size > 0)
            {
                ptr = new int[size]();
            }
        }

        //$ Copy Constructor
        Array(const Array &arr)
        :
            size(arr.size), ptr(nullptr)
        {
            if( ptr == nullptr && this->size > 0)
                ptr = new int[this->size]();

            for ( int i = 0 ; i < this->size ; i++) 
            {
                this->ptr[i] = arr.ptr[i];
            }
        }

        //$ Overloaded [], Returns reference to the value at requested index
        int& operator[](int index)
        {
            if ( index > 0 && index < size)
            {
                return ptr[index];      //& Return the element at the requested index
                // return *(ptr+index); //& Another Way
            }
        }

        //$ Destructor
        ~Array()
        {
            delete[] ptr;
        }

        //$ Set Array Data
        void setArrayElements( const int* values = nullptr)
        {
            if ( values != nullptr )
            {
                for ( int i = 0 ; i < this->size ; i++ )
                {
                    ptr[i] = values[i];
                }
            }
            else
            {
                std::cout<<"Enter "<<size<<" values for the array :\n";

                for ( int i = 0 ; i < this->size ; i++ )
                {
                    std::cin>>ptr[i];
                }
            }
        }

        //$ Shows Array Data
        void showArray() const
        {
            std::cout<<"Array elements : \n";
            for ( int i = 0 ; i < this->size ; i++ )
            {
                std::cout<<ptr[i]<<" ";
            }
        }

        //$ Overloaded assignment=, Deep copies and returns the reference to the caller object itself allowing chaining of operations
        Array& operator=(const Array& arr)
        {
            //& Self-assignment check
            if ( this == &arr)
                return *this;
            
            delete[] ptr;   //& Release existing memory
            

            //& Deep copy the size and allocate new memory
            this->size = arr.size;
            
            ptr = new int[this->size]();

            //& Copy each element from the source array
            for ( int i = 0 ; i < this->size ; i++) 
            {
                this->ptr[i] = arr.ptr[i];
            }

            return *this;
        }

};

int main()
{
    Array numbers(6);

    numbers.setArrayElements();
    numbers.showArray();

    int& element = numbers[3];
    std::cout<<"\n"<<element;

    element++;

    std::cout<<"\nIncremented element in the array :\n"<<element<<"\n";

    std::cout<<"Modified ";
    numbers.showArray();

    Array numbers2(6);
    numbers2 = numbers;
    numbers2.showArray();

    // while ( getchar() != '\n');
    std::cin.get();
    return 0;
}