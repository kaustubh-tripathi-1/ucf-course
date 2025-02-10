#include<iostream>
#include<forward_list>

int main()
{
    std::forward_list<int> l;
    auto it = l.before_begin(); // Iterator before first element
    it = l.insert_after(it, 10); // Insert one 10
    it = l.insert_after(it, 10); // Insert second 10
    it = l.insert_after(it, 10); // Insert third 10
    it = l.insert_after(it, 10); // Insert fourth 10
    it = l.insert_after(it, 5);  // Insert first 5
    it = l.insert_after(it, 5);  // Insert second 5
    it = l.insert_after(it, 5);  // Insert third 5

    /* std::forward_list<int> l1 = {10, 10, 10, 10}; // First list
    std::forward_list<int> l2 = {5, 5, 5};        // Second list

    l2.splice_after(l2.before_begin(), l1); // Move elements of l2 after l1.begin() */
    
    
    for ( auto num : l )
        std::cout<<num<<" ";

    std::cin.get();
    return 0;
}