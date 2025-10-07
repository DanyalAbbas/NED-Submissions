#include <stdio.h>

int main()
{
    int rows; 
    rows = 5;

    for (int i = 0; i < rows; i++)
    {
        // For spaces
        for (int j = 0; j < 2 * (rows - i); j++)
        {
            printf(" ");
        }

        // For asteric/numeric/alphabet
        for (int j = 0; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}