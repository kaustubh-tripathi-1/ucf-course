#include<iostream>

class A
{
    protected :

        int num1, num2;

    public :

        A(int num1 = 0, int num2 = 0)
        :
            num1(num1), num2(num2) {}

        A(const A &a)
        :
            num1(a.num1), num2(a.num2) {}

        void setData(int num1, int num2)
        {
            this->num1 = num1;
            this->num2 = num2;
        }

        virtual void showData() const
        {
            std::cout<<"Numbers are -\nNumber 1 : "<<num1<<"\n"<<"Number 2 : "<<num2<<"\n";
        }

        virtual void input()
        {
            std::cout<<"Enter 2 numbers :\n";
            std::cin>>num1>>num2;
        }

};

class B : public A
{
    int num3;

    public :

        B(int num1 = 0, int num2 = 0, int num3 = 0)
        :
            A(num1, num2), num3(num3) {}

        B( const B &b)
        :
            A(b), num3(b.num3) {}

        void input() override 
        {
            A::input();
            std::cout<<"Enter third number :\n";
            std::cin>>num3;
        }

        void showData() const override 
        {
            A::showData();
            std::cout<<"Number 3 : "<<num3<<"\n";
        }

};

int main()
{
    B bObj;
    bObj.input();
    bObj.showData();

    std::cin.get();
    return 0;
}