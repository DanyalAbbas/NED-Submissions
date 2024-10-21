#include <stdio.h>

int main()
{
    char str[20];

    printf("Enter any string ji : ");
    gets(str);
    StringHandler(str);
    printf("%s", str);
    
}

void StringHandler(char *str)
{
    int i = 0, index = 0;
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
            {i++;continue;}
        else if (str[i] >=65 && str[i] <= 90)
            str[index] = str[i] + 32;
        
        else
            str[index] = str[i];
        index++;
        i++;

    }

    str[index] = NULL;

}