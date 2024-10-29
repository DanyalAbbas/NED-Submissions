#include <stdio.h>
#include <string.h>

int main (void)
{
    char a[11] = "hello world";
    int i;
    for(i = 0; i <= 9; i++)
    {
        a[i] = a[i + 1];
        printf("%d \t %s \n", i, a);
    }
    printf("\n %d", a);
}