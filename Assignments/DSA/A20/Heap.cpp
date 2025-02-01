#include<iostream>
#include<string>
#include<vector>

//@ Exception classes

//$ Heap ( using Dynamic Heap ) Exceptions Base Class
class HeapExceptions : public std::exception
{
    private:
        std::string message;

    public:
        HeapExceptions( const std::string &msg ) : message(msg) {}

        virtual const char* what() const noexcept override
        {
            return message.c_str();
        }
    
};

//@ Heap Specific Exception Child Classes

//$ Negative Size Exception Class
class NegativeSizeException : public HeapExceptions
{
    public :

        NegativeSizeException() : HeapExceptions("Error : Heap Size should be greater than 0!") {}
};

//$ Overflow Exception Class
class OverflowException : public HeapExceptions
{
    public :

        OverflowException() : HeapExceptions("Error : Can't Add more elements as the Heap is full!") {}
};

//$ Overflow Exception Class
class UnderflowException : public HeapExceptions
{
    public :

        UnderflowException() : HeapExceptions("Error : Can't delete elements from an Empty Heap!") {}
};

//$ Heap not created through DMA Exception Class, so further operations shouldn't be possible
class HeapNotCreatedException : public HeapExceptions
{
    public :

        HeapNotCreatedException() : HeapExceptions("Error : Heap not created, further operations aren't possible") {}
};

//$ Assigner Heap not created through DMA Exception Class, so further operations shouldn't be possible
class AssignerHeapNotCreatedException : public HeapExceptions
{
    public :

        AssignerHeapNotCreatedException() : HeapExceptions("Error : The Heap you're trying to assign is not created, further operations aren't possible") {}
};

//$ Heap is Empty Exception Class, so further operations shouldn't be possible
class EmptyHeapException : public HeapExceptions
{
    public :

        EmptyHeapException() : HeapExceptions("Error : Heap is there, but it is empty so some operations like delete etc. aren't possible") {}
};


//@ Heap ( using Dynamic Heap )
class Heap
{
    private:
        int capacity, lastIndex;
        int *ptrHeap;

        //$ Halves the capacity to avoid memory wastage
        void decreaseCapacity();

        //$ Doubles the capacity of the array
        void doubleCapacity();

    public:

        //$ Constructor
        Heap(int capacity);
        
        //$ Copy Constructor
        Heap(const Heap &h);

        //$ Copy Assignment Op.
        Heap& operator=(const Heap &h);

        //$ Destructor
        ~Heap();

        //$ Inserts an element in the heap
        Heap& insert(int data);

        //$ Checks if the heap is empty
        bool isEmpty() const;

        //$ Returns the Greatest Value in a Max Heap
        int getMax() const;

        //$ Deletes the max element from the heap 
        Heap& deleteElement();

};

//$ Halves the capacity to avoid memory wastage
void Heap::decreaseCapacity()
{
    int newCapacity = std::max(capacity / 2, lastIndex + 1); // Ensure space for existing elements

    if (newCapacity == capacity) // Prevent unnecessary resizing
        return;

    int *newArray = new int[newCapacity](); 

    for ( int i = 0 ; i <= lastIndex ; i++ )
    {
        newArray[i] = ptrHeap[i];
    }

    delete[] ptrHeap;
    ptrHeap = newArray;
    capacity = newCapacity;
}

//$ Doubles the capacity of the array
void Heap::doubleCapacity()
{
    int *newArray = new int[capacity*2](); 

    for ( int i = 0 ; i <= lastIndex ; i++ )
    {
        newArray[i] = ptrHeap[i];
    }

    delete[] ptrHeap;
    ptrHeap = newArray;
    capacity *= 2;
}

//$ Constructor
Heap::Heap(int capacity)
: lastIndex(-1) ,ptrHeap(nullptr)
{
    if ( capacity <= 0 )
        throw NegativeSizeException();

    this->capacity = capacity;
    ptrHeap = new int[capacity]();

}

//$ Copy Constructor
Heap::Heap(const Heap &h)
: capacity(h.capacity), lastIndex(h.lastIndex)
{
    //& Source heap array not created
    if ( !h.ptrHeap )
    {
        this->ptrHeap = nullptr;
        throw AssignerHeapNotCreatedException();
    }

    this->ptrHeap = new int[capacity]();

    for ( int i = 0 ; i <= lastIndex ; i++ )
    {
        this->ptrHeap[i] = h.ptrHeap[i];
    }
    
}

//$ Copy Assignment Op.
Heap& Heap::operator=(const Heap &h)
{
    //& Self Assignment check
    if ( this == &h )
        return *this;

    //& Existing memory clean-up
    if ( this->ptrHeap )
        delete[] ptrHeap;

    //& Source heap array not created
    if ( !h.ptrHeap )
    {
        this->ptrHeap = nullptr;
        throw AssignerHeapNotCreatedException();
    }

    this->capacity = h.capacity;
    this->lastIndex = h.lastIndex;

    this->ptrHeap = new int[capacity]();

    for ( int i = 0 ; i <= lastIndex ; i++ )
    {
        this->ptrHeap[i] = h.ptrHeap[i];
    }

    return *this;
}

//$ Destructor
Heap::~Heap()
{
    if ( ptrHeap )
        delete[] ptrHeap;
}

//$ Insert an element in heap
Heap& Heap::insert(int data)
{
    if ( !ptrHeap )
        throw HeapNotCreatedException();

    if ( lastIndex+1 == capacity )
        doubleCapacity();

    //& Empty Heap
    if ( isEmpty() )
    {
        ptrHeap[++lastIndex] = data;
        return *this;
    }

    int tempIndex = ++lastIndex;
    int parentIndex = (lastIndex - 1) / 2;

    while ( tempIndex > 0 && ptrHeap[parentIndex] < data )
    {
        ptrHeap[tempIndex] = ptrHeap[parentIndex];
        tempIndex = parentIndex;
        if ( tempIndex > 0)
            parentIndex = (tempIndex - 1) / 2;
    }

    ptrHeap[tempIndex] = data; 

    return *this;
}

//$ Checks if the heap is empty
bool Heap::isEmpty() const
{
    if ( !ptrHeap )
        throw HeapNotCreatedException();

    return lastIndex == -1;
}

//$ Returns the Greatest Value in a Max Heap
int Heap::getMax() const
{
    if ( !ptrHeap )
        throw HeapNotCreatedException();

    if ( lastIndex == -1 )
        throw EmptyHeapException();

    return ptrHeap[0];
}

//$ Deletes the max element from the heap 
Heap& Heap::deleteElement()
{
    if ( !ptrHeap )
        throw HeapNotCreatedException();

    if ( isEmpty() )
        throw UnderflowException();

    //$ Only 1 element in heap
    if ( lastIndex == 0 )
    {
        lastIndex--;
        return *this;
    }

    ptrHeap[0] = ptrHeap[lastIndex--];

    int tempIndex = 0;
    
    while ( true )
    {
        int leftChildIndex = 2 * tempIndex + 1;
        int rightChildIndex = 2 * tempIndex + 2;
        int largestValueIndex = tempIndex;

        if ( leftChildIndex <= lastIndex && ptrHeap[leftChildIndex] > ptrHeap[largestValueIndex] )
            largestValueIndex = leftChildIndex;

        if ( rightChildIndex <= lastIndex && ptrHeap[rightChildIndex] > ptrHeap[largestValueIndex] )
            largestValueIndex = rightChildIndex;

        if ( largestValueIndex == tempIndex )
            break;

        std::swap(ptrHeap[tempIndex], ptrHeap[largestValueIndex]);

        tempIndex = largestValueIndex;
    }

    if ( lastIndex > 0 && lastIndex+1 == capacity/4)
        decreaseCapacity();
    
    return *this;
}

//$ Floyd's Heapify Method
void heapify( std::vector<int> &nums, int size, int index)
{
    if ( size == 1)
        return;
    
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2, largestValueIndex = index; 

    if ( leftChildIndex < size && nums[leftChildIndex] > nums[largestValueIndex] )
        largestValueIndex = leftChildIndex;

    if ( rightChildIndex < size && nums[rightChildIndex] > nums[largestValueIndex] )
        largestValueIndex = rightChildIndex;

    if ( largestValueIndex != index )
    {
        std::swap(nums[index], nums[largestValueIndex]);
        heapify(nums, size, largestValueIndex);
    }
}

//$ Heap sort
void heapSort( std::vector<int> &nums )
{
    //& Simple Heap sort using Heap class's insert() and deleteElement()
    /* Heap heap(nums.size());

    for ( int i = 0 ; i < nums.size() ; i++ )
        heap.insert(nums[i]);

    for ( int i = nums.size() - 1 ; i >= 0 ; i-- )
    {
        nums[i] = heap.getMax();
        heap.deleteElement();
    } */

    //& In-place Heap Sort using Floyd's Heapify
    for ( int i = nums.size() / 2 - 1 ; i >= 0 ; i-- )  //? start heapifying from last non-leaf node
        heapify(nums, nums.size(), i);

    for ( int i = nums.size() - 1 ; i > 0 ; i-- )
    {
        std::swap(nums.front(), nums.at(i));  //& Take the largest and place it at the end
        heapify(nums, i, 0);    //& Heapify left sub-array excluding the right sorted sub-array part
    }

}

int main()
{
    std::vector<int> nums = {21, 54, 76, 43, 5, 0, 49, 2, 94, 6};

    heapSort(nums);

    for ( int i = 0 ; i < nums.size() ; i++ )
        std::cout<<nums[i]<<" ";


    std::cin.get();
    return 0;
}