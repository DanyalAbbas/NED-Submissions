#include <stdio.h>

int main()
{
    char type, choice;
    int put_water, sugar, add_coffee, add_milk, mix_well, tot_time;
    printf("What type of coffee do you want >:3 [W/B]: ");
    scanf("%c", &type);

    switch (type)
    {
    case 'W': 
        put_water = 15;
        sugar = 15;
        mix_well = 20;
        add_coffee = 2;
        add_milk = 4;
        break;
    case 'B':
        put_water = 20;
        sugar = 20;
        mix_well = 25;
        add_coffee = 15;
        add_milk = 0;
        break;
    
    default:
        printf("Wrong input bbg >:(");
    }
    
    printf("\nDo you wana add water? [Y/N]");
    scanf(" %c", &choice);
    if (choice == "Y")
        tot_time += put_water;
    printf("\nDo you wana add sugar? [Y/N]");
    scanf(" %c", &choice);
    if (choice == "Y")
        tot_time += sugar;
    printf("\nDo you wana mix well? [Y/N]");
    scanf(" %c", &choice);
    if (choice == "Y")
        tot_time += mix_well;
    printf("\nDo you wana add coffee? [Y/N]");
    scanf(" %c", &choice);
    if (choice == "Y")
        tot_time += add_coffee;
    printf("\nDo you wana add milk? [Y/N]");
    scanf(" %c", &choice);
    if (choice == "Y")
        tot_time += add_milk;
    

    printf("Total time taken is %d mins", tot_time);


}