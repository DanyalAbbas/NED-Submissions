#include <stdio.h>

typedef struct
{
    int real;
    int img;
}Complex;


int main()
{
    Complex n1, n2;
    n1.img = 5; n1.real = 2; // 2 + 5i
    n2.img = 6; n2.real = 4; // 4 + 6i

    Complex addition, multiply;
    addition.real = n1.real + n2.real;
    addition.img = n1.img + n2.img;

    // 8 + 12i + 20i - 30 = -22 + 32i
    multiply.real = (n1.real*n2.real - n1.img*n2.img);
    multiply.img = (n1.real*n2.img + n1.img*n2.real);

    printf("addition is %d + %di", addition.real, addition.img);
    printf("\nmultiplication is %d + %di", multiply.real, multiply.img);

}