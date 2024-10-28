#include<iostream>
#include <limits>
#include <string>
using namespace std;

//@ Class for a Book
class Book
{
    private :

        bool booked;
        string title;
        double price;

    public :

        //& Initializer List with Default args.
        Book(bool booked = false, string title = "Default Name", double price = 0) : booked(booked), title(title), price(price) {}

        Book ( const Book &b) : booked(b.booked), title(b.title), price(b.price) {}


};

int main()
{
    Book book1;  //$ uses default arguments
    Book book2(true, "C++ Programming", 299.99);  //$ uses parameterized values
    Book book3(book2);  //$ uses copy constructor

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}