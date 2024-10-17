#include <stdio.h>

int main()
{
    int rows;
    rows = 5;

    for (int i = 0; i < rows; i++)
    {
        // For Spacing
        for (int j = 0; j < rows -i -1; j++)
        {
            printf("  ");
        }

        for (int j = 0; j <= 2*i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}