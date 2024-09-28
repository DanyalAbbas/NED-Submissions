#include <stdio.h>
#include <conio.h>

int main()
{
    int type, quantity, total_amount, i;
    char snacks;

    printf("\tBELLA KHAO RESTAURENT ONLINE ORDER PLACEMENT");
    printf("\n\t\t\tWELCOME!! >:3");
    printf("\n\n--------------------------------");
    printf("\nPlease select from following menu;");
    printf("\nB = Burger\t(Rs.200)");
    printf("\nF = French Fries\t(Rs.50)");
    printf("\nP = Pizza\t(Rs.500)");
    printf("\nS = Sandwiches\t(Rs.150)");
    printf("\n--------------------------------");


    printf("\n\nHow many types of snacks do you need ji? : ");
    scanf("%d", &type);

    for (i = 1; i <= type; i++)
    {
        printf("\nEnter snack no. %d you want to order : ", i);
        scanf(" %c", &snacks);
        printf("Enter the quantity : ");
        scanf("%d", &quantity);


        switch (snacks)
        {
        case 'B': total_amount += 200 * quantity;
                  printf("\nAdded %d Burger(s) to your list :3\n", quantity);
            break;
        case 'F': total_amount += 50 * quantity;
                  printf("\nAdded %d French Fries to your list :3\n", quantity);
            break;
        case 'P': total_amount += 500 * quantity;
                  printf("\nAdded %d Pizza(s) to your list :3\n", quantity);
            break;
        case 'S': total_amount += 150 * quantity;
                  printf("\nAdded %d Sandwich(es) to your list :3\n", quantity);
            break;
        default: printf("\nWrong input >:(\n");
            break;
        }
    }

    printf("\nYour final price is %d", total_amount);
}