#include <stdio.h>
#include <string.h>

int main()
{
    char string[20], reversed[20];

    printf("Enter a string : ");
    gets(string);

    StringHandler(string);

    int i = strlen(string) - 1, j = 0;
    
    while (i >= 0)
    {
        reversed[j] = string[i];
        i--;
        j++;
    }

    if (strcmp(string, reversed) == 0)
        printf("IT IS A PALINDROME");
    else
        printf("NUH UH");

}

void StringHandler(char *str)
{
    int i = 0, index = 0;
    char new_str[20];
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            {i++;continue;}
        else if (str[i] >=65 && str[i] <= 90)
            str[index] = str[i] + 32;
        
        else
            str[index] = str[i];
        index++;
        i++;

    }

}