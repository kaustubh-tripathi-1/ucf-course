#include<iostream>
#include<string>

//@ Exception classes

//$ Array Exception Base Class
class ArrayExceptions : public std::exception
{
    protected :

        std::string message;
    
    public :

        ArrayExceptions(const std::string &msg)
        :   message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
        
};

//@ Array Specific Exception Child Classes

//$ Negative Size Exception Class
class NegativeSizeException : public ArrayExceptions
{
    public :

        NegativeSizeException() : ArrayExceptions("Error : Array Size should be greater than 0!") {}
};

//$ Overflow Exception Class
class OverflowException : public ArrayExceptions
{
    public :

        OverflowException() : ArrayExceptions("Error : Can't Add more elements as the array is full!") {}
};

//$ Overflow Exception Class
class UnderflowException : public ArrayExceptions
{
    public :

        UnderflowException() : ArrayExceptions("Error : Can't delete elements from an Empty Array!") {}
};

//$ Invalid Index Exception Class
class InvalidIndexException : public ArrayExceptions
{
    public :

        InvalidIndexException() : ArrayExceptions("Error : Not a Valid Array Index!") {}
};

//$ Holey Array Exception Class
class HoleyArrayException : public ArrayExceptions
{
    public :

        HoleyArrayException() : ArrayExceptions("Error : You can only add elements in a sequential manner otherwise it will become an holey array!") {}
};

//$ Out of Bounds Exception Class
class OutOfBoundsException : public ArrayExceptions
{
    public :

        OutOfBoundsException(size_t index, size_t capacity) : ArrayExceptions("Error : Index" + std::to_string(index) + " is Out of Bounds for the Array. Maximun allowed is "+ std::to_string(capacity-1) + ".") {}
};

/* //$ Index greater than last index filled but less than Capacity Exception Class
class DeleteElementException : public ArrayExceptions
{
    public :

        DeleteElementException() : ArrayExceptions("Error : Can't Delete as the index is greater than last filled index!") {}
}; */

//$ No Element at Index Exception Class
class NoElementAtIndexException : public ArrayExceptions
{
    public :

        NoElementAtIndexException() : ArrayExceptions("Error : Index is within the capacity but there is no element at this index as it is greater than last index filled!") {}
};

//$ Array not created through DMA Exception Class, so further operations shouldn't be possible
class ArrayNotCreatedException : public ArrayExceptions
{
    public :

        ArrayNotCreatedException() : ArrayExceptions("Error : Array not created, further operations aren't possible") {}
};

//$ Array is Empty Exception Class, so further operations shouldn't be possible
class ArrayEmptyException : public ArrayExceptions
{
    public :

        ArrayEmptyException() : ArrayExceptions("Error : Array is there, but it is empty so some operations like delete, edit, count, find, get etc. aren't possible") {}
};

//@ Array DS Class
class Array
{
    private :

        size_t capacity, lastFilledIndex;
        int *arr;

        //$ Checks Common and Repeated Check of Index value, throws exceptions if invalid
        void checkArrayIndexExceptions(size_t index) const
        {
            if( index < 0 )
            {
                throw InvalidIndexException();
            }

            if( index >= capacity )
            {
                throw OutOfBoundsException(index, capacity);
            }
        }

        //$ Checks if the array is already created
        void isArrayCreated() const
        {
            if ( arr == nullptr )
            {
                throw ArrayNotCreatedException();
            }

        }

    public:

        //$ Non-Param Constructor
        Array()
        :
            capacity(0), lastFilledIndex(SIZE_MAX), arr(nullptr) {}

        //$ Param Constructor
        Array(size_t size)
        :
            capacity(0), lastFilledIndex(SIZE_MAX), arr(nullptr)
        {
            if ( (int)size <= 0 )
            {
                throw NegativeSizeException();
            }
            
            capacity = size;
            arr = new int[capacity];            
        }

        //$ Copy Constructor
        Array(const Array &array)
        :   capacity(array.capacity), lastFilledIndex(array.lastFilledIndex)
        {
            if ( capacity <= 0 )
            {
                throw NegativeSizeException();
            }

            if ( arr != nullptr)
            {
                delete[] arr;
            }

            this->arr = new int[capacity]();

            for ( size_t i = 0 ; i < lastFilledIndex ; i++)
            {
                this->arr[i] = array.arr[i];
            }
        }

        //$ Destructor
        virtual ~Array()
        {
            if( arr != nullptr )
                delete[] arr;
        }

        //$ Overloaded Assignment Op.
        Array& operator=(const Array &array)
        {
            isArrayCreated();
            
            //& Self Assignment Check
            if(this == &array)
            {
                return *this;
            }
            
            delete[] this->arr;
            
            this->capacity = array.capacity;
            this->lastFilledIndex = array.lastFilledIndex;

            this->arr = new int[this->capacity]();

            for ( size_t i = 0 ; i < lastFilledIndex ; i++)
            {
                this->arr[i] = array.arr[i];
            }

            return *this;
        }

        //$ Getters
        size_t getCapacity() const
        {
            return capacity;
        }

        size_t getLastFilledIndex() const
        {
            return lastFilledIndex;
        }

        //$ Creates an array if the same failed during object creation/constructor
        void createArray(size_t size)
        {
            if ( size <= 0 )
            {
                throw NegativeSizeException();
            }
            
            arr = nullptr;
            capacity = size;
            lastFilledIndex = SIZE_MAX;

            arr = new int[capacity]();
        }

        //$ Check for an empty array
        bool isEmpty() const 
        {
            isArrayCreated();

            return lastFilledIndex == SIZE_MAX;
        }

        /* void emptyArrayExceptionCheck() const
        {
            if ( lastFilledIndex == SIZE_MAX )
            {
                throw ArrayEmptyException();
            }
        } */

        //$ Appends an element
        Array& appendElement(int element)
        {
            isArrayCreated();

            if( lastFilledIndex+1 == capacity )
            {
                throw OverflowException();
            }

            if ( lastFilledIndex == SIZE_MAX )
            {
                lastFilledIndex = 0;
                arr[lastFilledIndex] = element;
            }
            else
            {
                this->arr[++lastFilledIndex] = element;
            }
            
            return *this;
        }

        //$ Insert an element at a specific index
        Array& insertElementAtIndex(size_t index, int element)
        {
            isArrayCreated();

            checkArrayIndexExceptions(index);

            if ( index > lastFilledIndex+1)
            {
                throw HoleyArrayException();
            }

            if ( lastFilledIndex + 1 >= capacity)
            {
                throw OverflowException();
            }

            if ( lastFilledIndex == SIZE_MAX )
            {
                lastFilledIndex = 0;
                arr[lastFilledIndex] = element;
            }
            else
            {
                for( size_t i = lastFilledIndex ; i >= index ; i--) 
                {   
                    arr[i+1] = arr[i];
                }
                arr[index] = element;

                lastFilledIndex++;
            }

            return *this;
        }

        //$ Edit/Replace an element at an Index
        Array& editElement(size_t index, int element)
        {
            if ( isEmpty() )
            {
                throw ArrayEmptyException();
            }

            checkArrayIndexExceptions(index);

            if ( index > lastFilledIndex )
            {
                throw NoElementAtIndexException();    //& Editing is only allowed for existing elements
            }
            
            arr[index] = element;

            return *this;
        }

        //$ Delete an element at an Index from the array
        Array& deleteElementAtIndex(size_t index)
        {
            if ( isEmpty() )
            {
                throw ArrayEmptyException();
            }

            checkArrayIndexExceptions(index);

            if ( index > lastFilledIndex )
            {
                throw NoElementAtIndexException();
            }

            /* if ( lastFilledIndex + 1 == 0 )
            {
                throw UnderflowException();
            } */

            if (index == lastFilledIndex) 
            {
                //& No need to shift elements; just decrement lastFilledIndex
                lastFilledIndex--;
            }
            else 
            {
                for (size_t i = index + 1; i <= lastFilledIndex; i++) 
                {
                    arr[i - 1] = arr[i];
                }
                lastFilledIndex--;
            }


            return *this;
        }

        //$ Tells if the array is full
        bool isFull() const
        {
            isArrayCreated();

            return lastFilledIndex + 1 == capacity;
        }

        //$ Returns the Element at Index
        int getElement(size_t index) const
        {
            if ( isEmpty() )
            {
                throw ArrayEmptyException();
            }

            checkArrayIndexExceptions(index);

            if ( index > lastFilledIndex )
            {
                throw NoElementAtIndexException();
            }
            
            return arr[index];
        }
        
        //$ Returns Number of Elements in/Size of Array
        int elementCount() const
        {
            if ( isEmpty() )
            {
                throw ArrayEmptyException();
            }

            return lastFilledIndex+1;
        }

        //$ Returns Index of Searched Element
        size_t findElementIndex( int element ) const
        {
            if ( isEmpty() )
            {
                throw ArrayEmptyException();
            }

            for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
            {
                if ( arr[i] == element )
                {
                    return i;
                }
            }

            return SIZE_MAX;
        }

        //$ Displays Array
        void displayArray() const
        {
            std::cout<<"Array Values/Elements :\n";

            if ( lastFilledIndex == SIZE_MAX )
            {
                std::cout<<"Array is Empty Now!\n";
            }
            else
            {
                for ( int i = 0 ; i <= lastFilledIndex ; i++)
                {
                    std::cout<<arr[i]<<" ";
                }
                std::cout<<"\n";
            }
        }
};

int main()
{
    try
    {
        Array a1(10);

        for( int i = 0, j = 1000 ; i < 10 ; i++, j += 3)
        {
            //& Using insertElementAtIndex()
            a1.insertElementAtIndex(i, j);
        }

        std::cout<<"Array after 1st Initialization :\n";
        a1.displayArray();

        //& Using deleteElementAtIndex() and appendElement()
        a1.deleteElementAtIndex(3).appendElement(1030);

        std::cout<<"Array after Modification with delete and append :\n";
        a1.displayArray();

        //& Using isFull()
        if ( a1.isFull() )
        {
            std::cout<<"Array is full..\n";
        }
        else
        {
            std::cout<<"Array is not full..\n";
        }

        //& Using deleteElementAtIndex() and isFull()
        if ( a1.deleteElementAtIndex(1).isFull() )
        {
            std::cout<<"Array is full..\n";
        }
        else
        {
            a1.displayArray();
            std::cout<<"Array is not full..\n";
        }
        
        //& Using isEmpty()
        if ( a1.isEmpty() )
        {
            std::cout<<"Array is empty..\n";
        }
        else
        {
            std::cout<<"Array is not empty..\n";
        }

        //& Using editElement()
        std::cout<<"Array before editElement() :\n";
        a1.displayArray();
        a1.editElement(3, 1016);
        std::cout<<"Array after editElement() :\n";
        a1.displayArray();

        //& Using getElement()
        int retrievedElement = a1.getElement(6);
        std::cout<<"Retrieved Element is : "<<retrievedElement<<"\n";

        size_t arraySize = a1.elementCount();
        std::cout<<"Array Size / No. Elements is : "<<arraySize<<"\n";

        //& Using findElementIndex()
        size_t indexOfSearchedElement = a1.findElementIndex(1012);

        if ( indexOfSearchedElement != SIZE_MAX )
        {
            std::cout<<"Index Of searched element is : "<<indexOfSearchedElement<<"\n";
        }
        else
        {
            std::cout<<"Element not found!\n";
        }

        indexOfSearchedElement = a1.findElementIndex(101);

        if ( indexOfSearchedElement != SIZE_MAX )
        {
            std::cout<<"Index Of searched element is : "<<indexOfSearchedElement<<"\n";
        }
        else
        {
            std::cout<<"Element not found!\n";
        }

        //& Using delete
        std::cout<<"Array before deleteElementAtIndex() :\n";
        a1.displayArray();
        for ( int i = a1.getLastFilledIndex() ; i >= 0 ; i-- )
        {
            a1.deleteElementAtIndex(i);
        }

        std::cout<<"Array after deleteElementAtIndex() :\n";
        a1.displayArray();

    }
    catch( const NegativeSizeException &e)
    {
        std::cerr<<"Caught NegativeSizeException:\n"<<e.what()<<"\n";
    }
    catch( const OverflowException &e)
    {
        std::cerr<<"Caught OverflowException:\n"<<e.what()<<"\n";
    }
    catch( const UnderflowException &e)
    {
        std::cerr<<"Caught UnderflowException:\n"<<e.what()<<"\n";
    }
    catch( const InvalidIndexException &e)
    {
        std::cerr<<"Caught InvalidIndexException:\n"<<e.what()<<"\n";
    }
    catch( const HoleyArrayException &e)
    {
        std::cerr<<"Caught HoleyArrayException:\n"<<e.what()<<"\n";
    }
    catch( const OutOfBoundsException &e)
    {
        std::cerr<<"Caught OutOfBoundsException:\n"<<e.what()<<"\n";
    }
    catch( const NoElementAtIndexException &e)
    {
        std::cerr<<"Caught NoElementAtIndexException:\n"<<e.what()<<"\n";
    }
    catch( const ArrayNotCreatedException &e)
    {
        std::cerr<<"Caught ArrayNotCreatedException:\n"<<e.what()<<"\n";
    }
    catch( const ArrayEmptyException &e)
    {
        std::cerr<<"Caught ArrayEmptyException:\n"<<e.what()<<"\n";
    }
    catch( const std::exception &e)
    {
        std::cerr<<"Caught std::exception : "<<e.what()<<"\n";
    }
    catch(...)
    {
        std::cout<<"Caught unknow Exception!\n";
    }
    
    
    std::cin.get();
    return 0;
}