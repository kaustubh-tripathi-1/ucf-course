#include<iostream>
#include <limits>
using namespace std;

void f1()
{
    int x = 0;
    static int y = 0;
    x++;y++;
    cout<<"x = "<<x<<", "<<"y = "<<y<<endl;
}

int main()
{
    f1();
    f1();
    f1();

    while ( getchar() != '\n');
    cin.get();
    return 0;
}