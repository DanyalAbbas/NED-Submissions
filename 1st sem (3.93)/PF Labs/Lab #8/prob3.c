#include <stdio.h>
#include <string.h>

int main()
{
    char str1[20], str2[20];
    printf("Enter string by student 1 : ");
    scanf("%s", &str1);
    printf("Enter string by student 2 : ");
    scanf("%s", &str2);

    if (strcmp(str1,str2) == 0)
        printf("THE STRINGS ARE EQUALLLL!!");
    else if (strcmp(str1,str2) > 0)
        printf("%s", str1);
    else
        printf("%s", str2);
}