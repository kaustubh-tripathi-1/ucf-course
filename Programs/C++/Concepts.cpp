//@ Static Keyword in C++


/* #include<iostream>
#include <limits>
using namespace std;

class Item
{
    public :
        int a, b; //$ Instance Member var.
        static int k; //$ Static Member var.
};

int main()
{
    Item i1;
    cout<<i1.a;
    cout<<i1.b;
    cout<<i1.k; //$ Error as k is not defined and we're trying to access it because it isn't enough to just declare the static mem. var. in Line 11.


    // while ( getchar() != '\n');
    cin.get();
    return 0;
} */

//& Declaration and Definition of Static Member var.

/* #include<iostream>
#include <limits>
using namespace std;

class Item
{
    public :
        int a, b; //$ Instance Member var.
        static int k; //$ Static Member var.
};

int Item::k=2;    //$ Weird rule in C++ to define static mem. var. outside class with declaration in Class. 

//$ Now, k is defined and has been given memory in the program. 

//$ Can assign any value also, by default it's 0. Madatory to do this if we want to use static mem. var.s

int main()
{
    Item i1;
    
    cout<<i1.a<<endl;
    cout<<i1.b<<endl;
    cout<<i1.k<<endl; //$ Now we can access k and this will print 0.


    // while ( getchar() != '\n');
    cin.get();
    return 0;
} */

//& SMV access with Membership Label, avoid accessing with Object name

/* #include<iostream>
#include <limits>
using namespace std;

class Item
{
    public :
        int a, b; //$ Instance Member var.
        static int k; //$ Static Member var.
};

int Item::k;

int main()
{
    Item i1, i2;
    // i1.k = 2;
    cout<<i1.a<<endl;   //$Garbage
    cout<<i1.b<<endl;   //$Garbage

    // cout<<i2.k<<endl; //$ Static member variables are class var.s and doesn't belong to an object meaning i1 and i2 's k are not different, they're the same, so here assigning 2 to i1.k means k == 2, for the whole class There is only 1 k in the whole class. Static member variables are created only once for the class

    //$ So we shouldn't write static mem. var.s with object name to avoid confusion and to access k when there is no object. Instead we should use class name ( membership label ) like - 

    Item::k = 23;
    cout<<Item::k<<endl;


    // while ( getchar() != '\n');
    cin.get();
    return 0;
} */

//& Now implementing Encapsulation ( Making Member var.s private and providing user services( member methods for mem. var.s ) like set and get )

#include<iostream>
#include <limits>
using namespace std;

class Item
{
    private :
        int a, b; //$ Instance Member var.
        static int k; //$ Static Member var.

    public :
        //$ For Instance Member var.s
        void set_a(int a)
        {
            this->a = a;
        }
        void set_b(int b)
        {
            this->b = b;
        }
        int get_a()
        {
            return a;
        }
        int get_b()
        {
            return b;
        }

        //$ For Static Member var.s
        //% Don't make these instance mem. methods as these are for SMVs only, and should be accessible when there are no objects too as we can't access member methods without and Object. So these are no Class methods as we made them Static Member methods using static keyword

        static void set_k(int temp)
        {
            k = temp;
        }
        static int get_k()
        {
            return k;
        }
};

int Item::k;

int main()
{
    // Item i1, i2;

    // i1.set_a(5);
    // i1.set_b(55);

    // cout<<i1.get_a()<<endl;
    // cout<<i1.get_b()<<endl;

    //$ These methods should still be accessible when there are no objects, that's why we make these methods static and these don't alter the state of an object.
    //$ We access these with Membership label too.

    Item::set_k(44);
    cout<<Item::get_k()<<endl;

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}