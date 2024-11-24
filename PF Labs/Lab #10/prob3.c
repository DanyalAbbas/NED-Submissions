#include <stdio.h>

typedef struct
{
    int areacode;
    int exchange;
    int number;
}PhoneNumber;


int main()
{
    PhoneNumber n;
    printf("Enter area code: ");
    scanf("%d", &n.areacode);
    printf("Enter exchange: ");
    scanf("%d", &n.exchange);
    printf("Enter number: ");
    scanf("%d", &n.number);

    printf("(%d) %d-%d", n.areacode, n.exchange, n.number);


}