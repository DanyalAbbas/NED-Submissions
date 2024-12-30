#include <stdio.h>

int main()
{
    int vowels = 0, consonents = 0, i = 0;
    char name[20];

    printf("Enter any string ji : ");
    gets(name);


    while (name[i] != '\0')
    {
        if (name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u')
            vowels ++; 
        else if (name[i] == ' ')
            ;
        else
            consonents++;
        
        i++;
    }

    printf("vowels : %d\nconsonents : %d", vowels, consonents);
    
}