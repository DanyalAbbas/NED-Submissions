#include <stdio.h>

int main()
{
    int rows;
    rows = 5;

    for (int i = 0; i < 2*rows-1; i++)
    {
        int comp;
        if (i<rows)
            comp = 2*i+1;
        else
            comp = 2*(2*rows-i)-3;
        
        for (int j = 0; j < comp; j++)
        {
            printf(" ");
        }
        for (int j = 0; j < 2*rows - comp; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
}