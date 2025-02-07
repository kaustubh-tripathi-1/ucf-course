#include<iostream>
#include<vector>

void printVector(const std::vector<int> &nums)
{
    for ( auto i = nums.cbegin() ; i != nums.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";

}

bool checkPrime(int num)
{
    int divisor;

    if ( num < 2)
        return false;

    for ( divisor = 2 ; divisor * divisor <= num ; divisor++)
        if ( num % divisor == 0)
            return false;

    return true;
    
}

void deletePrimes(std::vector<int> &vec)
{
    for ( auto i = vec.begin() ; i != vec.end() ; )
    {
        if ( checkPrime(*i) )
            i = vec.erase(i);
        else
            i++;
    }
}

int main()
{
    std::vector<int> vec = {2, 43, 54, 6, 32, 
                            4, -3, 43 ,54, 432, 
                            -45, 5, 6, 342, 43, 
                            54, -213, 3, 1, 8329};

    std::cout<<"Vector before deleting prime numbers :\n";
    printVector(vec);
                            
    deletePrimes(vec);

    std::cout<<"Vector after deleting prime numbers :\n";
    printVector(vec);
    
    std::cin.get();
    return 0;
}