#include <stdio.h>

int main()
{
    int rows, comp;
    rows = 5;

    for (int i = 0; i < 2*rows-1; i++)
    {
        if (i < rows)
            comp = 2*(rows-i)-1;
        else
            comp = 2*(i-rows+1)+1;

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