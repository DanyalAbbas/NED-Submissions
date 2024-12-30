#include <stdio.h>

int main()
{
    int number, last_digit, remaining;

    printf("Enter a number to find out if it is divisible by 7 :3 : ");
    scanf("%d", &number);

    while (number >= 10)
    {
        last_digit = number%10;
        remaining = number/10;
        last_digit *= 2;

        number = remaining - last_digit;
    }

    if (number == -7 || number == 0 || number == 7)
        printf("\nThe number is indeed divisible by 7 ji :3");
    else
        printf("\nnuh uh ji not divisible");
}