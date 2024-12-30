#include <stdio.h>

int main()
{
    int number, i;
    int add = 0;

    printf("Enter any number ji : ");
    scanf("%d", &number);

    i = 1;
    while (i == 1)
    {
        add += number%10;
        number /= 10;
        
        if (number < 1)
            break;
    }

    printf("The added value if %d", add);

}