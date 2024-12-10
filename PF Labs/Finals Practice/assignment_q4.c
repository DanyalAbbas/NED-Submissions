#include <stdio.h>
#include <string.h>

int main()
{
    char str[50] = "ABC54301 TFTFTFTT TFTFTFFTTFT 11 F";
    char n[50], s[25], o[25];
    
    printf("hmm : ");
    gets(n);

    int i = 0;
    while (n[i] != ' ')
    {
        s[i] = n[i];
        i++;
    }
    i++;
    int count = 0;
    while (n[i] != '\0')
    {
        o[count] = n[i];
        i++;
        count++;
    }
    o[count] = '\0';

    printf("%s\n%s",s,o);

}