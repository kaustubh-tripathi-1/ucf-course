#include<iostream>

// using namespace std;

//@ Class for Time
class Time
{
    private :

        int hour, minute, second;
        bool isValid;

        bool validTime(int hour, int minute, int second)
        {
            if ( hour >= 0 && hour < 24 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59 )
                return true;
            else
                return false;
        }

    public :

        //$ Default Param. Constructor
        Time(int hour = 0, int minute = 0, int second = 0)
            :
                hour(hour), minute(minute), second(second)
        {
            setTime(hour, minute, second);
        }

        //$ Copy Constructor   
        Time(const Time &t)
            :
                hour(t.hour), minute(t.minute), second(t.second), isValid(t.isValid) {}

        

        //$ Sets the Time for an instance, provide it in 24H clock format
        void setTime(int hour, int minute, int second)
        {
            if ( validTime(hour, minute, second) )
            {
                this->hour = hour;
                this->minute = minute;
                this->second = second;
                this->isValid = true;
            }
            else
            {
                std::cout<<"Invalid Time!"<<std::endl;
                this->isValid = false;
            }
        }

        //$ Displays the time of an instance
        void showTime() const
        {
            if ( isValid )
                std::cout<<"The time is "<<(hour < 10 ? "0" : "")<<hour<<":"<<(minute < 10 ? "0" : "")<<minute<<":"<<(second < 10 ? "0" : "")<<second<<std::endl;
            else
                std::cout<<"Time not set or is invalid!"<<std::endl;
        }

        //$ Normalize the time values
        void normalize()
        {
            if (!isValid)
                return;
            
            if ( second > 59 )
            {
                minute += second / 60;
                second %= 60;
            }
            if ( minute > 59)
            {
                hour += minute / 60;
                minute %= 60;
            }
            
            hour %= 24;
        }

        //$ Adds 2 times
        Time operator+(const Time &secondTime) const
        {
            Time temp;

            temp.hour = this->hour + secondTime.hour;
            temp.minute = this->minute + secondTime.minute;
            temp.second = this->second + secondTime.second;

            temp.normalize();
            temp.isValid = true;
            
            return temp;
        }

        /**  
         * @brief Overloaded operator >, Tells if the time of caller object is greater than the passed object
        */
        bool operator>( const Time &secondTime) const
        {
            int seconds1, seconds2;

            seconds1 = this->hour*3600 + this->minute*60 + this->second;
            seconds2 = secondTime.hour*3600 + secondTime.minute*60 + secondTime.second;


            return seconds1 > seconds2;

                
            //$ Multiple if-else checks logic
            /* if ( this->hour > secondTime.hour )
                return true;
            else if ( this->hour == secondTime.hour && this->minute > secondTime.minute)
                return true;
            else if ( this->minute == secondTime.minute && this->second > secondTime.second)
                return true;
            else
                return false; */
            
        }

        //@ Better to return the ref. of caller object instead of creating a temp object.
        //$ Overloaded Operator ++ Pre-Increment, Will Increment the second of Time by 1 and return a Time Object with pre-increment rules
        Time& operator++()
        {
            ++second;

            normalize();

            return *this;   //% Returns the object by reference(after deref., not returning this directly as it will return the add. of the whole object block and will need to deref. wherever received)
        }


        //$ Overloaded Operator ++ Post-Increment, Will Increment the second of Time by 1 and return a Time Object with post-increment rules
        Time operator++(int)
        {
            Time temp(*this);   //% Making a copy of the caller object
            second++;

            normalize();

            return temp;    //% Return the copy
        }

        //$ Declarations of friends
        friend std::ostream& operator<<( std::ostream&, const Time& );
        friend std::istream& operator>>( std::istream&, Time& );

        //$ Overloaded = operator, assigns/copies the passed object to caller object

        Time& operator=(const Time& t)
        {
            /* this->hour = t.hour;
            this->minute = t.minute;
            this->second = t.second;

            return *this; */
            Time temp = t;
            return temp;
        }
};

//@ Overloaded Friend Operators

//$ Friend Overloaded Insertion Op.

std::ostream& operator<<( std::ostream& dout, const Time& t)
{
    if (t.isValid) 
    {
        dout<<"The time is "<<(t.hour < 10 ? "0" : "")<<t.hour<<":"<<(t.minute < 10 ? "0" : "")<<t.minute<<":"<<(t.second < 10 ? "0" : "")<<t.second<<std::endl;
    }
    else
    {
         dout << "Time not set or is invalid!";
    }
    return dout;
}

//$ Friend Overloaded Extraction Op.

std::istream& operator>>( std::istream& din, Time& t)
{
    din>>t.hour>>t.minute>>t.second;
    t.setTime(t.hour, t.minute, t.second); //& validate and update `isValid`

    return din;
}

int main()
{
    Time t1, t2;
    t1.setTime(23, 34, 3);
    t2.setTime(15, 36, 3);

    std::cout<<"Time 1 is :";
    std::cout<<t1<<std::endl;
    std::cout<<"Time 2 is :";
    std::cout<<t2<<std::endl;

    Time t3 = t1 + t2;
    std::cout<<"The added time is :";
    std::cout<<t3<<std::endl;

    if ( t1 > t2 )
        std::cout<<"Caller Time is greater than the passed Time"<<std::endl;
    else
        std::cout<<"Passed Time is greater than the caller Time"<<std::endl;

    std::cout<<"Pre Increment -\n";
    ++t3;
    std::cout<<t3<<std::endl;

    std::cout<<"Pre Increment with returning object -\n";
    Time t4 = ++t3; //& Here, modified t3 is copied to t4, to recieve the ref. of t3 we need to use a ref variable Time& t4;
    t4.showTime();
    t3.showTime();
  
    std::cout<<"Post Increment -\n";
    t3++;
    std::cout<<t3<<std::endl;

    std::cout<<"Post Increment with returning object -\n";
    t4 = t3++;
    std::cout<<t4<<std::endl;
    std::cout<<t3<<std::endl;

    Time t5;
    t5 = t3;
    std::cout<<"Overloaded Assignment op. :\n"<<t5<<std::endl;;

    std::cin.get();
    return 0;
}