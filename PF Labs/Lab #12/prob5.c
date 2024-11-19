#include <stdio.h>
#include <stdbool.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void *BubbleSort(int *Arr, int ArrSize)
{
    bool swapped;
    for (int i = 0; i < ArrSize -1; i++)
    {
        swapped = false;
        for (int j = 0; j < ArrSize -i-1; j++)
        {
            if (Arr[j] > Arr[j+1])
            {
                swap(&Arr[j], &Arr[j+1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

int main()
{
    int list[5] = {23,341,12,5,3};
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(list+i));
    }
    printf("\n\n");
    BubbleSort(&list, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", *(list+i));
    }  
}