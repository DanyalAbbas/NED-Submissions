#include <stdio.h>

int main()
{
    int a = 8, b = 13, x = 0, y = 10;
    for (int k = --a; k < b; k++)
    {
        x = x + k;
        printf("%d\n", y);
        y = y - x--;
        printf("%d %d\n", x,y);
    }
}