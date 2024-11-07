#include <stdio.h>

void main()
{
    float dollar, pkr;
    printf("Enter paisa in dallar : ");
    scanf("%f", &dollar);

    pkr = 280 * dollar;

    printf("\nThe converted money is %.2f :0", pkr);
    

}