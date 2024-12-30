#include <stdio.h>

int main()
{
    int testint = 30000000000;
    printf("The value is :0 : %d", testint);
    // Output:
    // The value is : -64771072
    // This is because, the maximum value that can be stored in a int datatype is 2147483647
}