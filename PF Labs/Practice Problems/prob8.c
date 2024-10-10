#include <stdio.h>

int main()
{
    float temperature, converted;
    char choice;

    printf("What temperature do want your temperature to be converted to?\n[f/F] : Fahrenheit\n[c/C] : Celsius : ");
    scanf("%c", &choice);

    printf("Temperature bata ab jaldi : ");
    scanf("%f", &temperature);

    if (choice == 'F' || choice == 'f')
        converted = (temperature * 9/5) + 32;
    else if (choice == 'C' || choice == 'c')
        converted = (temperature - 32) * 5/9;
    
    printf("THE CONVERTED TEMPERATURE IS %f BITCH", converted);
}