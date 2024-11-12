#include <stdio.h>

int main()
{
    int arr[5] , len;
    len = sizeof(arr)/sizeof(arr[0]);
    int myAge = 34;
    int* ptr = &myAge;
    printf("The value of variable is %d", myAge);
    printf("\nThe address of variable is %p", ptr);
    *ptr += 5;
    printf("\n%d", myAge);
    printf("\n%d", len);

}
