#include <stdio.h>
#include <stdlib.h>


int main()
{
    int i, guess;
    int random = rand() % 100 + 1; // this only generates random numbers from 1 - 100

    random = 70; // making random value 70 for easy understanding for now
    
    i = 1;
    while (i == 1)
    {
        printf("\nNUMBER GUESS KARO JI >:3 : ");
        scanf("%d", &guess);
        
        if (guess == random)
        {
            printf("YIOPEEEEEE, YOU GUESSED THE NUMBER BBG >:3");
            break;
        }
        else if (guess > random)
            printf("too high bbg :(");
        else
            printf("too low dumbass >:(");
    }  
}