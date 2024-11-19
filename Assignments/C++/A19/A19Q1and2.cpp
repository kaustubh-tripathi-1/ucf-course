#include<iostream>

class Game
{
    protected :

        int scores[5];

    public :

        Game()
        {
            for ( int i = 0 ; i < 5 ; i++ )
            {
                scores[i] = 0;
            }
        }

        Game(const Game &game2)
        {
            for ( int i = 0 ; i < 5 ; i++ )
            {
                this->scores[i] = game2.scores[i];
            }
        }

        void setScore(int *scores = nullptr)
        {
            if ( scores != nullptr)
            {
                for ( int i = 0 ; i < 5 ; i++ )
                {
                    this->scores[i] = scores[i];
                }
            }
            else
            {
                std::cout<<"Enter scores of each round :\n";
                for ( int i = 0 ; i < 5 ; i++ )
                {
                    std::cout<<"Enter score of round "<<i+1<<" :\n";
                    std::cin>>this->scores[i];
                }
            }
        }

        void setScore(int round, int score)
        {
            if( round >= 1 && round <= 5)
                this->scores[round - 1] = score;
            else
                std::cout<<"Invalid Round Value!\n";
        }

        int getScore(int round) const
        {
            if( round >= 1 && round <= 5)
                return this->scores[round-1];
            else
            {
                std::cout<<"Invalid Round Value!\n";
                return -1;
            }
        }
};

constexpr int WIN = 2;
constexpr int LOSE = 0;
constexpr int DRAW = 1;

class GameResult : public Game
{
    private :


    public :

        GameResult()
        :
            Game()
        {
            for (int i = 0; i < 5; i++)
            {
                scores[i] = DRAW; // Default to draw
            }
        }

        GameResult(const GameResult &game2)
        :
            Game(game2) {}

        void setResult(int round, int result)
        {
            if (round >= 1 && round <= 5)
            {
                if (result >= 0 && result <= 2)
                {
                    this->scores[round - 1] = result;
                }
                else
                {
                    std::cout << "Invalid Result Value! It should be 0, 1, or 2.\n";
                }
            }
            else
            {
                std::cout << "Invalid Round Value! Round should be between 1 and 5.\n";
            }
        }

        int getResult(int round) const
        {
            if ( round >= 1 && round <= 5 )
                return this->scores[round - 1];
            else
            {
                std::cout<<"Invalid Round Value!\n";
                return -1;
            }
        }

        int calculateFinalResult() const
        {
            int finalResult = 0;

            for ( int i = 0 ; i < 5 ; i++ )
            {
                finalResult += scores[i];
            }

            return finalResult;
        }

};

int main()
{
    //& Create a GameResult object
    GameResult game;

    //& Set scores manually
    int scores[] = {10, 20, 15, 25, 30};
    game.setScore(scores);

    //& Set results for each round
    game.setResult(1, WIN);
    game.setResult(2, LOSE);
    game.setResult(3, DRAW);
    game.setResult(4, WIN);
    game.setResult(5, LOSE);

    //& Get and display scores
    for (int i = 1; i <= 5; i++)
    {
        std::cout << "Score for Round " << i << ": " << game.getScore(i) << "\n";
        std::cout << "Result for Round " << i << ": " << game.getResult(i) << "\n";
    }

    //& Calculate final result
    std::cout << "Final Result: " << game.calculateFinalResult() << "\n";  

    std::cin.get();
    return 0;
}