#include <bits/stdc++.h>
#include<iostream>

class InvalidIndexException : public std::exception
{
    public :

        virtual const char* what() const noexcept override
        {
            return "Invalid Array Index!";
        }

    
};

class IndexPair
{
    private :

        int left, right;

    public :

        IndexPair(int left, int right)
        {
            if ( left < 0 || right < 0 )
                throw InvalidIndexException();

            this->left = left;
            this->right = right;
        }

        void setLeft(int left)
        {
            if ( left < 0 )
                throw InvalidIndexException();

            this->left = left;
        }

        void setRight(int right)
        {
            if ( right < 0 )
                throw InvalidIndexException();

            this->right = right;
        }

        int getLeft() const
        {
            return left;
        }
        int getRight() const
        {
            return right;
        }
};

void printArray(int *, int);
int hoarePartition(int *, int, int);
void quickSort(int *, int, int);

int main()
{
    // int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    int numbers[] = { 24, 58, 11, 67, 92, 43, 0, -3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Quick Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    quickSort(numbers, 0, size-1);

    std::cout<<"\nArray after sorting -\n";
    printArray(numbers, size);

    std::cin.get();
    return 0;
}

//@ Prints the array
void printArray(int *array, int size)
{
    if ( size <= 0 )
    {
        std::cout<<"\nInvalid array || size provided!\n";
        return;
    }

    for ( int i = 0 ; i < size ; i++ )
    {
        std::cout<<array[i]<<" ";
    }

    std::cout<<"\n";
}

//@ Function to select the pivot using the Median-of-Three method
int medianOfThree(int *arr, int left, int right)  
{
    int mid = left + (right - left) / 2;

    // Arrange [arr[left], arr[mid], arr[right]] in sorted order
    if (arr[left] > arr[mid])
        std::swap(arr[left], arr[mid]);

    if (arr[left] > arr[right])
        std::swap(arr[left], arr[right]);

    if (arr[mid] > arr[right])
        std::swap(arr[mid], arr[right]);

    // The median is now at `arr[mid]`, move it to `arr[left]`
    std::swap(arr[mid], arr[left]);

    return arr[left];  // Return pivot
}

//@ Helper Function for Quick Sort that partitions the array, placing the 1st element at its right position
//$ Hoare's partition which is best
int hoarePartition(int *array, int left, int right)
{

    // int pivot = array[left];    //$ Pivot is always the 1st element
    int pivot = medianOfThree(array, left, right);  //$ Selecting median of left, middle and right as pivot
    int leftPtr = left - 1, rightPtr = right + 1;

    while ( leftPtr < rightPtr )
    {
        do
        {
            leftPtr++;
        } while ( pivot > array[leftPtr] );

        do
        {
            rightPtr--;
        } while ( pivot < array[rightPtr]  );

        if ( leftPtr >= rightPtr )
            return rightPtr;

        std::swap( array[leftPtr], array[rightPtr] );

    }

    return 0;
}

//@ My Hybird logic between lomuto and hoare partition 
int partition(int *array, int left, int right)
{

    int pivot = array[left];
    int leftPtr = left /* - 1 */, rightPtr = right /* + 1 */;

    while ( leftPtr < rightPtr )
    {
        while ( leftPtr < rightPtr && pivot > array[leftPtr] )
            leftPtr++;

        while ( leftPtr < rightPtr && pivot < array[rightPtr] )
            rightPtr--;

        if ( leftPtr >= rightPtr )
            return rightPtr;

        std::swap( array[leftPtr], array[rightPtr] );

    }
    return 0;

}

//@ Sorts the array using Quick Sort Algo.
void quickSort(int *array, int left, int right)
{
    try 
    {
        std::stack<IndexPair> stk;
        IndexPair p1(left, right);

        stk.push(p1);

        while( !stk.empty() )
        {
            IndexPair p = stk.top();
            stk.pop();
            int pivotIndex = hoarePartition(array, p.getLeft(), p.getRight() );

            // Ensure Left Subarray has at least 2 elements
            if ( pivotIndex - p.getLeft() > 0 )  
            {
                stk.push(IndexPair(p.getLeft(), pivotIndex));
            }

            // Ensure Right Subarray has at least 2 elements
            if ( p.getRight() - (pivotIndex + 1) > 0 )  
            {
                stk.push(IndexPair(pivotIndex + 1, p.getRight()));
            }

        }

    }
            
    catch( InvalidIndexException &e )
    {
        std::cerr<<"Caught Invalid Index Exception : "<<e.what()<<"\n";
    }
    catch( std::exception &e )
    {
        std::cerr<<"Caught exception : "<<e.what()<<"\n";
    }
    catch( ... )
    {
        std::cerr<<"Caught unknown exception.\n";
    }

}