#include<iostream>
// using namespace std;

class Integer
{
    private :

        int num;

    public :

        Integer(int num = 0) : num(num) {}

        Integer(const Integer &i) : num(i.num) {}

        friend bool operator!( const Integer &i);
        friend bool operator==( const Integer &i1, const Integer &i2);
};

bool operator!( const Integer &i)
{
    if ( i.num != 0 )
        return false;
    else
        return true;

}

bool operator==( const Integer &i1, const Integer &i2)
{
    if ( i1.num == i2.num )
        return true;
    
    return false;
}



int main()
{
    Integer i1 = 5;
    Integer i2 = i1;
    Integer i3 = 0;

    if ( !i1 )
        std::cout<<"Integer had a falsy value"<<std::endl;
    else
        std::cout<<"Integer had a truthy value"<<std::endl;

    if ( !i3 )
        std::cout<<"Integer had a falsy value"<<std::endl;
    else
        std::cout<<"Integer had a truthy value"<<std::endl;


    if ( i1 == i2 )
        std::cout<<"Both Integer Objects are equal.\n";
    else
        std::cout<<"Both Integer Objects are not equal.\n";

    if ( i1 == i3 )
        std::cout<<"Both Integer Objects are equal.\n";
    else
        std::cout<<"Both Integer Objects are not equal.\n";

    

    std::cin.get();
    return 0;
}