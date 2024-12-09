#include <stdio.h>

int main()
{
    int amount_spent, discounted;
    printf("YIOPPEEE!! it eid so there is discount now >:3");
    printf("\nHow much did you spend shopping so your discount rate could be evaluated : ");
    scanf("%d", &amount_spent);

    if (amount_spent < 1999)
    {
        printf("\nYOU GOT 10%% DISCOUNT");
        printf("\nBefore discount : %d", amount_spent);
        discounted = (float)amount_spent - ((float)amount_spent *0.1);
        printf("\nAfter discount : %d", discounted);
    }
    else if (amount_spent > 1999 && amount_spent < 4001)
    {
        printf("\nYOU GOT 20%% DISCOUNT");
        printf("\nBefore discount : %d", amount_spent);
        discounted = (float)amount_spent - ((float)amount_spent *0.2);
        printf("\nAfter discount : %d", discounted);
    }
    else if (amount_spent > 4000 && amount_spent < 6001)
    {
        printf("\nYOU GOT 30%% DISCOUNT");
        printf("\nBefore discount : %d", amount_spent);
        discounted = (float)amount_spent - ((float)amount_spent *0.3);
        printf("\nAfter discount : %d", discounted);
    }
    else if (amount_spent > 6000)
    {
        printf("\nYOU GOT 50%% DISCOUNT");
        printf("\nBefore discount : %d", amount_spent);
        discounted = (float)amount_spent - ((float)amount_spent *0.5);
        printf("\nAfter discount : %d", discounted);
    }
    else
        printf("Invalid amount");
}