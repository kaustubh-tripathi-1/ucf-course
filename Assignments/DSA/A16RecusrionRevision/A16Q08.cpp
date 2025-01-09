#include<iostream>
#include<vector>

//@ nth term of Fibonacci using recusrion and memoization 
unsigned long long int fibonacci(int term, std::vector<unsigned long long int> &memo)
{
    if ( term == 1 || term == 2)
        return 1;

    if ( memo[term] != -1 )
        return memo[term];

    memo[term] = fibonacci(term-1, memo) + fibonacci(term-2, memo);

    return memo[term];
}

int main()
{
    unsigned long long int term, termNo;
    std::cout<<"Enter the term that you want to know in the Fibonacci series :\n";
    std::cin>>termNo;

    if ( termNo == 0 )
    {
        std::cout<<"The "<<termNo<<" term in Fibonacci Series is 0\n";
    }
    else if ( termNo > 0 )
    {
        std::vector<unsigned long long int> memo(termNo + 1, -1);
        term = fibonacci(termNo, memo);
        std::cout<<"The "<<termNo<<" term in Fibonacci Series is "<<term<<"\n";
    }
    else
    {
        std::cout<<"The term no. you entered is invalid\n";
    }

    while( getchar() != '\n');
    std::cin.get();
    return 0;
}