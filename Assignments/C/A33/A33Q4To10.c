#include<stdio.h>
#include<conio.h>

#define win 2
#define draw 1
#define loss 0

void validInputCheck(int *, int );
void validInputCheckPlayer(int *, int );
void validInputCheckOutcome(int *, int );
void updateScoreBoard(int scoreBoard[4][4], int, int, int );
void displayScoreBoard(int scoreBoard[4][4]);
void displayScoreOfPlayer(int scoreBoard[4][4], int player);
int findWinner( int scoreBoard[4][4] );
void displayRank(int scoreBoard[4][4]);
void runTournament(int scoreBoard[4][4]);

int main()
{
    int scoreBoard[4][4] = {0};
    
    runTournament(scoreBoard);

    displayScoreBoard(scoreBoard);

    displayScoreOfPlayer(scoreBoard, 1);
    displayScoreOfPlayer(scoreBoard, 2);
    displayScoreOfPlayer(scoreBoard, 3);
    displayScoreOfPlayer(scoreBoard, 4);

    int winner = findWinner(scoreBoard);

    printf("\n\nThe Winner of Tourney is Player %d.", winner);

    displayRank(scoreBoard);
    
    getch();
    return 0;
}

//@ Taking Input and Checking if it's valid
void validInputCheck(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || *n > 0))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}
//@ Taking Input for Players and Checking if it's valid
void validInputCheckPlayer(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n > 0 && *n < 5)))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}
//@ Taking Input for Outcome and Checking if it's valid
void validInputCheckOutcome(int *n, int allowNegative)
{
    int validInput;
    while (1)
    {
        validInput = scanf("%d", n);

        if(validInput == 1 && (allowNegative || (*n >= 0 && *n < 3)))
            break;
        else
        {
            printf("Enter a valid number!\n");
            while( getchar() != '\n');
        }
    }
}

//@ Update Score Board Function
void updateScoreBoard(int scoreBoard[4][4], int player1, int player2, int result )
{

    player1--;
    player2--;
    //$ Code when we have to worry about who wins while calling the function 
    /* if( player1 >= 0 && player1 < 4 && player2 >= 0 && player2 < 4 && (result == 0 || result == 1 || result == 2))
    {
        scoreBoard[player1][player2] = result;
        scoreBoard[player2][player1] = 2-result;
    }
    else
        printf("The player no. or the result constant is invalid."); */

    //$ W/O Worrying who wins while calling the function
    if( player1 >= 0 && player1 < 4 && player2 >= 0 && player2 < 4 && (result == 0 || result == 1 || result == 2))
    {
        if( result == win)
        {
            scoreBoard[player1][player2] = win;
            scoreBoard[player2][player1] = loss;
        }
        else if( result == loss)
        {
            scoreBoard[player1][player2] = loss;
            scoreBoard[player2][player1] = win;
        }
        else
        {
            scoreBoard[player1][player2] = draw;
            scoreBoard[player2][player1] = draw;
        }
    }
    else
        printf("The player no. or the result constant is invalid.");

}

//@ Display Score Board
void displayScoreBoard(int scoreBoard[4][4])
{
    printf("\n****Score Board****\n");
    for( int i = 0 ; i < 4 ; i++)
    {
        printf("Player %d - ", i+1);
        for( int j = 0 ; j < 4 ; j++)
            printf("%d ", scoreBoard[i][j]);

        printf("\n");
    }
    printf("\n");
}

//@ Know the score of a specific player
void displayScoreOfPlayer(int scoreBoard[4][4], int player)
{
    int scoreSum = 0;

    player--;

    if ( player >= 0 && player < 4)
    {
        for ( int i = 0; i < 4; i++)
            scoreSum += scoreBoard[player][i];

         printf("The score of Player %d is %d.\n", player+1, scoreSum);
    }
    else
    {
        printf("The player no. is invalid.");
    }
}

//@ Find The Winner of the tourney
int findWinner( int scoreBoard[4][4] )
{
    int playerScore[4]={0}, i, j;

    //$ Traversing the array Scoreboard to sum up the scores
    for ( i = 0; i < 4; i++)
        for ( j = 0; j < 4; j++)
            playerScore[i] += scoreBoard[i][j];


    //$ Finding the largest score in the Player Score array
    int largest = playerScore[0], winner=0;
    for ( i = 1 ; i < 4 ; i++)
    {
        if(largest < playerScore[i])
        {
            largest = playerScore[i];
            winner = i;
        }
    }
    return winner+1; 
}

void sort( int a[], int size, int playerIndex[])
{
    int i, j, temp;

    for ( i = 0; i < size - 1 ; i++)
    {
        for ( j = 0; j < size-i-1 ; j++)
        {
            if (a[j] < a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                temp = playerIndex[j];
                playerIndex[j] = playerIndex[j+1];
                playerIndex[j+1] = temp;
            }
        }
    }
            
    
}

//@ Function to Display Rank
void displayRank(int scoreBoard[4][4])
{
    int playerScore[4]={0}, i, j;

    //$ Traversing the array Scoreboard to sum up the scores
    for ( i = 0; i < 4; i++)
        for ( j = 0; j < 4; j++)
            playerScore[i] += scoreBoard[i][j];

    int playerIndex[4];

    for ( i = 0; i < 4; i++)
    {
        playerIndex[i] = i;
    }
    

    int size = sizeof(playerScore) / sizeof(playerScore[0]);

    //$ Sorting the player score array
    sort( playerScore, size, playerIndex );

    //$ Displaying Ranks

    printf("\n");
    printf("\n**************Ranks**************");
    for ( i = 0; i < size; i++)
    {
        printf("\nRank %d - Player %d with Score - %d.\n", i+1, playerIndex[i]+1, playerScore[i]);
    }
}

//@ Run Tournament Function
void runTournament(int scoreBoard[4][4])
{
    int matches, player1, player2, outcome;

    printf("Enter the number of maches to be held - \n");
    validInputCheck(&matches, 0);

    for( int i = 0 ; i < matches ; i++)
    {
        printf("For Match %d - \n", i+1);
        printf("Enter the player 1 - \n");
        validInputCheckPlayer(&player1, 0);
        printf("Enter the player 2 - \n");
        validInputCheckPlayer(&player2, 0);
        printf("Enter the outcome in constants -\n2 for Win, 1 for draw, 0 for loss - \n");
        validInputCheckOutcome(&outcome, 0);
        updateScoreBoard(scoreBoard, player1, player2, outcome);
    }
    
}