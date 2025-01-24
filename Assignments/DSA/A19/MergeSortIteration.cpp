#include<iostream>
#include<stack>

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
void mergeArrays(int *, int , int , int , int );
void mergeSort(int *, int, int);

int main()
{
    int numbers[10] = {231, 532, -4321, 478, 8291, 2, 45, -213, 89, 0};
    // int numbers[] = { 24, 58, 11, 67, 92, 43, 0, -3 };
    int size = sizeof(numbers) / sizeof(numbers[0]);

    
    std::cout<<"Sorting using Merge Sort -\n\n";
    std::cout<<"Array before sorting -\n";
    printArray(numbers, size);

    mergeSort(numbers, 0, size-1);

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

//@ Merges the 2 sorted arrays
void mergeArrays(int *array, int leftStart, int leftEnd, int rightStart, int rightEnd)
{

    int sizeOfFirstArray = leftEnd - leftStart + 1;
    int sizeOfSecondArray = rightEnd - rightStart + 1;
    int mergeIndex = 0, mergedSize = sizeOfFirstArray + sizeOfSecondArray, leftIndex = leftStart, rightIndex = rightStart;
    int *mergedArray = new int[mergedSize];  //& Create a temporary array for merging

    //& Merge in a sorted manner, placing the smaller value first in the merged array
    while ( leftIndex <= leftEnd && rightIndex <= rightEnd  )
    {
        if ( array[leftIndex] < array[rightIndex]  )
            mergedArray[mergeIndex++] = array[leftIndex++];
        else
            mergedArray[mergeIndex++] = array[rightIndex++];
    }

    //& Copy the rest of the values of left sub-array (if left)
    while ( leftIndex <= leftEnd )
        mergedArray[mergeIndex++] = array[leftIndex++];

    //& Copy the rest of the values of right sub-array (if left)
    while ( rightIndex <= rightEnd )
        mergedArray[mergeIndex++] = array[rightIndex++];

    int left = leftStart;

    //& Copy the merged array values to the original sub-array
    for ( mergeIndex = 0 ; mergeIndex < mergedSize && left <= rightEnd ; mergeIndex++, left++ )
    {
        array[left] = mergedArray[mergeIndex];
    }

    delete[] mergedArray;    //& Delete the temporary merged array
    
}

//@ Iterative method to sort an array with Merge-Sort using stacks
void mergeSort(int *array, int left, int right)
{
    if ( left >= right || left < 0 || right < 0 )
        return;

    std::stack<IndexPair> stk, mergeStack;
    stk.push(IndexPair(left, right));
    
    while( !stk.empty() )
    {
        IndexPair top = stk.top();
        stk.pop();

        int middle = top.getLeft() + ( top.getRight() - top.getLeft() ) / 2;    //& Prevents integer range overflow for large index values

        if ( middle+1 < top.getRight() )
            stk.push(IndexPair(middle + 1, top.getRight()));

        if ( top.getLeft() < middle )
            stk.push(IndexPair(top.getLeft(), middle));
            
        mergeStack.push(top); // Store subarrays for merging

    }

    while ( !mergeStack.empty() ) // Now merge in the correct order
    {
        IndexPair top = mergeStack.top();
        mergeStack.pop();

        int middle = top.getLeft() + (top.getRight() - top.getLeft()) / 2;
        mergeArrays(array, top.getLeft(), middle, middle + 1, top.getRight());
    }

}