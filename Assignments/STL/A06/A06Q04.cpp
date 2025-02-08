#include<iostream>
#include<list>

//@ Manually Sorting using merge sort
// Function to merge two sorted lists
std::list<int> mergeLists(std::list<int> &left, std::list<int> &right)
{
    std::list<int> merged;
    auto it1 = left.begin();
    auto it2 = right.begin();

    while (it1 != left.end() && it2 != right.end())
    {
        if (*it1 < *it2)
        {
            merged.push_back(*it1);
            ++it1;
        }
        else
        {
            merged.push_back(*it2);
            ++it2;
        }
    }

    // Add remaining elements
    while (it1 != left.end())
    {
        merged.push_back(*it1);
        ++it1;
    }
    while (it2 != right.end())
    {
        merged.push_back(*it2);
        ++it2;
    }

    return merged;
}

// Function to implement Merge Sort on a list
std::list<int> mergeSort(std::list<int> &l)
{
    if (l.size() <= 1)
    {
        return l; // Already sorted
    }

    // Split the list into two halves using slow & fast pointers
    std::list<int> left, right;
    auto mid = l.begin();
    std::advance(mid, l.size() / 2);

    left.splice(left.begin(), l, l.begin(), mid);
    right.splice(right.begin(), l, l.begin(), l.end());

    // Recursively sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge sorted halves
    return mergeLists(left, right);
}

void sortList(std::list<int> &l)
{
    l.sort();   //$ Sorting using sort() method
    // l = mergeSort(l);   //$ Manually Sorting using merge sort
}

int main()
{
    std::list<int> l = {2, 43, 54, 6, 32 ,4, -3, 43 ,54, 432, -45, 5};

    std::cout<<"List before sorting :\n";
    for ( auto num : l )
    {
        std::cout<<num<<" ";
    }
    std::cout<<"\n";

    sortList(l);

    std::cout<<"List after sorting :\n";
    for ( auto num : l )
    {
        std::cout<<num<<" ";
    }
    std::cout<<"\n";

    std::cin.get();
    return 0;
}