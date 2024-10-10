#include <stdio.h>

int main()
{
    int number, i;
    int add = 0;

    printf("Enter any number ji : ");
    scanf("%d", &number);

    for (i=1; i<=number; i++)
        add += i;

    printf("The added value if %d", add);

}