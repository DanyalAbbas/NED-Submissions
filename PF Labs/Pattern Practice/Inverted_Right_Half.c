#include <stdio.h>

int main()
{
    int rows, count;
    rows = 5;

    for (int i = 0; i < rows; i++)
    {
        count = 1;
        for (int j = 5; j > i; j--)
        {
            printf("%d ", count);
            count++;
        }
        printf("\n");
    }
}