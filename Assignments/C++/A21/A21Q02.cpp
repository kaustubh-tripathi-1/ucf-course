#include<iostream>
#include<fstream>

int main()
{
    std::ifstream file("sourceFile.txt", std::ios::in);

    if ( file.is_open() )
    {
        std::string line;
        bool isEmpty = true;

        while( std::getline(file, line) )
        {
            isEmpty = false;
            std::cout<<line<<"\n";
        }

        if( isEmpty )
        {
            std::cout << "The file is empty.\n";
        }
    }
    else
    {
        std::cout<<"Unable to open the file.\n";
    }

    std::cin.get();
    return 0;
}