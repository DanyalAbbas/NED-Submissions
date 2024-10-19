#include <stdio.h>

int main()
{
    int principal, rate_of_interest, time;
    int simple_interest;

    printf("What is the principal bbg? : ");
    scanf("%d", &principal);
    printf("What is the rate of interest bbg? : ");
    scanf("%d", &rate_of_interest);
    printf("What is the time bbg? : ");
    scanf("%d", &time);

    simple_interest = (principal*rate_of_interest*time)/100;

    printf("Your simple interest is %d", simple_interest);
}