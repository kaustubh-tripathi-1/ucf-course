#include<iostream>
#include<vector>

void printVector(const std::vector<int> &nums)
{
    std::vector<int>::const_iterator i;
    
    for ( i = nums.cbegin() ; i != nums.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";

}

void deleteElementsFrom1stNegative(std::vector<int> &nums)
{
    std::vector<int>::iterator i;
    
    for ( i = nums.begin() ; i != nums.end()-1 ; i++ )
    {
        if ( *(i+1) < 0 )
        {
            while ( nums.back() != *i )
            {
                nums.pop_back();
            }
            break;
        }
    }

}

int main()
{
    std::vector<int> vec = {2, 43, 54, 6, 32 ,4, -3, 43 ,54, 432, -45, 5};

    std::cout<<"Vector before deleting all values from the 1st -ve value occurred :\n";
    printVector(vec);
    
    deleteElementsFrom1stNegative(vec);
    
    std::cout<<"Vector after deleting all values from the 1st -ve value occurred :\n";
    printVector(vec);

    std::cin.get();
    return 0;
}