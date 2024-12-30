#include <stdio.h>

int main()
{
    char str[20];
    int i = 0;

    printf("Enter any string : ");
    gets(str);

    while (str[i] != NULL)
        i++;
    
    printf("Length is : %d", i);
}