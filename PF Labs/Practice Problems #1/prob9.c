#include <stdio.h>

int main()
{
    int x,y, i, powered_val;

    printf("NUMBER BATA DANJAR >:( : ");
    scanf("%d", &x);
    printf("hehe :3 power pls : ");
    scanf("%d", &y);

    powered_val = x;
    for (i=1;i<y;i++)
        powered_val *= x;

    printf("%d RAISED TO THE POWER %d IS %d >:3", x,y,powered_val);

}