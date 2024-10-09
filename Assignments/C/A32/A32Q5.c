#include<stdio.h>
#include<conio.h>

void countElementFrequency(int [], int);

int main()
{
    int size, numbers[] = {1, 2, 1, 1, 4, 3, 5, 5, 3, 2, 4, 9};
    size = sizeof(numbers) / sizeof( numbers[0]);

    printf("Each element frequency in the array is - \n");

    countElementFrequency(numbers, size);

    getch();
    return 0;
}

//@ Counting Element Frequency
void countElementFrequency(int numbers[], int size)
{
    int i, j, visited[size], count;

    for ( i = 0; i < size; i++)
        visited[i] = 0;
    

    for( i=0 ; i < size ; i++)
    {
        if(visited[i] == 1)
            continue;
        
        count = 1;
        
        for( j=i+1 ; j < size ; j++) 
        {
            if( numbers[i] == numbers[j] )
            {
                count++;
                visited[j] = 1;
            }
        }

        printf("Frequency of %d - %d.\n", numbers[i], count);
    }
    
}