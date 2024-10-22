#include <stdio.h>
#include <string.h>

int main()
{
    char str[20], freq[26] = {0};
    int i = 0, j = 0, duplicate;


    printf("Enter any string ji : ");
    gets(str);
    StringHandler(str);

    while (str[i] != NULL)
    {
        int ch = str[i];
        freq[ch - 'a']++;
        i++;
        
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] > 0)
            printf("\n%c : %d", i + 'a',freq[i]);
    }
    

    
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