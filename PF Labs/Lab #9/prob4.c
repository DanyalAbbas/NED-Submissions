#include <stdio.h>
#include <math.h>

float Squeezer(float a);
int main()
{
    float number;
    printf("write a number bbg : ");
    scanf("%f", &number);

    printf("The new smaller number is : %.2f", Squeezer(number));
}

float Squeezer(float a)
{
    return round(a * 100) / 100;
}
