#include <stdio.h>

int main()
{
    int fat, calories, cal_from_fat;
    do 
    {
        printf("\nHow many calories are in your food ji >:( : ");
        scanf("%d", &calories);

        if (calories <= 0)
            printf("\nbbg put the right amount of calories >:( : ");
    } while (calories <= 0);

    do
    {
        printf("\nHow much grams of fat is in your food >:((( : ");
        scanf("%d", &fat);

        if ((fat*9) > calories || fat <= 0)
            printf("\nbbg put the right number of grams of fat >:( : ");

    } while ((fat*9) > calories || fat <= 0);


    cal_from_fat = fat * 9;

    if (calories*0.3 > cal_from_fat)
        printf("\nYour food is low in fat >:(");
}