#include <stdio.h>

int main()
{
    char FirstName[20], SecondName[20], FullName[40];
    int count = 0, i;

    printf("Enter first name : ");
    scanf("%s", &FirstName);
    printf("Enter second name : ");
    scanf("%s", &SecondName);

    i = 0;
    while (FirstName[i] != '\0')
    {
        FullName[count] = FirstName[i];
        i++;
        count++;
    }
    FullName[count] = ' ';
    count++;
    i = 0;
    while (SecondName[i] != '\0')
    {
        FullName[count] = SecondName[i];
        i++;
        count++;
    }
    FullName[count] = '\0';

    printf("Your full name is %s and its length is %d", FullName, count);
    



}