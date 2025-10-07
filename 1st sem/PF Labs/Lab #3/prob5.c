#include <stdio.h>

int main ()
{
    double principle, rate, interest;
    int time;
    printf("Enter the principal amount (100 Rs to 1,000,000 Rs) :3 :  ");
    scanf("%lf", &principle);
    printf("\nEnter the rate of interest (5%% to 10%%) :3 : ");
    scanf("%lf", &rate);
    printf("\nEnter the time period in years (1 to 10 years) :3 : ");
    scanf("%d", &time);

    interest = (principle * rate * time) / 100;

    printf("\nYour interest rate is 0_0 : %lf Rs", interest);

}