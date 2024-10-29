#include <stdio.h>
#include <math.h>

int getData(void);
int volumeCal(int height, int area);


int main()
{
    printf("answer is %d", getData());
}

int getData(void)
{
    int h, a;
    printf("Enter the height : ");
    scanf("%d", &h);
    printf("Enter the area : ");
    scanf("%d", &a);

    return volumeCal(h,a);

}

int volumeCal(int height, int area)
{
    int volume = 0;

    volume = pow(area,2) * 1/3 *height;

    return volume;
}