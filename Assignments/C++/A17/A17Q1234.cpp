#include<iostream>
#include<algorithm>

class Time
{
    private :

        int hour, minute, second;
        bool isValid;

        bool isValidTime(int hour, int minute, int second)
        {
            return ( hour >= 0 && hour < 24
                    && minute >= 0 && minute < 60
                    && second >= 0 && second < 60
                    );
        }

    public :

        Time( int hour = 0, int minute = 0, int second = 0 )
        :
            hour(hour), minute(minute), second(second), isValid(true)
        {
            if ( !isValidTime(hour, minute, second ))
            {
                std::cout<<"Invalid Time values!\n";
                isValid = false;
            }
        }

        Time( const Time &t )
        :
            hour(t.hour), minute(t.minute), second(t.second) {}

        //$ Setters
        Time& setTime(int hour, int minute, int second)
        {
            if ( isValidTime(hour, minute, second ))
            {
                this->hour = hour;
                this->minute = minute;
                this->second = second;
                this->isValid = true;
            }
            else
            {
                std::cout<<"Invalid Time values!\n";
                this->isValid = false;
            }
                

            return *this;
        }

        Time& setHour(int hour)
        {
            if ( hour >= 0 && hour < 24)
                this->hour = hour;

            return *this;
        }

        Time& setMinute(int minute)
        {
            if ( minute >= 0 && minute < 60)
                this->minute = minute;

            return *this;
        }

        Time& setSecond(int second)
        {
            if ( second >= 0 && second < 60)
                this->second = second;

            return *this;
        }

        //$ Display Time
        Time& showTime()
        {
            if ( isValid )
            {
                //$ W/O using overloaded <<
                /* std::cout<<"The time is :\n";
                std::cout<<(hour < 10 ? "0" : "")<<hour<<":"
                        <<(minute < 10 ? "0" : "")<<minute<<":"
                        <<(second < 10 ? "0" : "")<<second
                        <<"\n"; */

                //$ Using overloaded <<

                std::cout<<*this;
                
            }

            return *this;
        }

        //$ Getters
        int getHour() const
        {
            return this->hour;
        }

        int getMinute() const
        {
            return this->minute;
        }

        int getSecond() const
        {
            return this->second;
        }

        friend std::ostream& operator<<( std::ostream &out, const Time &t)
        {
            if ( t.isValid )
            {
                out<<"The time is :\n";
                out<<"[" << (t.isValid ? "Valid" : "Invalid") << "] "<<(t.hour < 10 ? "0" : "")<<t.hour<<":"
                        <<(t.minute < 10 ? "0" : "")<<t.minute<<":"
                        <<(t.second < 10 ? "0" : "")<<t.second
                        <<"\n";
            }

            return out;
        }

        friend std::istream& operator>>( std::istream &in, Time &t)
        {
            std::cout<<"Enter hour, minute and seconds to set time :\n";
            in>>t.hour>>t.minute>>t.second;

            if ( t.isValidTime(t.hour,t.minute,t.second) )
            {
                t.isValid = true;
            }
            else
            {
                std::cout<<"Invalid Time Values!\n";
                t.hour = 0;
                t.minute = 0;
                t.second = 0;
                t.isValid = false;
            }

            return in;
        }
    
        //$ Static Methods, as there is no pointer instance member var. for class to contain Array address
        static Time* createDynamicArray(int size)
        {
            if ( size > 0)
            {
                return new Time[size]();
            }
            else
            {
                std::cout<<"Size cannot be 0 or -ve!\n";
                return nullptr;
            }
        }

        static void freeDynamicArray(Time *ptr)
        {
            delete []ptr;
        }

        static void showTimeArray(Time *ptrTimeArray, int size)
        {
            for ( int i = 0 ; i < size ; i++)
            {
                std::cout<<ptrTimeArray[i];
            }
        }

        static void setTimeArray(Time *ptrTimeArray, int size)
        {
            if ( ptrTimeArray != nullptr)
            {
                for ( int i = 0 ; i < size ; i++)
                {
                    std::cin>>ptrTimeArray[i];
                }
            }
            
        }

        static void sortTimeArray(Time *ptrTimeArray, int size)
        {
            int i, j;

            for ( i = 0 ; i < size-1 ; i++)
            {
                for ( j = 0 ; j < size-i-1 ; j++)
                {
                    
                    //& Using temp and manual swapping 
                    if ( ptrTimeArray[j].hour > ptrTimeArray[j+1].hour )
                    {
                        Time temp;
                        //$ Shallow copy is acceptable as Time data type doesn't contain any dyncamic resources
                        temp = ptrTimeArray[j];
                        ptrTimeArray[j] = ptrTimeArray[j+1];
                        ptrTimeArray[j+1] = temp;
                    }
                    else if ( ptrTimeArray[j].hour == ptrTimeArray[j+1].hour && ptrTimeArray[j].minute > ptrTimeArray[j+1].minute )
                    {
                        Time temp;
                        temp = ptrTimeArray[j];
                        ptrTimeArray[j] = ptrTimeArray[j+1];
                        ptrTimeArray[j+1] = temp;
                    }
                    else if ( ptrTimeArray[j].minute == ptrTimeArray[j+1].minute && ptrTimeArray[j].second > ptrTimeArray[j+1].second )
                    {
                        Time temp;
                        temp = ptrTimeArray[j];
                        ptrTimeArray[j] = ptrTimeArray[j+1];
                        ptrTimeArray[j+1] = temp;
                    }
                    
                }
            }
        }
};

int main()
{
    Time t1(1, 34, 45);
    std::cout<<"Using showTime() method :\n";
    t1.showTime();
    std::cout<<"Using Overloaded << :\n"<<t1;

    Time t2;
    std::cout<<"T2 with default values :\n";
    std::cout<<t2;
    t2.setTime(12, 13, 36);
    std::cout<<"T2 with set values :\n";
    std::cout<<t2;

    Time t3;
    std::cin>>t3;
    std::cout<<"T3 with set values using overloaded >> :\n";
    std::cout<<t3;

    int size = 5;
    Time *ptrTimeArray = Time::createDynamicArray(size);
    std::cout<<"Array created, All times set to 12:00:00 AM :\n";
    Time::showTimeArray(ptrTimeArray, size);

    std::cout<<"Now set Time elements in array :\n";
    Time::setTimeArray(ptrTimeArray, size);
    
    std::cout<<"After creating and setting time objects in array :\n";
    std::cout<<"Before Sorting the Array :\n";
    Time::showTimeArray(ptrTimeArray, size);

    Time::sortTimeArray(ptrTimeArray, size);
    std::cout<<"After Sorting the Array :\n";
    Time::showTimeArray(ptrTimeArray, size);

    Time::freeDynamicArray(ptrTimeArray);

    std::cin.get();
    return 0;
}