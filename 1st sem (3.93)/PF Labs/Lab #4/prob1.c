#include <stdio.h>

int main()
{
    int alphabet=0;
    printf("Input a alphabet character and me evaluate if it capital or small >:3 : ");
    scanf("%c", &alphabet);

    if (alphabet >= 97 && alphabet <= 122)
    {
        printf("\nThe input is small character >:3");
    }
    else if (alphabet >= 65 && alphabet <=90)
    {
        printf("\nThe input is capital character >:3");
    }
    else
    {
        printf("Invalid input : %d", alphabet);
    }
}