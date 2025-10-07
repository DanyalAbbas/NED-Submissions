#include <stdio.h>

int main()
{
    int rows;
    rows = 5;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            printf(" ");
        }
        int coef = 1;

        for (int j = 1; j <= i; j++)
        {
            printf("%d ",coef);
            coef = coef * (i-j)/j;

        }
        printf("\n");
    }
}