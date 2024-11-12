#include <stdio.h>

int main()
{
    int len;
    float arr[] = {1.5,3.5,6.4,10.0,2.0};
    float highest = 0, sec_highest = arr[0];
    float *ptr = arr;

    len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < len; i++)
    {
        if (*(ptr + i) > highest)
        {
            sec_highest = highest;
            highest = *(ptr + i);
        }
        
    }

    printf("%f", sec_highest);


}