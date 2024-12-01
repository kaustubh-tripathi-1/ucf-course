#include<iostream>
#include<string>
#include<fstream>

int main()
{
    /* std::fstream file1("sourceFile.txt", std::ios::out);
    if ( file1.is_open())
    {
        file1<<"My name is Kaustubh Tripathi and I live in Ghaziabad.\nObviously aishdisa.\n";
        file1.close();
    }
    else
    {
        std::cout<<"Unable to open files.\n";
    }

    std::fstream file2("destinationFile.txt", std::ios::out);

    file1.open("sourceFile.txt", std::ios::in);

    if ( file1.is_open() && file2.is_open())
    {
        std::string line;

        while( std::getline(file1, line))
        {
            file2<<line<<"\n";
        }

        file1.close();
        file2.close();

    }
    else
    {
        std::cout<<"Unable to open files again.\n";
    } */

   std::fstream file1("sourceFile.txt", std::ios::in);
   std::fstream file2("destinationFile.txt", std::ios::out | std::ios::trunc);

    if ( file1.is_open() && file2.is_open() )
    {
        std::string line;

        while( std::getline( file1, line ))
        {
            file2<<line<<"\n";
        }

        file1.close();
        file2.close();
    }
   else
    {
        std::cout<<"Unable to open files again.\n";
    }
    

    std::cin.get();
    return 0;
}