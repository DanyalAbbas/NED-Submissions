#include <stdio.h>

void main()
{
    float dollar, pkr, euro;
    printf("Enter paisa in dallar : ");
    scanf("%f", &dollar);

    pkr = 280 * dollar;
    euro = 0.9 * dollar;

    printf("\nThe converted money from rupee is %.2f :0", pkr);
    printf("\nThe converted money from euro is %.2f :0", euro);
    

}