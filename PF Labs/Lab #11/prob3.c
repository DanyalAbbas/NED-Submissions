#include <stdio.h>

int main()
{
    int len, sum;
    int arr[] = {1,3,6,10,2};
    int *ptr = arr;

    len = sizeof(arr)/sizeof(arr[0]);

    for (int i = 0; i < len; i++)
    {
        sum += *(ptr + i);
    }

    printf("The sum is %d", sum);


}