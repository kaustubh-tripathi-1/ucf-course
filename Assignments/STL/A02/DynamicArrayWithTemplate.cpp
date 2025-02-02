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

//$ Array not created through DMA Exception Class, so further operations shouldn't be possible
class AssignerArrayNotCreatedException : public ArrayExceptions
{
    public :

        AssignerArrayNotCreatedException() : ArrayExceptions("Error : The Array you're trying to assign is not created, further operations aren't possible") {}
};

//$ Array is Empty Exception Class, so further operations shouldn't be possible
class ArrayEmptyException : public ArrayExceptions
{
    public :

        ArrayEmptyException() : ArrayExceptions("Error : Array is there, but it is empty so some operations like delete, edit, count, find, get etc. aren't possible") {}
};

//@ Array DS Class
template <typename DT>
class Array
{
    private :

        size_t capacity, lastFilledIndex;
        DT *arr;

        //$ Checks Common and Repeated Check of Index value, throws exceptions if invalid
        void checkArrayIndexExceptions(size_t index) const;

        //$ Checks if the array is already created
        void isArrayCreated() const;

        //$ Double the array capacity
        void extendCapacity();

        //$ Decrease the array capacity by half
        void decreaseCapacity();

    public:

        //$ Non-Param Constructor
        Array();

        //$ Param Constructor
        Array(size_t size);

        //$ Copy Constructor
        Array(const Array &array);

        //$ Destructor
        virtual ~Array();

        //$ Overloaded Assignment Op.
        Array<DT>& operator=(const Array &array);

        //$ Overloaded [] Subscript op.
        DT& operator[](size_t index) const;

        //$ Getters
        size_t getCapacity() const;

        size_t getLastFilledIndex() const;

        //$ Creates an array if the same failed during object creation/constructor
        void createArray(size_t size);

        //$ Check for an empty array
        bool isEmpty() const;

        // void emptyArrayExceptionCheck() const;

        //$ Appends an element
        Array<DT>& appendElement(DT element);

        //$ Insert an element at a specific index
        Array<DT>& insertElementAtIndex(size_t index, DT element);

        //$ Edit/Replace an element at an Index
        Array<DT>& editElement(size_t index, DT element);

        //$ Delete an element at an Index from the array
        Array<DT>& deleteElementAtIndex(size_t index);

        //$ Tells if the array is full
        bool isFull() const;

        //$ Returns the Element at Index
        DT getElement(size_t index) const;
        
        //$ Returns Number of Elements in/Size of Array
        int elementCount() const;

        //$ Returns Index of Searched Element
        size_t findElementIndex( DT element ) const;

        //$ Displays Array
        void displayArray() const;
};

//@ Private Member Methods of Array class
//$ Checks Common and Repeated Check of Index value, throws exceptions if invalid
template <typename DT>
void Array<DT>::checkArrayIndexExceptions(size_t index) const
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
template <typename DT>
void Array<DT>::isArrayCreated() const
{
    if ( arr == nullptr )
    {
        throw ArrayNotCreatedException();
    }

}

//$ Double the array capacity
template <typename DT>
void Array<DT>::extendCapacity()
{
    DT *newArr = new DT[capacity*2];

    for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    capacity *= 2;
    arr = newArr;
}

//$ Decrease the array capacity by half
template <typename DT>
void Array<DT>::decreaseCapacity()
{
    DT *newArr = new DT[capacity/2];

    for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
    {
        newArr[i] = arr[i];
    }

    delete[] arr;
    capacity /= 2;
    arr = newArr;
}

//@ Public Member Methods of Array class
//$ Non-Param Constructor
template <typename DT>
Array<DT>::Array()
:
    capacity(0), lastFilledIndex(SIZE_MAX), arr(nullptr) {}

//$ Param Constructor
template <typename DT>
Array<DT>::Array(size_t size)
:
    capacity(0), lastFilledIndex(SIZE_MAX), arr(nullptr)
{
    if ( (int)size <= 0 )
    {
        throw NegativeSizeException();
    }
    
    capacity = size;
    arr = new DT[capacity];            
}

//$ Deep Copy Constructor
template <typename DT>
Array<DT>::Array(const Array &array)
:   capacity(array.capacity), lastFilledIndex(array.lastFilledIndex)
{
    if ( array.arr == nullptr )    
    {
        this->arr = nullptr;
        throw AssignerArrayNotCreatedException();
    }

    this->arr = new DT[capacity];

    for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
    {
        this->arr[i] = array.arr[i];
    }
}

//$ Overloaded Assignment Op.
template <typename DT>
Array<DT>& Array<DT>::operator=(const Array &array)
{
    if ( array.arr == nullptr )    
    {
        throw AssignerArrayNotCreatedException();
    }
    
    //& Self Assignment Check
    if(this == &array)
    {
        return *this;
    }

    if ( arr )
    {
        delete[] this->arr;
        this->arr = nullptr;
    }
    
    this->capacity = array.capacity;
    this->lastFilledIndex = array.lastFilledIndex;

    this->arr = new DT[this->capacity];

    for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
    {
        this->arr[i] = array.arr[i];
    }

    return *this;
}

//$ Overloaded [] Subscript op.
template <typename DT>
DT& Array<DT>::operator[](size_t index) const
{
    isArrayCreated();

    checkArrayIndexExceptions(index);

    if ( index > lastFilledIndex )
        throw InvalidIndexException();
    
    return arr[index];
}

//$ Destructor
template <typename DT>
Array<DT>::~Array()
{
    if( arr != nullptr )
        delete[] arr;
}

//$ Getters
template <typename DT>
size_t Array<DT>::getCapacity() const
{
    return capacity;
}

template <typename DT>
size_t Array<DT>::getLastFilledIndex() const
{
    return lastFilledIndex;
}

//$ Creates an array if the same failed during object creation/constructor
template <typename DT>
void Array<DT>::createArray(size_t size)
{
    if ( size <= 0 )
    {
        throw NegativeSizeException();
    }
    
    if ( arr != nullptr )
    {
        delete []arr;
        arr = nullptr;
    }

    capacity = size;
    lastFilledIndex = SIZE_MAX;

    arr = new DT[capacity];
}

//$ Check for an empty array
template <typename DT>
bool Array<DT>::isEmpty() const 
{
    isArrayCreated();

    return lastFilledIndex == SIZE_MAX;
}

/* void Array<DT>::emptyArrayExceptionCheck() const
{
    if ( lastFilledIndex == SIZE_MAX )
    {
        throw ArrayEmptyException();
    }
} */

//$ Appends an element
template <typename DT>
Array<DT>& Array<DT>::appendElement(DT element)
{
    isArrayCreated();

    if( isFull() )
    {
        extendCapacity();
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
template <typename DT>
Array<DT>& Array<DT>::insertElementAtIndex(size_t index, DT element)
{
    isArrayCreated();

    checkArrayIndexExceptions(index);

    if ( index > lastFilledIndex+1)
    {
        throw HoleyArrayException();
    }

    if ( lastFilledIndex + 1 >= capacity)
    {
        extendCapacity();
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
template <typename DT>
Array<DT>& Array<DT>::editElement(size_t index, DT element)
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
template <typename DT>
Array<DT>& Array<DT>::deleteElementAtIndex(size_t index)
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

    if ( lastFilledIndex+1 == 0 )
    {
        throw UnderflowException();
    }

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

    if ( lastFilledIndex > 0 && lastFilledIndex + 1 == capacity/2 )
    {
        decreaseCapacity();
    }

    return *this;
}

//$ Tells if the array is full
template <typename DT>
bool Array<DT>::isFull() const
{
    isArrayCreated();

    return lastFilledIndex + 1 == capacity;
}

//$ Returns the Element at Index
template <typename DT>
DT Array<DT>::getElement(size_t index) const
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
template <typename DT>
int Array<DT>::elementCount() const
{
    if ( isEmpty() )
    {
        throw ArrayEmptyException();
    }

    return lastFilledIndex+1;
}

//$ Returns Index of Searched Element
template <typename DT>
size_t Array<DT>::findElementIndex( DT element ) const
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
template <typename DT>
void Array<DT>::displayArray() const
{
    std::cout<<"Array Values/Elements :\n";

    if ( lastFilledIndex == SIZE_MAX )
    {
        std::cout<<"Array is Empty Now!\n";
    }
    else
    {
        for ( size_t i = 0 ; i <= lastFilledIndex ; i++)
        {
            std::cout<<arr[i]<<" ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    try
    {
        Array<int> a1(10);

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