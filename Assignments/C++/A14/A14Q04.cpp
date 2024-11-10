#include<iostream>
// using namespace std;

class Array
{
    private :

        int size;
        int *ptrArr;

    public :

        //$ Default Param. Constructor
        Array(int size) : size(size), ptrArr(nullptr)
        {
            if ( size > 0 )
            {
                ptrArr = new int[size]();

            }
        }

        //$ Copy Constructor
        Array (const Array &arr )
        :
            size(arr.size), ptrArr(nullptr)
        {
            if ( size > 0 )
            {
                ptrArr = new int[size]();

                for ( int i = 0 ; i < size ; i++)
                {
                    this->ptrArr[i] = arr.ptrArr[i];
                }
            }
        }

        //$ Destructor
        ~Array()
        {
            delete []ptrArr;
        }

        //$ Set Array Data
        void setArrayElements( const int* values = nullptr)
        {
            if ( values != nullptr )
            {
                for ( int i = 0 ; i < this->size ; i++ )
                {
                    ptrArr[i] = values[i];
                }
            }
            else
            {
                std::cout<<"Enter "<<size<<" values for the array :\n";

                for ( int i = 0 ; i < this->size ; i++ )
                {
                    std::cin>>ptrArr[i];
                }
            }
        }

        //$ Shows Array Data
        void showArray() const
        {
            std::cout<<"Array elements : \n";
            for ( int i = 0 ; i < this->size ; i++ )
            {
                std::cout<<ptrArr[i]<<" ";
            }
            std::cout<<std::endl;
        }

        //$ Overloaded assignment=, Deep copies and returns the reference to the caller object itself allowing chaining of operations
        Array& operator=(const Array &arr)
        {
            //& Self-assignment check
            if ( this == &arr )
                return *this;
            
            delete []ptrArr;    //& Release existing memory

            //& Deep copy the size and allocate new memory
            this->size = arr.size ;
            
            ptrArr = new int[this->size]();

            //& Copy each element from the source arra
            for ( int i = 0 ; i < this->size ; i++)
            {
                this->ptrArr[i] = arr.ptrArr[i];
            }

            return *this;   //& Return caller object ref. for chaining
        }

        int getSize()
        {
            return this->size;
        }

        Array operator+(const Array &arr) const
        {
            int concatSize = this->size + arr.size;
            Array temp(concatSize);

            int i, j;
            for ( i = 0 ; i < this->size ; i++ )
            {
                temp.ptrArr[i] = this->ptrArr[i];
            }
            for ( j = 0 ; j < arr.size ; j++, i++ )
            {
                temp.ptrArr[i] = arr.ptrArr[j];
            }

            return temp;
        }
};

int main()
{
    Array numbers1(5);
    int nums[] = {1, 2, 3, 4, 5};
    numbers1.setArrayElements(nums);
    std::cout<<"Array 1 :\n";
    numbers1.showArray();

    Array numbers2(5);

    numbers2 = numbers1;
    std::cout<<"Array 2 :\n";
    numbers2.showArray();

    int concatSize = numbers1.getSize() + numbers2.getSize();

    Array numbers3(concatSize);

    numbers3 = numbers1 + numbers2;
    std::cout<<"Concatenated Array :\n";
    numbers3.showArray();


    std::cin.get();
    return 0;
}