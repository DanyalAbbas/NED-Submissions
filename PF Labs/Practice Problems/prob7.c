#include <stdio.h>

int main()
{
    int consonant = 0, vowel = 0;
    char character, choice;

    do
    {
        printf("ENTER CHARACTER BIATCH : ");
        scanf(" %c", &character);

        if (character == 'a' || character == 'o' || character == 'i' || character == 'o' ||character == 'u')
            vowel++;
        else
            consonant++;
        
        printf("Do you wana continue bbg?[y/n] : ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    printf("\nvowels be like : %d", vowel);
    printf("\nconsonents be like : %d", consonant);
}