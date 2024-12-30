#include <stdio.h>

float CostCalculator(int initial_cost, int fuel_cost, float tax_rate);
int main()
{
    int a,b;
    float c;
    printf("initial cost: ");
    scanf("%d", &a);
    printf("fuel cost: ");
    scanf("%d", &b);
    printf("tax rate: ");
    scanf("%f", &c);

    printf("5-year period price : %.2f", CostCalculator(a,b,c));
}

float CostCalculator(int initial_cost, int fuel_cost, float tax_rate)
{
    float house_cost = 0;
    house_cost = initial_cost + (fuel_cost*5);
    house_cost += (initial_cost*tax_rate)*5;
    return house_cost;
}