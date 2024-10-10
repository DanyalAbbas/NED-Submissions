#include <stdio.h>

int main()
{
    int year;
    printf("Give man the year innit?!? : ");
    scanf("%d", &year);

    if (year % 4 == 0 && year % 400 == 0)
        printf("BOMBACLAAT THE YEAR BE LEAPING YKNOW!?");
    else
        printf("SHUTUP FAM, THIS AINT NO LEAP YEAR YOU JOKEMAN");
}