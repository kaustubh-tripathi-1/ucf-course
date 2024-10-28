#include<iostream>
#include <limits>
using namespace std;

//@ Class for Test Result
class TestResult
{
    private :

        int rollNo, rightlyAnswered, wronglyAnswered;
        bool validRollNo = false;
        double netScore;
        static int rightWeightage, wrongWeightage, totalQuestions;
    
    public :

        //$ Sets the Roll number for a student
        void setRollNo( int rollNo )
        {
            if( rollNo > 0 )
            {
                this->rollNo = rollNo;
                validRollNo = true;
            }
            else
                cout<<"Invalid Roll No.! Can't be -ve"<<endl;
        }

        //$ Returns the Roll number of a student
        int getRollNo()
        {
            if ( validRollNo )
                return rollNo;
            else
            {
                cout<<"Valid Roll No. was not set."<<endl;
                return -1;
            }
        }

        //$ Sets the number of Questions that are answered right and wrong by the student
        void setRightAnswered(int rightlyAnswered)
        {
            if ( rightlyAnswered >= 0 && rightlyAnswered <= totalQuestions )
                this->rightlyAnswered = rightlyAnswered;
            else
                cout<<"No. of Right ANswered questions must be from 0 to "<<totalQuestions<<endl;
        }

        void setWrongAnswered(int wronglyAnswered)
        {
            if ( wronglyAnswered >= 0 && wronglyAnswered <= (totalQuestions - rightlyAnswered) )
                this->wronglyAnswered = wronglyAnswered;
            else
                cout<<"No. of Wrong Answered questions be from 0 to "<<(totalQuestions - rightlyAnswered)<<endl;
        }

        //$ Gets the number of Questions that are answered right and wrong by the student
        int getRightAnswered()
        {
            
            return rightlyAnswered;
        }
        int getWrongAnswered()
        {
            return wronglyAnswered;
        }

        //$ Sets the net score of the result
        void setNetScore()
        {
            netScore = (rightlyAnswered * rightWeightage) - ( wronglyAnswered * wrongWeightage );
        }

        //$ Returns the net score of the result
        double getNetScore()
        {
            return netScore;
        }

        //$ Sets the right and wrong weightage
        static void setRightWeightage(int rightWeight)
        {
            if ( rightWeight > 0 )
                rightWeightage = rightWeight;
            else
                cout<<"Right weightage cannot be -ve"<<endl;
        }

        static void setWrongWeightage(int wrongWeight)
        {
            if ( wrongWeight > 0)
                wrongWeightage = wrongWeight;
            else
                cout<<"Wrong weightage cannot be -ve"<<endl;
        }

        //$ Sets the total number of questions
        static void setTotalQuestions(int questions)
        {
            totalQuestions = questions;
        }

        //$ Shows result of the student
        void showResult()
        {
            cout<<"Student Roll No.                    : "<<rollNo<<"\n";
            cout<<"No. of Qs answered right by student : "<<rightlyAnswered<<"\n";
            cout<<"No. of Qs answered wrong by student : "<<wronglyAnswered<<"\n";
            cout<<"Net Score of the student            : "<<netScore<<"\n";
        }

        //$ Sorts the objects by Net Score in ascending order
        static void sortStudentsNetScoreAscending(TestResult *arr, int size)
        {
            int i, j;

            for ( i = 0 ; i < size-1 ; i++)
            {
                for ( j = 0 ; j < size-i-1 ; j++)
                {
                    if ( arr[j].netScore > arr[j+1].netScore )
                    {
                        TestResult temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }

        //$ Sorts the objects by Net Score in descending order
        static void sortStudentsNetScoreDescending(TestResult *arr, int size)
        {
            int i, j;

            for ( i = 0 ; i < size-1 ; i++)
            {
                for ( j = 0 ; j < size-i-1 ; j++)
                {
                    if ( arr[j].netScore < arr[j+1].netScore )
                    {
                        TestResult temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }

        //$ Sorts the objects by Roll No. in ascending order
        static void sortStudentsRollNumber(TestResult *arr, int size)
        {
            int i, j;

            for ( i = 0 ; i < size-1 ; i++)
            {
                for ( j = 0 ; j < size-i-1 ; j++)
                {
                    if ( arr[j].rollNo < arr[j+1].rollNo )
                    {
                        TestResult temp = arr[j];
                        arr[j] = arr[j+1];
                        arr[j+1] = temp;
                    }
                }
            }
        }
};

int TestResult::rightWeightage, TestResult::wrongWeightage, TestResult::totalQuestions;

int main()
{
    TestResult students[5];

    TestResult::setRightWeightage(4);
    TestResult::setWrongWeightage(1);
    TestResult::setTotalQuestions(25);

    for ( int i = 0 ; i < 5 ; i++)
    {
        students[i].setRollNo(i+1);
    }

    students[0].setRightAnswered(20);
    students[0].setWrongAnswered(5);

    students[1].setRightAnswered(18);
    students[1].setWrongAnswered(7);

    students[2].setRightAnswered(11);
    students[2].setWrongAnswered(14);

    students[3].setRightAnswered(23);
    students[3].setWrongAnswered(2);

    students[4].setRightAnswered(25);
    students[4].setWrongAnswered(0);



    for ( int i = 0 ; i < 5 ; i++ )
    {
        students[i].setNetScore();
    }

    TestResult::sortStudentsNetScoreAscending(students, 5);
    
    for ( int i = 0 ; i < 5 ; i++ )
    {
        cout<<"Result of Student :"<<"\n";
        students[i].showResult();
        cout<<"\n";
    }
        

    // while ( getchar() != '\n');
    cin.get();
    return 0;
}