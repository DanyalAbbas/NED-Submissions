#include <stdio.h>

int main()
{
    int number, average, add = 0, i = 0;
    char choice;

    do
    {
        printf("Enter a number : ");
        scanf("%d", &number);
        i += 1;
        add += number;

        average = add/i;
        printf("\nThe average is : %d", average);

        printf("\nDo you wana continue? [y/n] : ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

}