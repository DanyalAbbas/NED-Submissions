#include <stdio.h>

int main()
{
    int number, i;
    printf("ENTER A NUMBER YOU TWAT : ");
    scanf("%d", &number);

    i = 1;
    while (i==1)
    {
        printf("%d", number%10);
        number = number/10;
        if (number < 1)
            break;
    }
}