#include<iostream>
#include<limits>
#include<string>

class String
{
    private :

        int length, capacity;
        char *ptrStr;

        void expandCapacity()
        {
            //$ Double the capacity if more space is needed
            this->capacity *= 2;
            
            char *newStr = new char[this->capacity]();

            //$ Copy the existing chars
            for ( int i = 0 ; i < this->length ; i++)
            {
                newStr[i] = this->ptrStr[i];
            }

            delete[] this->ptrStr;
            this->ptrStr = newStr;
            
        }

    public :

        //$ Default Constructor, not allowed to make an object with parameterized constructor
        String() : length(0), capacity(10), ptrStr(new char[capacity]()) {}

        //$ Copy Constructor
        String ( const String &s)
        :
            length(s.length), capacity(s.capacity)
        {
            
            if ( length > 0 )
            {
                this->ptrStr = new char[s.length]();

                int i;
                for ( i = 0 ; i < this->length ; i++)
                {
                    this->ptrStr[i] = s.ptrStr[i];
                }
                this->ptrStr[this->length] = '\0';

            }
        }

        //$ Destructor
        ~String()
        {
            std::cout<<"Array Block deleted\n";
            delete[] this->ptrStr;
        }

        void createString()
        {
            std::cout<<"Enter the string :\n";
            
            //& Without Memory Wastage but not much efficient bcoz of too much alloc and dealloc
            /* this->length = 1;
        
            char *str1 = nullptr;
            char *str2 = nullptr;

            while (1)
            {
                char ch = getchar();
                if ( ch == '\n')
                    break;
                
                str1 = new char[this->length]();
                
                if ( str2 != nullptr )
                {
                    for ( int i = 0 ; i < this->length ; i++)
                    {
                        str1[i] = str2[i];
                    }

                    str1[this->length-1] = ch;
                    delete[] str2;
                }
                else
                {
                    *str1 = ch;
                }

                str2 = new char[this->length+1]();

                for ( int i = 0 ; i < this->length ; i++)
                {
                    str2[i] = str1[i];
                }

                str2[this->length] = '\0';
                delete[] str1;

                this->length++;
                this->ptrStr = str2;
            }    

            this->length--; //& Decrement the length as it doesn't include the \0 */


            //& Doubling Strategy, Less alloc and dealloc but potential trade-off of some memory wastage

            char ch;
            while ( (ch = getchar()) != '\n' )
            {
                if ( this->length + 1 >= this->capacity )
                {
                    expandCapacity();
                }

                //$ Add the character and increment length
                this->ptrStr[this->length++] = ch;

            }

            //$ Null terminate the string
            this->ptrStr[this->length] = '\0';
            this->length--;
        }

        friend std::ostream& operator<<(std::ostream &out, const String &str)
        {
            out<<"The string is -\n";
            
            for ( int i = 0 ; str.ptrStr[i] != '\0' ; i++)
            {
                out<<str.ptrStr[i];
            }

            out<<"\n";

            return out;
        }

        //$ Length Getter
        int getLength() const
        {
            return this->length;
        }

        //$ Convert to Lower Case
        String& toLowerCase()
        {
            for ( int i = 0 ; i < this->length ; i++)
            {
                if ( this->ptrStr[i] >= 'A' && this->ptrStr[i] <= 'Z')
                    this->ptrStr[i] += 32;
            }

            return *this;
        }

        //$ Convert to Upper Case
        String& toUpperCase()
        {
            for ( int i = 0 ; i < this->length ; i++)
            {
                if ( this->ptrStr[i] >= 'a' && this->ptrStr[i] <= 'z')
                    this->ptrStr[i] -= 32;
            }

            return *this;
        }

        //$ Return the string
        //& Returning the actual base address of string
        /* char* returnString() const
        {
            return this->ptrStr;
        } */

        //& Returning a string object
        std::string returnString()
        {
            return std::string(this->ptrStr, this->length);     //& Don't need to explicitly copy the \0 by passing this->length, as the std::string constructor will automatically append the \0
        }

};

int main()
{
    String s1;

    
    s1.createString();

    std::cout<<s1;

    int lengthOfString = s1.getLength();

    std::cout<<"The length of the string is : "<<lengthOfString<<"\n";

    std::cout<<"Lower Case String :\n";
    std::cout<<s1.toLowerCase();

    std::cout<<"Upper Case String :\n";
    std::cout<<s1.toUpperCase();

    /* char *retreivedStr = s1.returnString();
    std::cout<<"The returned string is :\n";
    for ( int i = 0 ; i < s1.getLength() ; i++)
    {
        std::cout<<retreivedStr[i];
    } */

   std::string retreivedStr = s1.returnString();
   std::cout<<"The returned string :\n"<<retreivedStr;

    std::cin.get();
    return 0;
}