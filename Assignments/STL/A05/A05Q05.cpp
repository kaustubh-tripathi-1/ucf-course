#include<iostream>
#include<vector>

void printVector(const std::vector<int> &nums)
{
    for ( auto i = nums.cbegin() ; i != nums.cend() ; i++ )
    {
        std::cout<<*i<<" ";
    }
    std::cout<<"\n";

}

int main()
{
    try
    {
        std::vector<std::vector<int>> vec = {{1, 2, 3, 4, 5},
                                            {6, 7, 8, 9, 10},
                                            {11, 12, 13, 14, 15}
                                            };

        std::vector<int> customVector;
        // std::vector<std::vector<int>>::iterator j = vec.begin();

        /* customVector.insert(customVector.end(), (*j).begin(), (*j).begin()+3 );
        j++;
        customVector.insert(customVector.end(), (*j).end()-2, (*j).end() );
        j++;
        customVector.insert(customVector.end(), (*j).begin(), (*j).end() );
        printVector(customVector); */
        customVector.insert(customVector.end(), vec[0].begin(), vec[0].begin()+3 );
        customVector.insert(customVector.end(), vec[1].end()-2, vec[1].end() );
        customVector.insert(customVector.end(), vec[2].begin(), vec[2].end() );
        printVector(customVector);
    }
    catch(const std::exception &e)
    {
        std::cerr<<e.what()<<"\n";
    }

                                        
    std::cin.get();
    return 0;
}