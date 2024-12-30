#include <stdio.h>

int main()
{
    long value1 = 200000, value2;
    long *lPtr;

    lPtr = &value1;
    printf("%ld", *lPtr);
    value2 = *lPtr;
    printf("\n%ld", value2);
    printf("\nAdress of val 1 : %p", &value1);
    printf("\nAddress stored in ptr : %p", lPtr);
}