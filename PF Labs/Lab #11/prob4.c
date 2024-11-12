#include <stdio.h>

int main()
{
    int len;
    float arr[] = {3.14, 2.71, 9.81, 1.61, 4.67, 5.99, 0.57, 8.23, 7.12, 6.45, 
                   0.99, 3.33, 4.45, 6.28, 5.55, 7.89, 2.22, 8.91, 1.11, 0.76};
    float highest = arr[0], sec_highest = 0;
    float *ptr = arr;

    len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 1; i < len; i++)
    {
        if (*(ptr + i) > highest)
        {
            sec_highest = highest;
            highest = *(ptr + i);
        }
        if (*(ptr + i) > sec_highest && *(ptr + i) < highest)
            sec_highest = *(ptr + i);
    }

    printf("%.2f", sec_highest);


}