#include<iostream>
#include <limits>
#include <string>
using namespace std;

class Room
{
    private :

        int roomNumber;
        string roomType;
        bool isAC, isValid;

    public :

        Room(int roomNumber, string roomType, bool isAC)
        :
            roomNumber(roomNumber), roomType(roomType), isAC(isAC), isValid(true)
        {
            if ( roomNumber < 0 || roomType.empty())
            {
                isValid = false;
                cout<<"The Room details are invalid!\n";
            }
        }

        void displayRoom() const
        {
            if ( isValid )
            {
                cout<<"The Room data is :\n";
                cout<<"Room Number : "<<roomNumber<<endl;
                cout<<"Room Type : "<<roomType<<endl;
                cout<<"Is the Room AC or not : "<<(isAC ? "Yes" : "No")<<endl;
            }
            else
                cout<<"Room details are invalid and cannot be displayed!\n";
        }


};

int main()
{
    Room r1(101, "Deluxe", true);
    r1.displayRoom();

    Room r2(-5, "", false);  
    r2.displayRoom();

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}