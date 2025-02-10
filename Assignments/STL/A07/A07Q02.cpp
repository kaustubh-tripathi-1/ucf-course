#include<iostream>
#include<forward_list>
#include<vector>

int main()
{
    std::forward_list<std::string> str = {"Name", "Age", "Roll no", "Class", "Address"};

    //& Reversing the original list
    /* str.reverse();

    for ( const auto i : str )
        std::cout<<i<<" "; */

    std::vector<std::string> vec(str.begin(), str.end()); // Convert to vector
    for (auto it = vec.rbegin(); it != vec.rend(); ++it)
        std::cout << *it << " "; // Print in reverse order

    std::cin.get();
    return 0;
}