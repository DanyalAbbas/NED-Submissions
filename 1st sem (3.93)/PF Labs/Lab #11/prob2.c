#include <stdio.h>

void swap(int *a, int *b, int *c)
{
    int temp = *b;
    *b = *a;
    *a = *c;
    *a = temp;

}

int main()
{
    int a = 1, b = 2, c = 3;
    printf("Before : %d, %d, %d", a,b,c);
    swap(&a,&b,&c);
    printf("\nAfter : %d, %d, %d", a,b,c);
}