#include<iostream>
#include <limits>
#include <string>
using namespace std;

//@ Class for a Book
class Book
{
    private :

        int bookID;
        string title;
        double price;

    public :

        //& Initializer List with Default args.
        Book(int bookID=1, string title = "Default Name", double price = 0) : bookID(bookID), title(title), price(price) {}

        Book ( const Book &b) : bookID(b.bookID), title(b.title), price(b.price) {}


};

int main()
{
    Book book1;  //$ uses default arguments
    Book book2(101, "C++ Programming", 299.99);  //$ uses parameterized values
    Book book3(book2);  //$ uses copy constructor

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}