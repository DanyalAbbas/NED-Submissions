#include <stdio.h>

int main()
{
    int val1, val2, swapped;
    printf("Input value no 1 ji >:3 : ");
    scanf("%d", &val1);
    printf("\nInput value no 2 bbg : ");
    scanf("%d", &val2);

    swapped = val1;
    val1 = val2;
    val2 = swapped;

    printf("\n I ooga boogaed and now the value 1 and 2 are swapped and are %d and %d respectively", val1, val2);


}